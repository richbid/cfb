namespace json
{
	public class Parser
	{
		public class ParseResult
		{
			public object JSONObject
			{
				get;
				set;
			}
			public Parser.ParseErrors JSONErrors
			{
				get;
				set;
			}
		}
		public class ParseErrors
		{
			public int iErrorIndex
			{
				get;
				set;
			}
			public string sWarningText
			{
				get;
				set;
			}
		}
		internal enum JSONTokens : byte
		{
			NONE,
			CURLY_OPEN,
			CURLY_CLOSE,
			SQUARED_OPEN,
			SQUARED_CLOSE,
			COLON,
			COMMA,
			STRING,
			NUMBER,
			TRUE,
			FALSE,
			NULL,
			IMPLIED_IDENTIFIER_NAME
		}
		private const int BUILDER_DEFAULT_CAPACITY = 2048;
		public static object Decode(string sJSON)
		{
			Parser.ParseErrors jSONErrors;
			return new Parser.ParseResult
			{
				JSONObject = Parser.Decode(sJSON, out jSONErrors),
				JSONErrors = jSONErrors
			};
		}
		public static object Decode(string sJSON, out Parser.ParseErrors oErrors)
		{
			oErrors = new Parser.ParseErrors
			{
				iErrorIndex = -1,
				sWarningText = string.Empty
			};
			if (!string.IsNullOrEmpty(sJSON))
			{
				char[] json = sJSON.ToCharArray();
				int num = 0;
				bool flag = true;
				return Parser.ParseValue(json, ref num, ref flag, ref oErrors);
			}
			return null;
		}
		private static System.Collections.Hashtable ParseObject(char[] json, ref int index, ref Parser.ParseErrors oErrors)
		{
			System.Collections.Hashtable hashtable = new System.Collections.Hashtable();
			Parser.NextToken(json, ref index);
			bool flag = false;
			while (!flag)
			{
				Parser.JSONTokens jSONTokens = Parser.LookAhead(json, index);
				if (jSONTokens == Parser.JSONTokens.NONE)
				{
					return null;
				}
				if (jSONTokens == Parser.JSONTokens.COMMA)
				{
					Parser.NextToken(json, ref index);
				}
				else
				{
					if (jSONTokens == Parser.JSONTokens.CURLY_CLOSE)
					{
						Parser.NextToken(json, ref index);
						return hashtable;
					}
					string text;
					if (jSONTokens == Parser.JSONTokens.IMPLIED_IDENTIFIER_NAME)
					{
						text = Parser.ParseUnquotedIdentifier(json, ref index, ref oErrors);
						if (text == null)
						{
							if (oErrors.iErrorIndex < 0)
							{
								oErrors.iErrorIndex = index;
							}
							return null;
						}
					}
					else
					{
						text = Parser.ParseString(json, ref index);
						if (text == null)
						{
							if (oErrors.iErrorIndex < 0)
							{
								oErrors.iErrorIndex = index;
							}
							return null;
						}
					}
					jSONTokens = Parser.NextToken(json, ref index);
					if (jSONTokens != Parser.JSONTokens.COLON)
					{
						if (oErrors.iErrorIndex < 0)
						{
							oErrors.iErrorIndex = index;
						}
						return null;
					}
					bool flag2 = true;
					object value = Parser.ParseValue(json, ref index, ref flag2, ref oErrors);
					if (!flag2)
					{
						oErrors.iErrorIndex = index;
						return null;
					}
					hashtable[text] = value;
				}
			}
			return hashtable;
		}
		private static System.Collections.ArrayList ParseArray(char[] json, ref int index, ref Parser.ParseErrors oErrors)
		{
			System.Collections.ArrayList arrayList = new System.Collections.ArrayList();
			Parser.NextToken(json, ref index);
			bool flag = false;
			while (!flag)
			{
				Parser.JSONTokens jSONTokens = Parser.LookAhead(json, index);
				if (jSONTokens == Parser.JSONTokens.NONE)
				{
					if (oErrors.iErrorIndex < 0)
					{
						oErrors.iErrorIndex = index;
					}
					return null;
				}
				if (jSONTokens == Parser.JSONTokens.COMMA)
				{
					Parser.NextToken(json, ref index);
				}
				else
				{
					if (jSONTokens == Parser.JSONTokens.SQUARED_CLOSE)
					{
						Parser.NextToken(json, ref index);
						break;
					}
					bool flag2 = true;
					object value = Parser.ParseValue(json, ref index, ref flag2, ref oErrors);
					if (!flag2)
					{
						if (oErrors.iErrorIndex < 0)
						{
							oErrors.iErrorIndex = index;
						}
						return null;
					}
					arrayList.Add(value);
				}
			}
			return arrayList;
		}
		private static object ParseValue(char[] json, ref int index, ref bool success, ref Parser.ParseErrors oErrors)
		{
			switch (Parser.LookAhead(json, index))
			{
			case Parser.JSONTokens.CURLY_OPEN:
				return Parser.ParseObject(json, ref index, ref oErrors);
			case Parser.JSONTokens.SQUARED_OPEN:
				return Parser.ParseArray(json, ref index, ref oErrors);
			case Parser.JSONTokens.STRING:
				return Parser.ParseString(json, ref index);
			case Parser.JSONTokens.NUMBER:
				return Parser.ParseNumber(json, ref index);
			case Parser.JSONTokens.TRUE:
				Parser.NextToken(json, ref index);
				return true;
			case Parser.JSONTokens.FALSE:
				Parser.NextToken(json, ref index);
				return false;
			case Parser.JSONTokens.NULL:
				Parser.NextToken(json, ref index);
				return null;
			case Parser.JSONTokens.IMPLIED_IDENTIFIER_NAME:
				return Parser.ParseUnquotedIdentifier(json, ref index, ref oErrors);
			}
			success = false;
			return null;
		}
		private static string ParseUnquotedIdentifier(char[] json, ref int index, ref Parser.ParseErrors oErrors)
		{
			Parser.EatWhitespace(json, ref index);
			int num = index;
			System.Text.StringBuilder stringBuilder = new System.Text.StringBuilder(2048);
			bool flag = false;
			while (!flag && index != json.Length)
			{
				char c = json[index];
				if (!Parser.IsValidIdentifierChar(c))
				{
					if (stringBuilder.Length < 1)
					{
						return null;
					}
					flag = true;
					break;
				}
				else
				{
					stringBuilder.Append(c);
					index++;
				}
			}
			if (!flag)
			{
				return null;
			}
			oErrors.sWarningText = string.Format("{0}Illegal/Unquoted identifier '{1}' at position {2}.\n", oErrors.sWarningText, stringBuilder.ToString(), num);
			return stringBuilder.ToString();
		}
		private static string ParseString(char[] json, ref int index)
		{
			System.Text.StringBuilder stringBuilder = new System.Text.StringBuilder(2048);
			Parser.EatWhitespace(json, ref index);
			index++;
			bool flag = false;
			while (!flag && index != json.Length)
			{
				char c = json[index++];
				if (c == '"')
				{
					flag = true;
					break;
				}
				if (c == '\\')
				{
					if (index == json.Length)
					{
						break;
					}
					c = json[index++];
					if (c == '"')
					{
						stringBuilder.Append('"');
					}
					else
					{
						if (c == '\\')
						{
							stringBuilder.Append('\\');
						}
						else
						{
							if (c == '/')
							{
								stringBuilder.Append('/');
							}
							else
							{
								if (c == 'b')
								{
									stringBuilder.Append('\b');
								}
								else
								{
									if (c == 'f')
									{
										stringBuilder.Append('\f');
									}
									else
									{
										if (c == 'n')
										{
											stringBuilder.Append('\n');
										}
										else
										{
											if (c == 'r')
											{
												stringBuilder.Append('\r');
											}
											else
											{
												if (c == 't')
												{
													stringBuilder.Append('\t');
												}
												else
												{
													if (c == 'u')
													{
														int num = json.Length - index;
														if (num < 4)
														{
															break;
														}
														uint utf = uint.Parse(new string(json, index, 4), System.Globalization.NumberStyles.HexNumber);
														string value;
														try
														{
															value = char.ConvertFromUtf32((int)utf);
														}
														catch (System.Exception)
														{
															value = "�";
														}
														stringBuilder.Append(value);
														index += 4;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				else
				{
					stringBuilder.Append(c);
				}
			}
			if (!flag)
			{
				return null;
			}
			return stringBuilder.ToString();
		}
		private static double ParseNumber(char[] json, ref int index)
		{
			Parser.EatWhitespace(json, ref index);
			int lastIndexOfNumber = Parser.GetLastIndexOfNumber(json, index);
			int length = lastIndexOfNumber - index + 1;
			string s = new string(json, index, length);
			index = lastIndexOfNumber + 1;
			return double.Parse(s, System.Globalization.CultureInfo.InvariantCulture);
		}
		private static int GetLastIndexOfNumber(char[] json, int index)
		{
			int num = index;
			while (num < json.Length && "0123456789+-.eE".IndexOf(json[num]) != -1)
			{
				num++;
			}
			return num - 1;
		}
		private static void EatWhitespace(char[] json, ref int index)
		{
			while (index < json.Length)
			{
				if (" \t\n\r".IndexOf(json[index]) == -1)
				{
					return;
				}
				index++;
			}
		}
		private static Parser.JSONTokens LookAhead(char[] json, int index)
		{
			int num = index;
			return Parser.NextToken(json, ref num);
		}
		private static Parser.JSONTokens NextToken(char[] json, ref int index)
		{
			Parser.EatWhitespace(json, ref index);
			if (index == json.Length)
			{
				return Parser.JSONTokens.NONE;
			}
			char c = json[index];
			index++;
			char c2 = c;
			switch (c2)
			{
			case '"':
				return Parser.JSONTokens.STRING;
			case '#':
			case '$':
			case '%':
			case '&':
			case '\'':
			case '(':
			case ')':
			case '*':
			case '+':
			case '.':
			case '/':
				break;
			case ',':
				return Parser.JSONTokens.COMMA;
			case '-':
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				return Parser.JSONTokens.NUMBER;
			case ':':
				return Parser.JSONTokens.COLON;
			default:
				switch (c2)
				{
				case '[':
					return Parser.JSONTokens.SQUARED_OPEN;
				case '\\':
					break;
				case ']':
					return Parser.JSONTokens.SQUARED_CLOSE;
				default:
					switch (c2)
					{
					case '{':
						return Parser.JSONTokens.CURLY_OPEN;
					case '}':
						return Parser.JSONTokens.CURLY_CLOSE;
					}
					break;
				}
				break;
			}
			index--;
			int num = json.Length - index;
			if (num >= 5 && json[index] == 'f' && json[index + 1] == 'a' && json[index + 2] == 'l' && json[index + 3] == 's' && json[index + 4] == 'e')
			{
				index += 5;
				return Parser.JSONTokens.FALSE;
			}
			if (num >= 4 && json[index] == 't' && json[index + 1] == 'r' && json[index + 2] == 'u' && json[index + 3] == 'e')
			{
				index += 4;
				return Parser.JSONTokens.TRUE;
			}
			if (num >= 4 && json[index] == 'n' && json[index + 1] == 'u' && json[index + 2] == 'l' && json[index + 3] == 'l')
			{
				index += 4;
				return Parser.JSONTokens.NULL;
			}
			if (Parser.IsValidIdentifierStart(json[index]))
			{
				return Parser.JSONTokens.IMPLIED_IDENTIFIER_NAME;
			}
			return Parser.JSONTokens.NONE;
		}
		private static bool IsValidIdentifierStart(char c)
		{
			return c == '_' || c == '$' || c == '\'' || char.IsLetter(c);
		}
		private static bool IsValidIdentifierChar(char c)
		{
			return c == '-' || c == '_' || c == '$' || char.IsLetterOrDigit(c) || c == '\'';
		}
		public static string JsonEncode(object json)
		{
			System.Text.StringBuilder stringBuilder = new System.Text.StringBuilder(2048);
			if (!Parser.SerializeValue(json, stringBuilder))
			{
				return null;
			}
			return stringBuilder.ToString();
		}
		private static bool SerializeObject(System.Collections.IDictionary anObject, System.Text.StringBuilder builder)
		{
			builder.Append("{");
			System.Collections.IDictionaryEnumerator enumerator = anObject.GetEnumerator();
			bool flag = true;
			while (enumerator.MoveNext())
			{
				string aString = enumerator.Key.ToString();
				object value = enumerator.Value;
				if (!flag)
				{
					builder.Append(", ");
				}
				Parser.SerializeString(aString, builder);
				builder.Append(":");
				if (!Parser.SerializeValue(value, builder))
				{
					return false;
				}
				flag = false;
			}
			builder.Append("}");
			return true;
		}
		private static bool SerializeArray(System.Collections.IList anArray, System.Text.StringBuilder builder)
		{
			builder.Append("[");
			bool flag = true;
			for (int i = 0; i < anArray.Count; i++)
			{
				object value = anArray[i];
				if (!flag)
				{
					builder.Append(", ");
				}
				if (!Parser.SerializeValue(value, builder))
				{
					return false;
				}
				flag = false;
			}
			builder.Append("]");
			return true;
		}
		private static bool SerializeValue(object value, System.Text.StringBuilder builder)
		{
			if (value == null)
			{
				builder.Append("null");
			}
			else
			{
				if (value is string)
				{
					Parser.SerializeString((string)value, builder);
				}
				else
				{
					if (value is System.Collections.Hashtable)
					{
						Parser.SerializeObject((System.Collections.Hashtable)value, builder);
					}
					else
					{
						if (value is System.Collections.ArrayList)
						{
							Parser.SerializeArray((System.Collections.ArrayList)value, builder);
						}
						else
						{
							if (Parser.IsNumeric(value))
							{
								Parser.SerializeNumber(System.Convert.ToDouble(value), builder);
							}
							else
							{
								if (value is bool && (bool)value)
								{
									builder.Append("true");
								}
								else
								{
									if (!(value is bool) || (bool)value)
									{
										return false;
									}
									builder.Append("false");
								}
							}
						}
					}
				}
			}
			return true;
		}
		private static void SerializeString(string aString, System.Text.StringBuilder builder)
		{
			builder.Append("\"");
			char[] array = aString.ToCharArray();
			int i = 0;
			while (i < array.Length)
			{
				char c = array[i];
				switch (c)
				{
				case '\b':
					builder.Append("\\b");
					break;
				case '\t':
					builder.Append("\\t");
					break;
				case '\n':
					builder.Append("\\n");
					break;
				case '\v':
					goto IL_B6;
				case '\f':
					builder.Append("\\f");
					break;
				case '\r':
					builder.Append("\\r");
					break;
				default:
					if (c != '"')
					{
						if (c != '\\')
						{
							goto IL_B6;
						}
						builder.Append("\\\\");
					}
					else
					{
						builder.Append("\\\"");
					}
					break;
				}
				IL_FA:
				i++;
				continue;
				IL_B6:
				char value = array[i];
				int num = System.Convert.ToInt32(value);
				if (num >= 32 && num <= 126)
				{
					builder.Append(value);
					goto IL_FA;
				}
				builder.Append("\\u" + num.ToString("x").PadLeft(4, '0'));
				goto IL_FA;
			}
			builder.Append("\"");
		}
		private static void SerializeNumber(double number, System.Text.StringBuilder builder)
		{
			builder.Append(System.Convert.ToString(number, System.Globalization.CultureInfo.InvariantCulture));
		}
		private static bool IsNumeric(object o)
		{
			try
			{
				double.Parse(o.ToString());
			}
			catch (System.Exception)
			{
				return false;
			}
			return true;
		}
	}
}
