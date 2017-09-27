﻿/* This class framework is generated by Core Frame Builder. */
/* For more information, refer to http://www.one-lab.net/ */

/* Data Handling Class */
#include "cls2.h"
inline bool ns::cls2::compare_to(cls2& aValue) const {
	if (!ns::cls::compare_to(aValue)) return false;
	if (mPInt != aValue.getPInt()) return false;
	return true;
}

inline void ns::cls2::clone_from(cls2& aValue) {
	ns::cls::clone_from(aValue);
	setPInt(aValue.getPInt());
}

ns::cls2::~cls2() {
}

ns::cls2::cls2() {
	mPInt = 0;
}

ns::cls2::cls2(const int& aPInt){
	setPInt(aPInt);
}

void ns::cls2::_invoke_(const QString& entry, const QString& input, QString& output) {
	if (false){}
}
int ns::cls2::field_count() {
	return ns::cls::field_count() + 1;
}

int ns::cls2::validate_field(int index, const QVariant& value) {
	return input_field(index, value, false);
}

int ns::cls2::validate_field(const QString& key, const QVariant& value) {
	return input_field(key, value, false);
}

const QString field_keys[] = { "PInt",  };

int ns::cls2::input_field(int index, const QVariant& value, bool _set_value) {
	if (index < 0 || index > (field_count()-1)) return 0;
	return input_field(field_keys[index], value, _set_value);
}

int ns::cls2::input_field(const QString& key, const QVariant& value, bool _set_value) /*override*/ {
	if (ns::cls::input_field(key, value, _set_value) == 1) return 1;
	int result = 0;
	if (!key.length()) return 0;
	else if (key == "PInt") {
		if (_set_value) {
			int v = value.toInt();
			setPInt(v);
		}
		result = 1;
	}
	return result;
}

inline bool ns::cls2List::compare_to(cls2List& aValue) const {
	if (Items.count() != aValue.Items.count()) return false;
	for (int n = 0; n < Items.count(); n++) if (Items[n] != aValue.Items[n]) return false;
	return true;
}

int ns::cls2::to_json(QString& output) /*override*/ {
	QString baseOutput;
	if (ns::cls::to_json(baseOutput) == 0) return 0;
	baseOutput = baseOutput.mid(1, baseOutput.length()-2) + ",";
	output = QString("{") + baseOutput + "\"PInt\"" + ":" + "\"" + to_string(getPInt()) + "\"" + "}";
	return 1;
}

int ns::cls2List::to_json(QString& output, const QString& tag) {
	if (!tag.length()) return 0;
	QStringList list;
	QString text;
	foreach(cls2 item, Items) {
		item.to_json(text);
		list += text;
	}
	output = "{\"" + tag + "\":[" + list.join(",") + "]}";
	return 1;
}

int ns::cls2::from_json(const QMap<QString, QVariant>& map) {
	if (map.count() != field_count()) return 0;
	foreach(QString key, map.keys())
		if (!validate_field(key, map[key])) return 0;
	foreach(QString key, map.keys())
		input_field(key, map[key], true);
	return 1;
}

int ns::cls2::from_json(const QString& input) {
	if (!input.length()) return 0;
	QJson json;
	QVariant variant = json.decode(input);
	if (variant.type () == QVariant::Map) {
		QMap<QString, QVariant> map = variant.toMap();
		return from_json(map);
	}
	return 0;
}

int ns::cls2List::from_json(const QString& input, const QString& tag) {
		if (!input.length() || !tag.length()) return 0;
		QJson json;
		QVariant variant = json.decode(input);
		if (variant.type() != QVariant::Map) return 0;
		QMap<QString, QVariant> map = variant.toMap();
		if (!map.count() || map.keys()[0] != tag)
				return 0;
		QList<QVariant> list = map.values()[0].toList();
		if (!list.count()) return 0;
		QList<cls2> newList;
		cls2 cls;
		foreach(variant, list) {
			QMap<QString, QVariant> map = variant.toMap();
			if (!cls.from_json(map))
					return 0;
			newList << cls;
		}
		Items.clear();
		Items = newList;
		return 1;
	return 0;
}

int ns::cls2::to_xml(QString& output, const QString& rowTag) /*override*/ {
	QString baseOutput;
	if (ns::cls::to_xml(baseOutput, rowTag) == 0) return 0;
	baseOutput = baseOutput.replace("<" + rowTag + ">", "").replace("</" + rowTag + ">", "");
	output = "<" + rowTag + ">" + baseOutput + "<PInt>" + to_xml_string(to_string(getPInt())) + "</PInt>" + "</" + rowTag + ">";
	return 1;
}

int ns::cls2List::to_xml(QString& output, const QString& rowTag, const QString& tableTag) {
	if(!rowTag.length() || !tableTag.length()) return 0;
	QStringList list;
	QString text;
	foreach(cls2 item, Items) {
		item.to_xml(text, rowTag);
		list += text;
	}
	output = "<" + tableTag + ">" + list.join("") + "</" + tableTag + ">";
	return 1;
}

int ns::cls2::from_xml(const QDomElement& element, QHash<QString, QString>& values) {
	values.clear();
	for (QDomElement elm = element; !elm.isNull(); elm = elm.nextSibling().toElement()) {
		QString key = elm.tagName();		
		QString value = elm.text();
		if (!key.length())
			break;
		if (!validate_field(key, value))
			return 0;		
		values.insert(key, value);
	}
	foreach(QString k, values.keys())
		input_field(k, values[k], true);
	return 1;
}

int ns::cls2::from_xml(const QString& input, const QString& rowTag) {
	if (!input.length() || !rowTag.length()) return 0;
	QDomDocument doc;
	if (!doc.setContent(input))
		return 0;
	if (doc.documentElement().tagName() != rowTag)
		return 0;
	QHash<QString, QString> values;
	QDomElement elm = doc.documentElement().firstChildElement();
	if (!from_xml(doc.documentElement().firstChildElement(), values))
		return 0;
	foreach(QString k, values.keys())
		input_field(k, values[k], true);
	return 1;
}

int ns::cls2List::from_xml(const QString& input, const QString& rowTag, const QString& tableTag) {
	if (!input.length() || !rowTag.length() || !tableTag.length()) return 0;
	QDomDocument doc;
	if (!doc.setContent(input))
		return 0;
	if (doc.documentElement().tagName() != tableTag)
		return 0;
	QList<cls2> newList;
	cls2 cls;
	for (QDomElement elm = doc.documentElement().firstChildElement(); !elm.isNull(); elm = elm.nextSibling().toElement()) {
		if (elm.tagName() != rowTag)
			return 0;
		QHash<QString, QString> values;
		if (!cls.from_xml(elm.firstChildElement(), values))
			return 0;
		newList << cls;
	}
	Items.clear();
	Items = newList;
	return 1;
}

int ns::cls2::to_sv(QString& output, const QString& spliter) /*override*/ {
	QString baseOutput;
	if (ns::cls::to_sv(baseOutput, spliter) == 0) return 0;
	QStringList list;
	list << baseOutput << to_string(getPInt());
	output = list.join(spliter);
	return 1;
}

int ns::cls2List::to_sv(QString& output, const QString& spliter) {
	if (!spliter.length()) return 0;
	QStringList list;
	QString text;
	foreach(cls2 item, Items) {
		item.to_sv(text, spliter);
		list += text;
	}
	output = list.join("\n");
	return 1;
}

int ns::cls2::from_sv(const QString& input, const QString& spliter) {
	if (!input.length() || !spliter.length()) return 0;
	QStringList list = input.split(spliter, QString::SkipEmptyParts);
	if (list.count() != field_count()) return 0;
	int index = 0;
	foreach(QString item, list)
		if (!validate_field(index++, item))
			return 0;
	index = 0;
	foreach(QString item, list)
		input_field(index++, item, true);
	return 1;
}

int ns::cls2List::from_sv(const QString& input, const QString& spliter) {
	if (!input.length() || !spliter.length()) return 0;
	QString raw = input; raw.replace("\r", "");
	QStringList list = raw.split("\n", QString::SkipEmptyParts);
	if (!list.count()) return 0;
	cls2List newList;
	foreach(QString item, list) {
		cls2 cls;
		if (!cls.from_sv(item, spliter)) return 0;
		newList.Items += cls;
	}
	if (newList.Items.count() == list.count()) {
		Items.clear();
		Items = newList.Items;
		return 1;
	}
	return 0;
}
