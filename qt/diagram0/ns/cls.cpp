﻿/* This class framework is generated by Core Frame Builder. */
/* For more information, refer to http://www.one-lab.net/ */

/* Data Handling Class */
#include "cls.h"
#include "log.h"
inline bool ns::cls::compare_to(cls& aValue) const {
	if (mPText != aValue.getPText()) return false;
	return true;
}

inline void ns::cls::clone_from(cls& aValue) {
	setPText(aValue.getPText());
}

ns::cls::~cls() {
}

ns::cls::cls() {
}

ns::cls::cls(const QString& aPText){
	setPText(aPText);
}

int ns::cls::trigger(int* aReturn) {
//function-begin : int ns::cls::trigger(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::trigger()", "[enter]");
	f0(aReturn);
	f1(aReturn);
	f2(aReturn);
	return 0;
//function-end
}

int ns::cls::f0(int* aReturn) {
//function-begin : int ns::cls::f0(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::f0()", "[enter]");
	return 0;
//function-end
}

int ns::cls::f1(int* aReturn) {
//function-begin : int ns::cls::f1(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::f1()", "[enter]");
	if (ifx0(aReturn) != 0) { tfx(aReturn); } else { ffx(aReturn); }
	return 0;
//function-end
}

int ns::cls::f2(int* aReturn) {
//function-begin : int ns::cls::f2(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::f2()", "[enter]");
	if (ifx1(aReturn) != 0) { tf0(aReturn); tf1(aReturn); tf2(aReturn); } else { f0(aReturn); f1(aReturn); f2(aReturn); }
	return 0;
//function-end
}

int ns::cls::ifx0(int* aReturn) {
//function-begin : int ns::cls::ifx0(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::ifx0()", "[enter]");
	return 0;
//function-end
}

int ns::cls::tfx(int* aReturn) {
//function-begin : int ns::cls::tfx(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::tfx()", "[enter]");
	switch (sfx0(aReturn)) {
	case 0: cfx(aReturn); break;
	case 1: return -1;
	case 2: return -2;
	default:break;
	}
	return 0;
//function-end
}

int ns::cls::ffx(int* aReturn) {
//function-begin : int ns::cls::ffx(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::ffx()", "[enter]");
	switch (sfx1(aReturn)) {
	case 0: cf0(aReturn); break;
	case 1: cf1(aReturn); break;
	case 2: cf2(aReturn); break;
	default:break;
	}
	return 0;
//function-end
}

int ns::cls::ifx1(int* aReturn) {
//function-begin : int ns::cls::ifx1(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::ifx1()", "[enter]");
	return 0;
//function-end
}

int ns::cls::tf0(int* aReturn) {
//function-begin : int ns::cls::tf0(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::tf0()", "[enter]");
	return 0;
//function-end
}

int ns::cls::tf1(int* aReturn) {
//function-begin : int ns::cls::tf1(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::tf1()", "[enter]");
	return 0;
//function-end
}

int ns::cls::tf2(int* aReturn) {
//function-begin : int ns::cls::tf2(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::tf2()", "[enter]");
	return 0;
//function-end
}

int ns::cls::sfx0(int* aReturn) {
//function-begin : int ns::cls::sfx0(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::sfx0()", "[enter]");
	return 0;
//function-end
}

int ns::cls::cfx(int* aReturn) {
//function-begin : int ns::cls::cfx(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::cfx()", "[enter]");
	return 0;
//function-end
}

int ns::cls::sfx1(int* aReturn) {
//function-begin : int ns::cls::sfx1(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::sfx1()", "[enter]");
	return 0;
//function-end
}

int ns::cls::cf0(int* aReturn) {
//function-begin : int ns::cls::cf0(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::cf0()", "[enter]");
	while (wfx0(aReturn) != 0) { lfx(aReturn); }
	return 0;
//function-end
}

int ns::cls::cf1(int* aReturn) {
//function-begin : int ns::cls::cf1(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::cf1()", "[enter]");
	while (wfx1(aReturn) != 0) { lf0(aReturn); lf1(aReturn); lf2(aReturn); }
	return 0;
//function-end
}

int ns::cls::cf2(int* aReturn) {
//function-begin : int ns::cls::cf2(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::cf2()", "[enter]");
	return 0;
//function-end
}

int ns::cls::wfx0(int* aReturn) {
//function-begin : int ns::cls::wfx0(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::wfx0()", "[enter]");
	return 0;
//function-end
}

int ns::cls::lfx(int* aReturn) {
//function-begin : int ns::cls::lfx(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::lfx()", "[enter]");
	return 0;
//function-end
}

int ns::cls::wfx1(int* aReturn) {
//function-begin : int ns::cls::wfx1(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::wfx1()", "[enter]");
	return 0;
//function-end
}

int ns::cls::lf0(int* aReturn) {
//function-begin : int ns::cls::lf0(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::lf0()", "[enter]");
	return 0;
//function-end
}

int ns::cls::lf1(int* aReturn) {
//function-begin : int ns::cls::lf1(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::lf1()", "[enter]");
	return 0;
//function-end
}

int ns::cls::lf2(int* aReturn) {
//function-begin : int ns::cls::lf2(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::lf2()", "[enter]");
	if (if10(aReturn) != 0) { return -1; } else { return -2; }
//function-end
}

int ns::cls::if9(int* aReturn) {
//function-begin : int ns::cls::if9(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::if9()", "[enter]");
	return 0;
//function-end
}

int ns::cls::tf10(int* aReturn) {
//function-begin : int ns::cls::tf10(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::tf10()", "[enter]");
	while (lf10(aReturn) != 0);
	return 0;
//function-end
}

int ns::cls::if10(int* aReturn) {
//function-begin : int ns::cls::if10(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::if10()", "[enter]");
	return 0;
//function-end
}

int ns::cls::lf10(int* aReturn) {
//function-begin : int ns::cls::lf10(int* aReturn) @ ns.cls
	onelab::log::info("ns::cls::lf10()", "[enter]");
	return 0;
//function-end
}

void ns::cls::_invoke_(const QString& entry, const QString& input, QString& output) {
	if (false){}
	else if (entry == "trigger"){
	}
}
int ns::cls::field_count() {
	return 1;
}

int ns::cls::validate_field(int index, const QVariant& value) {
	return input_field(index, value, false);
}

int ns::cls::validate_field(const QString& key, const QVariant& value) {
	return input_field(key, value, false);
}

const QString field_keys[] = { "PText",  };

int ns::cls::input_field(int index, const QVariant& value, bool _set_value) {
	if (index < 0 || index > (field_count()-1)) return 0;
	return input_field(field_keys[index], value, _set_value);
}

int ns::cls::input_field(const QString& key, const QVariant& value, bool _set_value) {
	int result = 0;
	if (!key.length()) return 0;
	else if (key == "PText") {
		if (_set_value) {
			QString v = value.toString();
			setPText(v);
		}
		result = 1;
	}
	return result;
}

inline bool ns::clsList::compare_to(clsList& aValue) const {
	if (Items.count() != aValue.Items.count()) return false;
	for (int n = 0; n < Items.count(); n++) if (Items[n] != aValue.Items[n]) return false;
	return true;
}

int ns::cls::to_json(QString& output) {
	output = QString("{") + "\"PText\"" + ":" + "\"" + mPText + "\"" + "}";
	return 1;
}

int ns::clsList::to_json(QString& output, const QString& tag) {
	if (!tag.length()) return 0;
	QStringList list;
	QString text;
	foreach(cls item, Items) {
		item.to_json(text);
		list += text;
	}
	output = "{\"" + tag + "\":[" + list.join(",") + "]}";
	return 1;
}

int ns::cls::from_json(const QMap<QString, QVariant>& map) {
	if (map.count() != field_count()) return 0;
	foreach(QString key, map.keys())
		if (!validate_field(key, map[key])) return 0;
	foreach(QString key, map.keys())
		input_field(key, map[key], true);
	return 1;
}

int ns::cls::from_json(const QString& input) {
	if (!input.length()) return 0;
	QJson json;
	QVariant variant = json.decode(input);
	if (variant.type () == QVariant::Map) {
		QMap<QString, QVariant> map = variant.toMap();
		return from_json(map);
	}
	return 0;
}

int ns::clsList::from_json(const QString& input, const QString& tag) {
		if (!input.length() || !tag.length()) return 0;
		QJson json;
		QVariant variant = json.decode(input);
		if (variant.type() != QVariant::Map) return 0;
		QMap<QString, QVariant> map = variant.toMap();
		if (!map.count() || map.keys()[0] != tag)
				return 0;
		QList<QVariant> list = map.values()[0].toList();
		if (!list.count()) return 0;
		QList<cls> newList;
		cls cls;
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

int ns::cls::to_xml(QString& output, const QString& rowTag) {
	output = "<" + rowTag + ">""<PText>" + to_xml_string(mPText) + "</PText>" + "</" + rowTag + ">";
	return 1;
}

int ns::clsList::to_xml(QString& output, const QString& rowTag, const QString& tableTag) {
	if(!rowTag.length() || !tableTag.length()) return 0;
	QStringList list;
	QString text;
	foreach(cls item, Items) {
		item.to_xml(text, rowTag);
		list += text;
	}
	output = "<" + tableTag + ">" + list.join("") + "</" + tableTag + ">";
	return 1;
}

int ns::cls::from_xml(const QDomElement& element, QHash<QString, QString>& values) {
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

int ns::cls::from_xml(const QString& input, const QString& rowTag) {
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

int ns::clsList::from_xml(const QString& input, const QString& rowTag, const QString& tableTag) {
	if (!input.length() || !rowTag.length() || !tableTag.length()) return 0;
	QDomDocument doc;
	if (!doc.setContent(input))
		return 0;
	if (doc.documentElement().tagName() != tableTag)
		return 0;
	QList<cls> newList;
	cls cls;
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

int ns::cls::to_sv(QString& output, const QString& spliter) {
	if (!spliter.length()) return 0;
	QStringList list;
	list << mPText;
	output = list.join(spliter);
	return 1;
}

int ns::clsList::to_sv(QString& output, const QString& spliter) {
	if (!spliter.length()) return 0;
	QStringList list;
	QString text;
	foreach(cls item, Items) {
		item.to_sv(text, spliter);
		list += text;
	}
	output = list.join("\n");
	return 1;
}

int ns::cls::from_sv(const QString& input, const QString& spliter) {
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

int ns::clsList::from_sv(const QString& input, const QString& spliter) {
	if (!input.length() || !spliter.length()) return 0;
	QString raw = input; raw.replace("\r", "");
	QStringList list = raw.split("\n", QString::SkipEmptyParts);
	if (!list.count()) return 0;
	clsList newList;
	foreach(QString item, list) {
		cls cls;
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
