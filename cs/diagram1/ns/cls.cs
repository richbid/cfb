﻿/* This class framework is generated by Core Frame Builder. */
/* For more information, refer to http://www.one-lab.net/ */

/* Data Handling Class */
using System;
using System.Text;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.IO;

namespace ns {
public class cls : ICloneable {
	public override int GetHashCode() { return base.GetHashCode(); }

	public override bool Equals(object obj) { return this == (cls)obj; }

	public String mPText { get; set; }

	public void setPText(String aPText) {
		mPText = aPText;
	}

	public String getPText() {
		 return mPText;
	}

	protected bool compare_to(cls aValue) {
		if (mPText != aValue.mPText) return false;
		return true;
	}

	protected void clone_from(cls aValue) {
		mPText = aValue.mPText;
	}

	public object Clone() {
		cls oValue = new cls();
		oValue.clone_from(this);
		return oValue;
	}

	public static bool operator == (cls a0, cls a1) { object o1 = (object)a0; object o2 = (object)a1; if (o1 == null && o2 == null) return true; return (o1 == null || o2 == null) ? false : a0.compare_to(a1); }

	public static bool operator != (cls a0, cls a1) { object o1 = (object)a0; object o2 = (object)a1; if (o1 == null && o2 == null) return false; return (o1 == null || o2 == null) ? true : !a0.compare_to(a1); }

	public cls(cls aValue) { clone_from(aValue); }

	public cls() {
	}

	public cls(String aPText) {
		mPText = aPText;
	}

	public virtual int trigger(ref Int32 aReturn) {
	//function-begin : public virtual int trigger(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.trigger()", "[enter]");
		f0(ref aReturn);
		f1(ref aReturn);
		f2(ref aReturn);
		return 0;
	//function-end
	}

	public virtual void trigger2() {
	//function-begin : public virtual void trigger2() @ ns.cls
		onelab.log.info("ns.cls.trigger2()", "[enter]");
	//function-end
	}

	private int f0(ref Int32 aReturn) {
	//function-begin : private int f0(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.f0()", "[enter]");
		return 0;
	//function-end
	}

	private int f1(ref Int32 aReturn) {
	//function-begin : private int f1(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.f1()", "[enter]");
		if (ifx0(ref aReturn) != 0) { tfx(ref aReturn); } else { ffx(ref aReturn); }
		return 0;
	//function-end
	}

	private int f2(ref Int32 aReturn) {
	//function-begin : private int f2(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.f2()", "[enter]");
		if (ifx1(ref aReturn) != 0) { tf0(ref aReturn); tf1(ref aReturn); tf2(ref aReturn); } else { f0(ref aReturn); f1(ref aReturn); f2(ref aReturn); }
		return 0;
	//function-end
	}

	private int ifx0(ref Int32 aReturn) {
	//function-begin : private int ifx0(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.ifx0()", "[enter]");
		return 0;
	//function-end
	}

	private int tfx(ref Int32 aReturn) {
	//function-begin : private int tfx(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.tfx()", "[enter]");
		switch (sfx0(ref aReturn)) {
		case 0: cfx(ref aReturn); break;
		case 1: return -1;
		case 2: return -2;
		default:break;
		}
		return 0;
	//function-end
	}

	private int ffx(ref Int32 aReturn) {
	//function-begin : private int ffx(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.ffx()", "[enter]");
		switch (sfx1(ref aReturn)) {
		case 0: cf0(ref aReturn); break;
		case 1: cf1(ref aReturn); break;
		case 2: cf2(ref aReturn); break;
		default:break;
		}
		return 0;
	//function-end
	}

	private int ifx1(ref Int32 aReturn) {
	//function-begin : private int ifx1(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.ifx1()", "[enter]");
		return 0;
	//function-end
	}

	private int tf0(ref Int32 aReturn) {
	//function-begin : private int tf0(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.tf0()", "[enter]");
		return 0;
	//function-end
	}

	private int tf1(ref Int32 aReturn) {
	//function-begin : private int tf1(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.tf1()", "[enter]");
		return 0;
	//function-end
	}

	private int tf2(ref Int32 aReturn) {
	//function-begin : private int tf2(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.tf2()", "[enter]");
		return 0;
	//function-end
	}

	private int sfx0(ref Int32 aReturn) {
	//function-begin : private int sfx0(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.sfx0()", "[enter]");
		return 0;
	//function-end
	}

	private int cfx(ref Int32 aReturn) {
	//function-begin : private int cfx(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.cfx()", "[enter]");
		return 0;
	//function-end
	}

	private int sfx1(ref Int32 aReturn) {
	//function-begin : private int sfx1(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.sfx1()", "[enter]");
		return 0;
	//function-end
	}

	private int cf0(ref Int32 aReturn) {
	//function-begin : private int cf0(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.cf0()", "[enter]");
		while (wfx0(ref aReturn) != 0) { lfx(ref aReturn); }
		return 0;
	//function-end
	}

	private int cf1(ref Int32 aReturn) {
	//function-begin : private int cf1(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.cf1()", "[enter]");
		while (wfx1(ref aReturn) != 0) { lf0(ref aReturn); lf1(ref aReturn); lf2(ref aReturn); }
		return 0;
	//function-end
	}

	private int cf2(ref Int32 aReturn) {
	//function-begin : private int cf2(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.cf2()", "[enter]");
		return 0;
	//function-end
	}

	private int wfx0(ref Int32 aReturn) {
	//function-begin : private int wfx0(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.wfx0()", "[enter]");
		return 0;
	//function-end
	}

	private int lfx(ref Int32 aReturn) {
	//function-begin : private int lfx(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.lfx()", "[enter]");
		return 0;
	//function-end
	}

	private int wfx1(ref Int32 aReturn) {
	//function-begin : private int wfx1(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.wfx1()", "[enter]");
		return 0;
	//function-end
	}

	private int lf0(ref Int32 aReturn) {
	//function-begin : private int lf0(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.lf0()", "[enter]");
		return 0;
	//function-end
	}

	private int lf1(ref Int32 aReturn) {
	//function-begin : private int lf1(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.lf1()", "[enter]");
		return 0;
	//function-end
	}

	private int lf2(ref Int32 aReturn) {
	//function-begin : private int lf2(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.lf2()", "[enter]");
		if (if10(ref aReturn) != 0) { return -1; } else { return -2; }
	//function-end
	}

	private int if9(ref Int32 aReturn) {
	//function-begin : private int if9(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.if9()", "[enter]");
		return 0;
	//function-end
	}

	private int tf10(ref Int32 aReturn) {
	//function-begin : private int tf10(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.tf10()", "[enter]");
		while (lf10(ref aReturn) != 0);
		return 0;
	//function-end
	}

	private int if10(ref Int32 aReturn) {
	//function-begin : private int if10(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.if10()", "[enter]");
		return 0;
	//function-end
	}

	private int lf10(ref Int32 aReturn) {
	//function-begin : private int lf10(ref Int32 aReturn) @ ns.cls
		onelab.log.info("ns.cls.lf10()", "[enter]");
		return 0;
	//function-end
	}

	public void _invoke_(String entry, String input, ref String output) {
		if (false){}
		else if (entry == "trigger"){
		}
		else if (entry == "trigger2"){
		}
	}
	public virtual int field_count() {
		return 1;
	}

	private int validate_field(String key, object value) {
		return input_field(key, value, false);
	}

	private int validate_field(int index, object value) {
		return input_field(index, value, false);
	}

	public virtual int input_field(String key, object value, bool _set_value) {
		int result = 0;
		if (string.IsNullOrWhiteSpace(key) || value == null) return 0;
		else if (key == "PText") {
			String v = value.ToString();
			if (_set_value)
				mPText = v;
			result = 1;
		}
		return result;
	}

	private static readonly string[] field_keys = new string[] { "PText",  };
	private int input_field(int index, object value, bool _set_value) {
		if (index < 0 || index > (field_count()-1) || value == null) return 0;
		return input_field(field_keys[index], value, _set_value);
	}

	public virtual int to_json(ref String output) {
		output = "{" + "\"PText\"" + ":" + "\"" + (mPText == null ? "" : mPText) + "\"" + "}";
		return 1;
	}

	public int from_json(System.Collections.Hashtable table) {
		SortedList<string, string> list = new SortedList<string, string>();
		foreach (string key in table.Keys) {
			object oValue = table[key];
			if (oValue != null) {
				string value = oValue.ToString();
				if (validate_field(key, value) == 0)
					return 0;
				list.Add(key, value);
			}
		}
		if (list.Count != field_count()) return 0;
		foreach (string k in list.Keys)
			input_field(k, list[k], true);
		return 1;
	}

	public int from_json(String input) {
		if (string.IsNullOrWhiteSpace(input)) return 0;
		try {
			object obj = json.Parser.Decode(input);
			json.Parser.ParseResult result = (json.Parser.ParseResult)obj;
			return from_json((System.Collections.Hashtable)result.JSONObject);
		}
		catch { return 0; }
	}

	public virtual int to_xml(ref String output, String rowTag) {
		if (string.IsNullOrWhiteSpace(rowTag)) return 0;
		output = "<" + rowTag + ">" + "<PText>" + mPText.ToString().Replace("<", "&lt;").Replace("<", "&gt;") + "</PText>" + "</" + rowTag + ">";
		return 1;
	}

	public int from_xml(String input, String rowTag) {
		if (string.IsNullOrWhiteSpace(input) || string.IsNullOrWhiteSpace(rowTag)) return 0;
		try {
			SortedList<string, string> list = new SortedList<string, string>();
			System.Xml.XmlDocument doc = new System.Xml.XmlDocument();
			doc.LoadXml(input);
			if (doc.DocumentElement.Name != rowTag) return 0;
			foreach(System.Xml.XmlNode node in doc.DocumentElement.ChildNodes) {
				string key = node.Name;
				string value = node.InnerText;
				if (validate_field(key, value) == 0) return 0;
				list.Add(key, value);
			}
			if (list.Count != field_count()) return 0;
			foreach (string k in list.Keys)
				input_field(k, list[k], true);
		}
		catch { return 0; }
		return 1;
	}

	public virtual int to_sv(ref String output, String spliter) {
		if (string.IsNullOrWhiteSpace(spliter)) return 0;
		List<String> list = new List<String>();
		list.Add((mPText == null ? "" : mPText));
	
		output = String.Join(spliter, list.ToArray());
		return 1;
	}

	public int from_sv(String input, String spliter) {
		if (string.IsNullOrWhiteSpace(input) || string.IsNullOrWhiteSpace(spliter)) return 0;
		string[] list = input.Split(new string[] { spliter }, StringSplitOptions.RemoveEmptyEntries);
		if (list.Length != field_count()) return 0;
		int index = 0;
		foreach(string item in list)
			if (validate_field(index++, item) == 0)
				return 0;
		index = 0;
		foreach(string item in list)
			input_field(index++, item, true);
		return 1;
	}

}//class cls
public class clsList {
	public Object Clone() {
		clsList obj = new clsList();
		obj.Items.AddRange(Items);
		return obj;
	}
	public List<cls> Items = new List<cls>();

	public override int GetHashCode() { return base.GetHashCode(); }

	public override bool Equals(object obj) { return this == (clsList)obj; }

	protected bool compare_to(clsList aValue) {
		if (aValue == null) return false;
		if (Items.Count != aValue.Items.Count) return false;
		for (int n = 0; n < Items.Count; n++) if (Items[n] != aValue.Items[n]) return false;
		return true;
	}

	public static bool operator == (clsList a0, clsList a1) { object o1 = (object)a0; object o2 = (object)a1; if (o1 == null && o2 == null) return true; return (o1 == null || o2 == null) ? false : a0.compare_to(a1); }

	public static bool operator != (clsList a0, clsList a1) { object o1 = (object)a0; object o2 = (object)a1; if (o1 == null && o2 == null) return false; return (o1 == null || o2 == null) ? true : !a0.compare_to(a1); }

	public int to_json(ref String output, String tag = "cls") {
		if (string.IsNullOrWhiteSpace(tag)) return 0;
		List<string> list = new List<string>();
		string text = "";
		foreach(cls item in Items) {
			item.to_json(ref text);
			list.Add(text);
		}
		output = "{\"" + tag + "\":[" + string.Join(",", list.ToArray()) + "]}";
		return 1;
	}

	public int from_json(String input, String tag = "cls") {
		if (string.IsNullOrWhiteSpace(input) || string.IsNullOrWhiteSpace(tag)) return 0;
		try {
			List<cls> newList = new List<cls>();
			object obj = json.Parser.Decode(input);
			json.Parser.ParseResult result = (json.Parser.ParseResult)obj;
			System.Collections.Hashtable table = (System.Collections.Hashtable)result.JSONObject;
			System.Collections.ArrayList list = (System.Collections.ArrayList)table[tag];
			foreach(object value in list) {
				cls cls = new cls();
				if (cls.from_json((System.Collections.Hashtable)value) == 0) return 0;
				newList.Add(cls);
			}
			Items.Clear();
			Items = newList;
		}
		catch { return 0; }
		return 1;
	}

	public int to_xml(ref String output, String rowTag, String tableTag) {
		if (string.IsNullOrWhiteSpace(rowTag) ||string.IsNullOrWhiteSpace(tableTag)) return 0;
		List<string> list = new List<string>();
		string text = "";
		foreach(cls item in Items) {
			item.to_xml(ref text, rowTag);
			list.Add(text);
		}
		output = "<" + tableTag + ">" + string.Join("", list.ToArray()) + "</" + tableTag + ">";
		return 1;
	}

	public int from_xml(String input, String rowTag, String tableTag) {
		if (string.IsNullOrWhiteSpace(input) || string.IsNullOrWhiteSpace(rowTag) || string.IsNullOrWhiteSpace(tableTag)) return 0;
		try {
			List<cls> newList = new List<cls>();
			System.Xml.XmlDocument doc = new System.Xml.XmlDocument();
			doc.LoadXml(input);
			if (doc.DocumentElement.Name != tableTag) return 0;
			foreach (System.Xml.XmlNode node in doc.DocumentElement.ChildNodes) {
				cls cls = new cls();
				if (cls.from_xml(node.OuterXml, rowTag) == 0) return 0;
				newList.Add(cls);
			}
			Items.Clear();
			Items = newList;
		}
		catch { return 0; }
		return 1;
	}

	public int to_sv(ref String output, String spliter) {
		if (string.IsNullOrWhiteSpace(spliter)) return 0;
		List<string> list = new List<string>();
		string text = "";
		foreach(cls item in Items) {
			item.to_sv(ref text, spliter);
			list.Add(text);
		}
		output = string.Join("\n", list.ToArray());
		return 1;
	}

	public int from_sv(String input, String spliter) {
		if (string.IsNullOrWhiteSpace(input) || string.IsNullOrWhiteSpace(spliter)) return 0;
		string[] list = input.Split(new string[] { "\n" }, StringSplitOptions.RemoveEmptyEntries);
		if (list.Length == 0) return 0;
		List<cls> newList = new List<cls>();
		foreach(string item in list) {
			cls cls = new cls();
			if (cls.from_sv(item, spliter) == 0) return 0;
			newList.Add(cls);
		}
		if (newList.Count == list.Length) {
			Items.Clear();
			Items = newList;
			return 1;
		}
		return 0;
	}
}//class clsList
}//namespace ns