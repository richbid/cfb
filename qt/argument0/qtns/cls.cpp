﻿/* This class framework is generated by Core Frame Builder. */
/* For more information, refer to http://www.one-lab.net/ */

/* Data Handling Class */
#include "cls.h"
#include "log.h"
inline bool qtns::cls::compare_to(cls& aValue) const {
	if (mPBool != aValue.getPBool()) return false;
	return true;
}

inline void qtns::cls::clone_from(cls& aValue) {
	setPBool(aValue.getPBool());
}

qtns::cls::~cls() {
}

qtns::cls::cls() {
	mPBool = false;
}

qtns::cls::cls(const bool& aPBool){
	setPBool(aPBool);
}

int qtns::cls::FuncBool(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, bool* aReturn) {
//function-begin : int qtns::cls::FuncBool(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, bool* aReturn) @ qtns.cls
	onelab::log::info("qtns::cls::FuncBool(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32)", "[enter]");
	return 0;
//function-end
}

int qtns::cls::FuncBytes(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, onelab::Bytes* aReturn) {
//function-begin : int qtns::cls::FuncBytes(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, onelab::Bytes* aReturn) @ qtns.cls
	onelab::log::info("qtns::cls::FuncBytes(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32)", "[enter]");
	return 0;
//function-end
}

int qtns::cls::FuncDate(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, QDate* aReturn) {
//function-begin : int qtns::cls::FuncDate(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, QDate* aReturn) @ qtns.cls
	onelab::log::info("qtns::cls::FuncDate(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32)", "[enter]");
	return 0;
//function-end
}

int qtns::cls::FuncDateTime(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, QDateTime* aReturn) {
//function-begin : int qtns::cls::FuncDateTime(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, QDateTime* aReturn) @ qtns.cls
	onelab::log::info("qtns::cls::FuncDateTime(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32)", "[enter]");
	return 0;
//function-end
}

int qtns::cls::FuncDouble(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, double* aReturn) {
//function-begin : int qtns::cls::FuncDouble(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, double* aReturn) @ qtns.cls
	onelab::log::info("qtns::cls::FuncDouble(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32)", "[enter]");
	return 0;
//function-end
}

int qtns::cls::FuncFloat(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, float* aReturn) {
//function-begin : int qtns::cls::FuncFloat(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, float* aReturn) @ qtns.cls
	onelab::log::info("qtns::cls::FuncFloat(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32)", "[enter]");
	return 0;
//function-end
}

int qtns::cls::FuncInt32(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, int* aReturn) {
//function-begin : int qtns::cls::FuncInt32(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, int* aReturn) @ qtns.cls
	onelab::log::info("qtns::cls::FuncInt32(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32)", "[enter]");
	return 0;
//function-end
}

int qtns::cls::FuncText(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, QString* aReturn) {
//function-begin : int qtns::cls::FuncText(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, QString* aReturn) @ qtns.cls
	onelab::log::info("qtns::cls::FuncText(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32)", "[enter]");
	return 0;
//function-end
}

int qtns::cls::FuncTime(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, QTime* aReturn) {
//function-begin : int qtns::cls::FuncTime(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, QTime* aReturn) @ qtns.cls
	onelab::log::info("qtns::cls::FuncTime(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32)", "[enter]");
	return 0;
//function-end
}

int qtns::cls::FuncUInt32(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, unsigned int* aReturn) {
//function-begin : int qtns::cls::FuncUInt32(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32, unsigned int* aReturn) @ qtns.cls
	onelab::log::info("qtns::cls::FuncUInt32(bool* aArgBool, onelab::Bytes* aArgBytes, QDate* aArgDate, QDateTime* aArgDateTime, double* aArgDouble, float* aArgFloat, int* aArgInt32, QString* aArgText, QTime* aArgTime, unsigned int* aArgUInt32)", "[enter]");
	return 0;
//function-end
}

void qtns::cls::_invoke_(const QString& entry, const QString& input, QString& output) {
	if (false){}
	else if (entry == "FuncBool"){
	}
	else if (entry == "FuncBytes"){
	}
	else if (entry == "FuncDate"){
	}
	else if (entry == "FuncDateTime"){
	}
	else if (entry == "FuncDouble"){
	}
	else if (entry == "FuncFloat"){
	}
	else if (entry == "FuncInt32"){
	}
	else if (entry == "FuncText"){
	}
	else if (entry == "FuncTime"){
	}
	else if (entry == "FuncUInt32"){
	}
}
int qtns::cls::field_count() {
	return 1;
}

int qtns::cls::validate_field(int index, const QVariant& value) {
	return input_field(index, value, false);
}

int qtns::cls::validate_field(const QString& key, const QVariant& value) {
	return input_field(key, value, false);
}

const QString field_keys[] = { "PBool",  };

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
	return result;
}

inline bool qtns::clsList::compare_to(clsList& aValue) const {
	if (Items.count() != aValue.Items.count()) return false;
	for (int n = 0; n < Items.count(); n++) if (Items[n] != aValue.Items[n]) return false;
	return true;
}

int qtns::cls::to_json(QString& output) {
	output = QString("{") + "\"PBool\"" + ":" + "\"" + to_string(getPBool()) + "\"" + "}";
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
	output = "<" + rowTag + ">""<PBool>" + to_xml_string(to_string(getPBool())) + "</PBool>" + "</" + rowTag + ">";
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
	list << to_string(getPBool());
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
