package javans;
 
import java.lang.*;
import java.text.*;
import java.util.*;
import net.onelab.*;
import net.onelab.JSONException;
import net.onelab.JSONObject;
public class clsList {
	public List<cls> Items = new ArrayList<cls>();
	public Object clone() {
		clsList obj = new clsList();
		obj.Items.addAll(Items);
		return obj;
	}
	public boolean equals(Object oValue) {
		if (oValue == null) return false;
		if (oValue == this) return true;
		clsList aValue = (clsList)oValue;
		if (aValue.Items.size() != Items.size()) return false;
		for (int n = 0; n < Items.size(); n++) if (!Items.get(n).equals(aValue.Items.get(n))) return false;
		return true;
	}
	public int to_json(StringBuilder output, String tag) {
		if (tag == null || tag.length() == 0) return 0;
		if (output == null) output = new StringBuilder(); else output.setLength(0);
		StringBuilder text = new StringBuilder();
		List<String> list = new ArrayList<String>();
		for(cls item : Items) {
			item.to_json(text);
			list.add(text.toString());
		}
		output.append("{\"" + tag + "\":[" + net.onelab.Text.join(",", list) + "]}");
		return 1;
	}

	public int to_json(StringBuilder output) { return to_json(output, "cls"); }

	public int from_json(String input, String tag) throws JSONException, ParseException {
		if (input == null || input.length() == 0 || tag == null || tag.length() == 0) return 0;
		JSONObject json = new JSONObject(input);
		if (!json.has(tag)) return 0;
		JSONArray array = json.getJSONArray(tag);
		List<cls> newList = new ArrayList<cls>();
		for(Object obj : array) {
			cls cls = new cls();
			if (cls.from_json(obj.toString()) == 0) return 0;
			newList.add(cls);
		}
		Items.clear();
		Items = newList;
		return 1;
	}

	public int from_json(String input) throws JSONException, ParseException { return from_json(input, "cls"); }
}//class clsList