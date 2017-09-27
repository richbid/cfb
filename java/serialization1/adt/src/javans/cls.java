/* This class framework is generated by Core Frame Builder. */
/* For more information, refer to http://www.one-lab.net/ */

/* Data Handling Class */
package javans;
 
import java.lang.*;
import java.text.*;
import java.util.*;
import net.onelab.*;
import net.onelab.JSONException;
import net.onelab.JSONObject;

public class cls implements Cloneable {
protected void clone_from(cls aValue) {
	setPBool(aValue.getPBool());
	setPBytes((net.onelab.Bytes)aValue.getPBytes().clone());
	setPDate(aValue.getPDate());
	setPDateTime(aValue.getPDateTime());
	setPDouble(aValue.getPDouble());
	setPFloat(aValue.getPFloat());
	setPInt32(aValue.getPInt32());
	setPText(aValue.getPText());
	setPTime(aValue.getPTime());
	setPUInt32(aValue.getPUInt32());
}

public Object clone() {
	cls oValue = new cls();
	oValue.clone_from(this);
	return oValue;
}

public boolean equals(Object oValue) {
	if (oValue == null) return false;
	if (this == oValue) return true;
	cls aValue = (cls)oValue;
	if (!mPBool.equals(aValue.getPBool())) return false;
	if (!mPBytes.equals(aValue.getPBytes())) return false;
	if (!mPDate.equals(aValue.getPDate())) return false;
	if (!mPDateTime.equals(aValue.getPDateTime())) return false;
	if (!mPDouble.equals(aValue.getPDouble())) return false;
	if (!mPFloat.equals(aValue.getPFloat())) return false;
	if (!mPInt32.equals(aValue.getPInt32())) return false;
	if (!mPText.equals(aValue.getPText())) return false;
	if (!mPTime.equals(aValue.getPTime())) return false;
	if (!mPUInt32.equals(aValue.getPUInt32())) return false;
	return true;
}
 
private Boolean mPBool = new Boolean(false);

public void setPBool(Boolean aPBool) {
	mPBool = aPBool;
}

public Boolean getPBool() {
	 return mPBool;
}

 
private net.onelab.Bytes mPBytes = new net.onelab.Bytes();

public void setPBytes(net.onelab.Bytes aPBytes) {
	mPBytes = (net.onelab.Bytes)aPBytes.clone();
}

public net.onelab.Bytes getPBytes() {
	 return mPBytes;
}

 
private java.util.GregorianCalendar mPDate = new GregorianCalendar();

public void setPDate(java.util.GregorianCalendar aPDate) {
	mPDate = aPDate;
}

public java.util.GregorianCalendar getPDate() {
	 return mPDate;
}

 
private java.util.GregorianCalendar mPDateTime = new GregorianCalendar();

public void setPDateTime(java.util.GregorianCalendar aPDateTime) {
	mPDateTime = aPDateTime;
}

public java.util.GregorianCalendar getPDateTime() {
	 return mPDateTime;
}

 
private Double mPDouble = new Double(0.0);

public void setPDouble(Double aPDouble) {
	mPDouble = aPDouble;
}

public Double getPDouble() {
	 return mPDouble;
}

 
private Float mPFloat = new Float(0.0f);

public void setPFloat(Float aPFloat) {
	mPFloat = aPFloat;
}

public Float getPFloat() {
	 return mPFloat;
}

 
private Integer mPInt32 = new Integer(0);

public void setPInt32(Integer aPInt32) {
	mPInt32 = aPInt32;
}

public Integer getPInt32() {
	 return mPInt32;
}

 
private String mPText = new String();

public void setPText(String aPText) {
	mPText = aPText;
}

public String getPText() {
	 return mPText;
}

 
private java.util.GregorianCalendar mPTime = new GregorianCalendar();

public void setPTime(java.util.GregorianCalendar aPTime) {
	mPTime = aPTime;
}

public java.util.GregorianCalendar getPTime() {
	 return mPTime;
}

 
private Integer mPUInt32 = new Integer(0);

public void setPUInt32(Integer aPUInt32) {
	mPUInt32 = aPUInt32;
}

public Integer getPUInt32() {
	 return mPUInt32;
}

public cls() {
}

public cls(Boolean aPBool, net.onelab.Bytes aPBytes, java.util.GregorianCalendar aPDate, java.util.GregorianCalendar aPDateTime, Double aPDouble, Float aPFloat, Integer aPInt32, String aPText, java.util.GregorianCalendar aPTime, Integer aPUInt32) {
	setPBool(aPBool);
	setPBytes((net.onelab.Bytes)aPBytes.clone());
	setPDate(aPDate);
	setPDateTime(aPDateTime);
	setPDouble(aPDouble);
	setPFloat(aPFloat);
	setPInt32(aPInt32);
	setPText(aPText);
	setPTime(aPTime);
	setPUInt32(aPUInt32);
}

public void _invoke_(String entry, String input, String output) {
	if (false){}
}
public static int field_count() {
	return 10;
}

private int validate_field(String key, Object value) throws ParseException {
	return input_field(key, value, false);
}

private int validate_field(int index, Object value) throws ParseException {
	return input_field(index, value, false);
}

public int input_field(String key, Object value, boolean _set_value) throws ParseException {
	int result = 0;
	if (key == null || key.isEmpty() || value == null) return 0;
	else if (key.equals("PBool")) {
		if (_set_value) {
			Boolean v = Boolean.valueOf(value.toString());
			mPBool = v;
		}
		result = 1;
	}
	else if (key.equals("PBytes")) {
		if (_set_value) {
			net.onelab.Bytes v = new net.onelab.Bytes(value.toString());
			mPBytes = (net.onelab.Bytes)v.clone();
		}
		result = 1;
	}
	else if (key.equals("PDate")) {
		if (_set_value) {
			java.util.Date v = new SimpleDateFormat("yyyy/MM/dd").parse(value.toString());
			mPDate.setTime(v);
		}
		result = 1;
	}
	else if (key.equals("PDateTime")) {
		if (_set_value) {
			java.util.Date v = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss.SSS").parse(value.toString());
			mPDateTime.setTime(v);
		}
		result = 1;
	}
	else if (key.equals("PDouble")) {
		if (_set_value) {
			Double v = Double.valueOf(value.toString());
			mPDouble = v;
		}
		result = 1;
	}
	else if (key.equals("PFloat")) {
		if (_set_value) {
			Float v = Float.valueOf(value.toString());
			mPFloat = v;
		}
		result = 1;
	}
	else if (key.equals("PInt32")) {
		if (_set_value) {
			Integer v = Integer.valueOf(value.toString());
			mPInt32 = v;
		}
		result = 1;
	}
	else if (key.equals("PText")) {
		if (_set_value) {
			String v = value.toString();
			mPText = v;
		}
		result = 1;
	}
	else if (key.equals("PTime")) {
		if (_set_value) {
			java.util.Date v = new SimpleDateFormat("HH:mm:ss.SSS").parse(value.toString());
			mPTime.setTime(v);
		}
		result = 1;
	}
	else if (key.equals("PUInt32")) {
		if (_set_value) {
			Integer v = Integer.valueOf(value.toString());
			mPUInt32 = v;
		}
		result = 1;
	}
	return result;
}

private static final String field_keys[] = { "PBool", "PBytes", "PDate", "PDateTime", "PDouble", "PFloat", "PInt32", "PText", "PTime", "PUInt32",  };
private int input_field(int index, Object value, boolean _set_value) throws ParseException {
	if (index < 0 || index > (field_count()-1) || value == null) return 0;
	return input_field(field_keys[index], value, _set_value);
}

public int to_json(StringBuilder output) {
	if (output == null) output = new StringBuilder(); else output.setLength(0);
	output.append("{" + "\"PBool\"" + ":" + "\"" + mPBool.toString() + "\"" + "," + "\"PBytes\"" + ":" + "\"" + mPBytes.toString() + "\"" + "," + "\"PDate\"" + ":" + "\"" + new SimpleDateFormat("yyyy/MM/dd").format(mPDate.getTime()) + "\"" + "," + "\"PDateTime\"" + ":" + "\"" + new SimpleDateFormat("yyyy/MM/dd HH:mm:ss.SSS").format(mPDateTime.getTime()) + "\"" + "," + "\"PDouble\"" + ":" + "\"" + mPDouble.toString() + "\"" + "," + "\"PFloat\"" + ":" + "\"" + mPFloat.toString() + "\"" + "," + "\"PInt32\"" + ":" + "\"" + mPInt32.toString() + "\"" + "," + "\"PText\"" + ":" + "\"" + mPText + "\"" + "," + "\"PTime\"" + ":" + "\"" + new SimpleDateFormat("HH:mm:ss.SSS").format(mPTime.getTime()) + "\"" + "," + "\"PUInt32\"" + ":" + "\"" + mPUInt32.toString() + "\"" + "}");
	return 1;
}

public int from_json(String input) throws JSONException, ParseException {
	if (input == null || input.length() == 0) return 0;
	JSONObject json = new JSONObject(input);
	if (json.length() != field_count()) return 0;
	for(String key : json.keySet())
		if (validate_field(key, json.get(key)) == 0)
			return 0;
	for(String key : json.keySet())
		input_field(key, json.get(key), true);
	return 1;
}

}//class cls