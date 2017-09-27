﻿/* This class framework is generated by Core Frame Builder. */
/* For more information, refer to http://www.one-lab.net/ */

/* Data Handling Class */
#include "cls.h"
inline bool qtns::cls::compare_to(cls& aValue) const {
	if (mPBool != aValue.getPBool()) return false;
	if (mPBytes != aValue.getPBytes()) return false;
	if (mPDate != aValue.getPDate()) return false;
	if (mPDateTime != aValue.getPDateTime()) return false;
	if (mPDouble != aValue.getPDouble()) return false;
	if (mPFloat != aValue.getPFloat()) return false;
	if (mPInt32 != aValue.getPInt32()) return false;
	if (mPText != aValue.getPText()) return false;
	if (mPTime != aValue.getPTime()) return false;
	if (mPUInt32 != aValue.getPUInt32()) return false;
	return true;
}

inline void qtns::cls::clone_from(cls& aValue) {
	setPBool(aValue.getPBool());
	setPBytes(aValue.getPBytes());
	setPDate(aValue.getPDate());
	setPDateTime(aValue.getPDateTime());
	setPDouble(aValue.getPDouble());
	setPFloat(aValue.getPFloat());
	setPInt32(aValue.getPInt32());
	setPText(aValue.getPText());
	setPTime(aValue.getPTime());
	setPUInt32(aValue.getPUInt32());
}

qtns::cls::~cls() {
}

qtns::cls::cls() {
	mPBool = false;
	mPDouble = 0.0;
	mPFloat = 0.0f;
	mPInt32 = 0;
	mPUInt32 = 0u;
}

qtns::cls::cls(const bool& aPBool, const onelab::Bytes& aPBytes, const QDate& aPDate, const QDateTime& aPDateTime, const double& aPDouble, const float& aPFloat, const int& aPInt32, const QString& aPText, const QTime& aPTime, const unsigned int& aPUInt32){
	setPBool(aPBool);
	setPBytes(aPBytes);
	setPDate(aPDate);
	setPDateTime(aPDateTime);
	setPDouble(aPDouble);
	setPFloat(aPFloat);
	setPInt32(aPInt32);
	setPText(aPText);
	setPTime(aPTime);
	setPUInt32(aPUInt32);
}

void qtns::cls::_invoke_(const QString& entry, const QString& input, QString& output) {
	if (false){}
}
int qtns::cls::field_count() {
	return 10;
}

int qtns::cls::validate_field(int index, const QVariant& value) {
	return input_field(index, value, false);
}

int qtns::cls::validate_field(const QString& key, const QVariant& value) {
	return input_field(key, value, false);
}

const QString field_keys[] = { "PBool", "PBytes", "PDate", "PDateTime", "PDouble", "PFloat", "PInt32", "PText", "PTime", "PUInt32",  };

int qtns::cls::input_field(int index, const QVariant& value, bool _set_value) {
	if (index < 0 || index > (field_count()-1)) return 0;
	return input_field(field_keys[index], value, _set_value);
}

int qtns::cls::input_field(const QString& key, const QVariant& value, bool _set_value) {
	int result = 0;
	if (!key.length()) return 0;
	else if (key == "PBool") {
		if (_set_value) {
			bool v = value.toBool();
			setPBool(v);
		}
		result = 1;
	}
	else if (key == "PBytes") {
		if (_set_value) {
			onelab::Bytes v(value.toString());
			setPBytes(v);
		}
		result = 1;
	}
	else if (key == "PDate") {
		if (_set_value) {
			QDate v = value.toDate();
			setPDate(v);
		}
		result = 1;
	}
	else if (key == "PDateTime") {
		if (_set_value) {
			QDateTime v = value.toDateTime();
			setPDateTime(v);
		}
		result = 1;
	}
	else if (key == "PDouble") {
		if (_set_value) {
			double v = value.toDouble();
			setPDouble(v);
		}
		result = 1;
	}
	else if (key == "PFloat") {
		if (_set_value) {
			float v = value.toFloat();
			setPFloat(v);
		}
		result = 1;
	}
	else if (key == "PInt32") {
		if (_set_value) {
			int v = value.toInt();
			setPInt32(v);
		}
		result = 1;
	}
	else if (key == "PText") {
		if (_set_value) {
			QString v = value.toString();
			setPText(v);
		}
		result = 1;
	}
	else if (key == "PTime") {
		if (_set_value) {
			QTime v = value.toTime();
			setPTime(v);
		}
		result = 1;
	}
	else if (key == "PUInt32") {
		if (_set_value) {
			unsigned int v = value.toUInt();
			setPUInt32(v);
		}
		result = 1;
	}
	return result;
}

inline bool qtns::clsList::compare_to(clsList& aValue) const {
	if (Items.count() != aValue.Items.count()) return false;
	for (int n = 0; n < Items.count(); n++) if (Items[n] != aValue.Items[n]) return false;
	return true;
}

int qtns::cls::to_json(QString& output) {
	output = QString("{") + "\"PBool\"" + ":" + "\"" + to_string(getPBool()) + "\"" + "," + "\"PBytes\"" + ":" + "\"" + mPBytes.toString() + "\"" + "," + "\"PDate\"" + ":" + "\"" + mPDate.toString("yyyy/MM/dd") + "\"" + "," + "\"PDateTime\"" + ":" + "\"" + mPDateTime.toString("yyyy/MM/dd HH:mm:ss.zzz") + "\"" + "," + "\"PDouble\"" + ":" + "\"" + to_string(getPDouble()) + "\"" + "," + "\"PFloat\"" + ":" + "\"" + to_string(getPFloat()) + "\"" + "," + "\"PInt32\"" + ":" + "\"" + to_string(getPInt32()) + "\"" + "," + "\"PText\"" + ":" + "\"" + mPText + "\"" + "," + "\"PTime\"" + ":" + "\"" + mPTime.toString("HH:mm:ss.zzz") + "\"" + "," + "\"PUInt32\"" + ":" + "\"" + to_string(getPUInt32()) + "\"" + "}";
	return 1;
}

int qtns::clsList::to_json(QString& output, const QString& tag) {
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

int qtns::cls::from_json(const QMap<QString, QVariant>& map) {
	if (map.count() != field_count()) return 0;
	foreach(QString key, map.keys())
		if (!validate_field(key, map[key])) return 0;
	foreach(QString key, map.keys())
		input_field(key, map[key], true);
	return 1;
}

int qtns::cls::from_json(const QString& input) {
	if (!input.length()) return 0;
	QJson json;
	QVariant variant = json.decode(input);
	if (variant.type () == QVariant::Map) {
		QMap<QString, QVariant> map = variant.toMap();
		return from_json(map);
	}
	return 0;
}

int qtns::clsList::from_json(const QString& input, const QString& tag) {
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

int qtns::cls::to_xml(QString& output, const QString& rowTag) {
	output = "<" + rowTag + ">""<PBool>" + to_xml_string(to_string(getPBool())) + "</PBool>" + "<PBytes>" + to_xml_string(getPBytes().toString()) + "</PBytes>" + "<PDate>" + to_xml_string(to_string(getPDate())) + "</PDate>" + "<PDateTime>" + to_xml_string(to_string(getPDateTime())) + "</PDateTime>" + "<PDouble>" + to_xml_string(to_string(getPDouble())) + "</PDouble>" + "<PFloat>" + to_xml_string(to_string(getPFloat())) + "</PFloat>" + "<PInt32>" + to_xml_string(to_string(getPInt32())) + "</PInt32>" + "<PText>" + to_xml_string(mPText) + "</PText>" + "<PTime>" + to_xml_string(to_string(getPTime())) + "</PTime>" + "<PUInt32>" + to_xml_string(to_string(getPUInt32())) + "</PUInt32>" + "</" + rowTag + ">";
	return 1;
}

int qtns::clsList::to_xml(QString& output, const QString& rowTag, const QString& tableTag) {
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

int qtns::cls::from_xml(const QDomElement& element, QHash<QString, QString>& values) {
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

int qtns::cls::from_xml(const QString& input, const QString& rowTag) {
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

int qtns::clsList::from_xml(const QString& input, const QString& rowTag, const QString& tableTag) {
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

int qtns::cls::to_sv(QString& output, const QString& spliter) {
	if (!spliter.length()) return 0;
	QStringList list;
	list << to_string(getPBool()) << getPBytes().toString() << to_string(getPDate()) << to_string(getPDateTime()) << to_string(getPDouble()) << to_string(getPFloat()) << to_string(getPInt32()) << mPText << to_string(getPTime()) << to_string(getPUInt32());
	output = list.join(spliter);
	return 1;
}

int qtns::clsList::to_sv(QString& output, const QString& spliter) {
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

int qtns::cls::from_sv(const QString& input, const QString& spliter) {
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

int qtns::clsList::from_sv(const QString& input, const QString& spliter) {
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