/* This class framework is generated by Core Frame Builder. */
/* For more information, refer to http://www.one-lab.net/ */

/* Data Handling Class */
package ns;
 
import java.lang.*;
import java.text.*;
import java.util.*;
import net.onelab.*;
import net.onelab.JSONException;
import net.onelab.JSONObject;

public class cls implements Cloneable {
protected void clone_from(cls aValue) {
	setPBool(aValue.getPBool());
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
	return true;
}
 
private Boolean mPBool = new Boolean(false);

public void setPBool(Boolean aPBool) {
	mPBool = aPBool;
}

public Boolean getPBool() {
	 return mPBool;
}

public cls() {
}

public cls(Boolean aPBool) {
	setPBool(aPBool);
}

public void _invoke_(String entry, String input, String output) {
	if (false){}
}
public static int field_count() {
	return 1;
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
	return result;
}

private static final String field_keys[] = { "PBool",  };
private int input_field(int index, Object value, boolean _set_value) throws ParseException {
	if (index < 0 || index > (field_count()-1) || value == null) return 0;
	return input_field(field_keys[index], value, _set_value);
}

public int to_json(StringBuilder output) {
	if (output == null) output = new StringBuilder(); else output.setLength(0);
	output.append("{" + "\"PBool\"" + ":" + "\"" + mPBool.toString() + "\"" + "}");
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

public int to_xml(StringBuilder output, String rowTag) {
	if (rowTag == null || rowTag.length() < 1) return 0;
	if (output == null) output = new StringBuilder(); else output.setLength(0);
	output.append("<" + rowTag + ">" + "<PBool>" + mPBool.toString().replace("<", "&lt;").replace(">", "&gt;") + "</PBool>" + "</" + rowTag + ">");
	return 1;
}

public int from_xml(String input, String rowTag) throws JSONException, ParseException {
	if (input == null || input.length() == 0 || rowTag == null || rowTag.length() == 0) return 0;
	JSONObject json = XML.toJSONObject(input);
	if (!json.has(rowTag)) return 0;
	return from_json(json.get(rowTag).toString());
}

public int to_sv(StringBuilder output, String spliter) {
	if (spliter == null || spliter.length() == 0) return 0;
	if (output == null) output = new StringBuilder(); else output.setLength(0);
	java.util.List<String> list = new ArrayList<String>();
	list.add(mPBool.toString());

	output.append(net.onelab.Text.join(spliter, list));
	return 1;
}

public int from_sv(String input, String spliter) throws ParseException {
	if (input == null || input.length() == 0 || spliter == null || spliter.length() == 0) return 0;
	String[] list = input.split(spliter);
	if (list.length != field_count()) return 0;
	int index = 0;
	for(String item : list)
		if (validate_field(index++, item) == 0)
			return 0;
	index = 0;
	for(String item : list)
		input_field(index++, item, true);
	return 1;
}

}//class cls