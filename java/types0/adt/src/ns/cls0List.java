package ns;
 
import java.lang.*;
import java.text.*;
import java.util.*;
import net.onelab.*;
import net.onelab.JSONException;
import net.onelab.JSONObject;
public class cls0List {
	public List<cls0> Items = new ArrayList<cls0>();
	public Object clone() {
		cls0List obj = new cls0List();
		obj.Items.addAll(Items);
		return obj;
	}
	public boolean equals(Object oValue) {
		if (oValue == null) return false;
		if (oValue == this) return true;
		cls0List aValue = (cls0List)oValue;
		if (aValue.Items.size() != Items.size()) return false;
		for (int n = 0; n < Items.size(); n++) if (!Items.get(n).equals(aValue.Items.get(n))) return false;
		return true;
	}
	public int to_json(StringBuilder output, String tag) {
		if (tag == null || tag.length() == 0) return 0;
		if (output == null) output = new StringBuilder(); else output.setLength(0);
		StringBuilder text = new StringBuilder();
		List<String> list = new ArrayList<String>();
		for(cls0 item : Items) {
			item.to_json(text);
			list.add(text.toString());
		}
		output.append("{\"" + tag + "\":[" + net.onelab.Text.join(",", list) + "]}");
		return 1;
	}

	public int to_json(StringBuilder output) { return to_json(output, "cls0"); }

	public int from_json(String input, String tag) throws JSONException, ParseException {
		if (input == null || input.length() == 0 || tag == null || tag.length() == 0) return 0;
		JSONObject json = new JSONObject(input);
		if (!json.has(tag)) return 0;
		JSONArray array = json.getJSONArray(tag);
		List<cls0> newList = new ArrayList<cls0>();
		for(Object obj : array) {
			cls0 cls = new cls0();
			if (cls.from_json(obj.toString()) == 0) return 0;
			newList.add(cls);
		}
		Items.clear();
		Items = newList;
		return 1;
	}

	public int from_json(String input) throws JSONException, ParseException { return from_json(input, "cls0"); }
	public int to_xml(StringBuilder output, String rowTag, String tableTag) {
		if (rowTag == null || rowTag.length() == 0 || tableTag == null || tableTag.length() == 0) return 0;
		if (output == null) output = new StringBuilder(); else output.setLength(0);
		StringBuilder text = new StringBuilder();
		List<String> list = new ArrayList<String>();
		for(cls0 item : Items) {
			item.to_xml(text, rowTag);
			list.add(text.toString());
		}
		output.append("<" + tableTag + ">" + net.onelab.Text.join("", list) + "</" + tableTag + ">");
		return 1;
	}

	public int from_xml(String input, String rowTag, String tableTag) throws JSONException, ParseException {
		if (input == null || input.length() == 0 || rowTag == null || rowTag.length() == 0 || tableTag == null || tableTag.length() == 0) return 0;
		JSONObject json = XML.toJSONObject(input);
		if (!json.has(tableTag)) return 0;
		json = (JSONObject)json.get(tableTag);
		if (!json.has(rowTag)) return 0;
		JSONArray array = json.getJSONArray(rowTag);
		List<cls0> newList = new ArrayList<cls0>();
		for(Object obj : array) {
			cls0 cls = new cls0();
			if (cls.from_json(obj.toString()) == 0) return 0;
			newList.add(cls);
		}
		Items.clear();
		Items = newList;		
		return 1;
	}

	public int to_sv(StringBuilder output, String spliter) {
		if (spliter == null || spliter.length() == 0) return 0;
		if (output == null) output = new StringBuilder(); else output.setLength(0);
		StringBuilder text = new StringBuilder();
		List<String> list = new ArrayList<String>();
		for(cls0 item : Items) {
			item.to_sv(text, spliter);
			list.add(text.toString());
		}
		output.append(net.onelab.Text.join("\n", list));
		return 1;
	}

	public int from_sv(String input, String spliter) throws ParseException {
		if (input == null || input.length() == 0 || spliter == null || spliter.length() == 0) return 0;
		String[] list = input.split("\n");
		if (list.length == 0) return 0;
		List<cls0> newList = new ArrayList<cls0>();
		for(String item : list) {
			cls0 cls = new cls0();
			if (cls.from_sv(item, spliter) == 0) return 0;
			newList.add(cls);
		}
		if (newList.size() == list.length) {
			Items.clear();
			Items = newList;
			return 1;
		}
		return 0;
	}

}//class cls0List