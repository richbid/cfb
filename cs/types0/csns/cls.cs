﻿/* This class framework is generated by Core Frame Builder. */
/* For more information, refer to http://www.one-lab.net/ */

/* Data Handling Class */
using System;
using System.Text;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.IO;

namespace csns {
public class cls : ICloneable {
	public override int GetHashCode() { return base.GetHashCode(); }

	public override bool Equals(object obj) { return this == (cls)obj; }

	public Boolean mPBool { get; set; }

	public void setPBool(Boolean aPBool) {
		mPBool = aPBool;
	}

	public Boolean getPBool() {
		 return mPBool;
	}

	public onelab.Bytes mPBytes { get; set; }

	public void setPBytes(onelab.Bytes aPBytes) {
		mPBytes = (onelab.Bytes)aPBytes.Clone();
	}

	public onelab.Bytes getPBytes() {
		 return mPBytes;
	}

	public DateTime mPDate { get; set; }

	public void setPDate(DateTime aPDate) {
		mPDate = aPDate;
	}

	public DateTime getPDate() {
		 return mPDate;
	}

	public DateTime mPDateTime { get; set; }

	public void setPDateTime(DateTime aPDateTime) {
		mPDateTime = aPDateTime;
	}

	public DateTime getPDateTime() {
		 return mPDateTime;
	}

	public Double mPDouble { get; set; }

	public void setPDouble(Double aPDouble) {
		mPDouble = aPDouble;
	}

	public Double getPDouble() {
		 return mPDouble;
	}

	public Single mPFloat { get; set; }

	public void setPFloat(Single aPFloat) {
		mPFloat = aPFloat;
	}

	public Single getPFloat() {
		 return mPFloat;
	}

	public Int32 mPInt32 { get; set; }

	public void setPInt32(Int32 aPInt32) {
		mPInt32 = aPInt32;
	}

	public Int32 getPInt32() {
		 return mPInt32;
	}

	public String mPText { get; set; }

	public void setPText(String aPText) {
		mPText = aPText;
	}

	public String getPText() {
		 return mPText;
	}

	public DateTime mPTime { get; set; }

	public void setPTime(DateTime aPTime) {
		mPTime = aPTime;
	}

	public DateTime getPTime() {
		 return mPTime;
	}

	public UInt32 mPUInt32 { get; set; }

	public void setPUInt32(UInt32 aPUInt32) {
		mPUInt32 = aPUInt32;
	}

	public UInt32 getPUInt32() {
		 return mPUInt32;
	}

	public ns.cls0 mPCls0 { get; set; }

	public void setPCls0(ns.cls0 aPCls0) {
		mPCls0 = (ns.cls0)aPCls0.Clone();
	}

	public ns.cls0 getPCls0() {
		 return mPCls0;
	}

	protected bool compare_to(cls aValue) {
		if (mPBool != aValue.mPBool) return false;
		if (mPBytes != aValue.mPBytes) return false;
		if (mPDate != aValue.mPDate) return false;
		if (mPDateTime != aValue.mPDateTime) return false;
		if (mPDouble != aValue.mPDouble) return false;
		if (mPFloat != aValue.mPFloat) return false;
		if (mPInt32 != aValue.mPInt32) return false;
		if (mPText != aValue.mPText) return false;
		if (mPTime != aValue.mPTime) return false;
		if (mPUInt32 != aValue.mPUInt32) return false;
		if (mPCls0 != aValue.mPCls0) return false;
		return true;
	}

	protected void clone_from(cls aValue) {
		mPBool = aValue.mPBool;
		mPBytes = (onelab.Bytes)aValue.mPBytes.Clone();
		mPDate = aValue.mPDate;
		mPDateTime = aValue.mPDateTime;
		mPDouble = aValue.mPDouble;
		mPFloat = aValue.mPFloat;
		mPInt32 = aValue.mPInt32;
		mPText = aValue.mPText;
		mPTime = aValue.mPTime;
		mPUInt32 = aValue.mPUInt32;
		mPCls0 = (ns.cls0)aValue.mPCls0.Clone();
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
		mPBytes = new onelab.Bytes();
		mPCls0 = new ns.cls0();
	}

	public cls(Boolean aPBool, onelab.Bytes aPBytes, DateTime aPDate, DateTime aPDateTime, Double aPDouble, Single aPFloat, Int32 aPInt32, String aPText, DateTime aPTime, UInt32 aPUInt32, ns.cls0 aPCls0) {
		mPBool = aPBool;
		mPBytes = (onelab.Bytes)aPBytes.Clone();
		mPDate = aPDate;
		mPDateTime = aPDateTime;
		mPDouble = aPDouble;
		mPFloat = aPFloat;
		mPInt32 = aPInt32;
		mPText = aPText;
		mPTime = aPTime;
		mPUInt32 = aPUInt32;
		mPCls0 = (ns.cls0)aPCls0.Clone();
	}

	public void _invoke_(String entry, String input, ref String output) {
		if (false){}
	}
	public virtual int field_count() {
		return 11;
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
		else if (key == "PBool") {
			Boolean v; if (!Boolean.TryParse(value.ToString(), out v)) return 0;
			if (_set_value)
				mPBool = v;
			result = 1;
		}
		else if (key == "PBytes") {
			onelab.Bytes v = new onelab.Bytes(); if (v.fromString(value.ToString()) != 1) return 0;
			if (_set_value)
				mPBytes = (onelab.Bytes)v.Clone();
			result = 1;
		}
		else if (key == "PDate") {
			DateTime v; if (!DateTime.TryParse(value.ToString(), out v)) return 0;
			if (_set_value)
				mPDate = v;
			result = 1;
		}
		else if (key == "PDateTime") {
			DateTime v; if (!DateTime.TryParse(value.ToString(), out v)) return 0;
			if (_set_value)
				mPDateTime = v;
			result = 1;
		}
		else if (key == "PDouble") {
			Double v; if (!Double.TryParse(value.ToString(), out v)) return 0;
			if (_set_value)
				mPDouble = v;
			result = 1;
		}
		else if (key == "PFloat") {
			Single v; if (!Single.TryParse(value.ToString(), out v)) return 0;
			if (_set_value)
				mPFloat = v;
			result = 1;
		}
		else if (key == "PInt32") {
			Int32 v; if (!Int32.TryParse(value.ToString(), out v)) return 0;
			if (_set_value)
				mPInt32 = v;
			result = 1;
		}
		else if (key == "PText") {
			String v = value.ToString();
			if (_set_value)
				mPText = v;
			result = 1;
		}
		else if (key == "PTime") {
			DateTime v; if (!DateTime.TryParse(value.ToString(), out v)) return 0;
			if (_set_value)
				mPTime = v;
			result = 1;
		}
		else if (key == "PUInt32") {
			UInt32 v; if (!UInt32.TryParse(value.ToString(), out v)) return 0;
			if (_set_value)
				mPUInt32 = v;
			result = 1;
		}
		else if (key == "PCls0") {
			if (_set_value)
				if (mPCls0 != null) { return mPCls0.from_json(value.ToString()); }
			result = 1;
		}
		return result;
	}

	private static readonly string[] field_keys = new string[] { "PBool", "PBytes", "PDate", "PDateTime", "PDouble", "PFloat", "PInt32", "PText", "PTime", "PUInt32", "PCls0",  };
	private int input_field(int index, object value, bool _set_value) {
		if (index < 0 || index > (field_count()-1) || value == null) return 0;
		return input_field(field_keys[index], value, _set_value);
	}

	public virtual int to_json(ref String output) {
		String jsonPCls0 = "";
		if (mPCls0 != null)
			if (mPCls0.to_json(ref jsonPCls0) != 1) return 0;
		output = "{" + "\"PBool\"" + ":" + "\"" + mPBool.ToString() + "\"" + "," + "\"PBytes\"" + ":" + "\"" + (mPBytes == null ? "" : mPBytes.toString()) + "\"" + "," + "\"PDate\"" + ":" + "\"" + (mPDate == null ? "" : mPDate.ToString("yyyy/MM/dd")) + "\"" + "," + "\"PDateTime\"" + ":" + "\"" + (mPDateTime == null ? "" : mPDateTime.ToString("yyyy/MM/dd HH:mm:ss.fff")) + "\"" + "," + "\"PDouble\"" + ":" + "\"" + mPDouble.ToString() + "\"" + "," + "\"PFloat\"" + ":" + "\"" + mPFloat.ToString() + "\"" + "," + "\"PInt32\"" + ":" + "\"" + mPInt32.ToString() + "\"" + "," + "\"PText\"" + ":" + "\"" + (mPText == null ? "" : mPText) + "\"" + "," + "\"PTime\"" + ":" + "\"" + (mPTime == null ? "" : mPTime.ToString("HH:mm:ss.fff")) + "\"" + "," + "\"PUInt32\"" + ":" + "\"" + mPUInt32.ToString() + "\"" + "," + "\"PCls0\"" + ":" + jsonPCls0 + "}";
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

}//class clsList
}//namespace csns