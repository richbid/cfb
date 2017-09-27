#ifndef _CONFIG_H_
#define _CONFIG_H_
//TEMPLATE for MS VC2010 2016/11/16 11:03
#include "QtCore/qobject.h"
#include "QtCore/qtextcodec.h"
#include "QtCore/qstring.h"
#include "QtCore/qstringlist.h"
#include "QtCore/qstack.h"
#include "QtCore/qqueue.h"
#include "QtCore/qlinkedlist.h"
#include "QtCore/qlist.h"
#include "QtCore/qvector.h"
#include "QtCore/qhash.h"
#include "QtCore/qvariant.h"
#include "QtCore/qfile.h"
#include "QtCore/qdatetime.h"
#include "QtCore/QCryptographicHash"
#include "QtXml/qxml.h"
#include "QtXml/qdom.h"
#include "qjson.h"

#define rw_cls_field(t, n) \
	protected: \
		t m##n; \
	public: \
		void set##n(t v) { m##n = v; } \
		t get##n() { return m##n; }

#define ro_cls_field(t, n) \
	protected: \
		t m##n; \
		void set##n(t v) { m##n = v; } \
		t get##n() { return m##n; }

#define rw_field_range(t, n) \
	protected: \
		t m##n; \
		t m##n##Min; \
		t m##n##Max; \
		QList<t> m##n##Range; \
	public: \
		void set##n##Min(const t& v) { m##n##Min = v; } \
		void set##n##Max(const t& v) { m##n##Max = v; } \
		void add##n##Range(const t& v) { if (!m##n##Range.contains(v)) m##n##Range << v; } \
		void set##n(const t& v) { m##n = v; } \
		bool set##n##ByMaxMin(const t& v) { if (v >= m##n##Min && v <= m##n##Max) { m##n = v; return true; } return false; } \
		bool set##n##ByRange(const t& v) { if (m##n##Range.contains(v)) { m##n##Range << v; return true; } return false; } \
		t& get##n() { return m##n; }

#define rw_field(t, n) \
    protected: \
        t m##n; \
    public: \
        void set##n(const t& v) { m##n = v; } \
        t& get##n() { return m##n; }

#define ro_field_range(t, n) \
	protected: \
		t m##n; \
		t m##n##Min; \
		t m##n##Max; \
		QList<t> m##n##Range; \
		void set##n##Min(const t& v) { m##n##Min = v; } \
		void set##n##Max(const t& v) { m##n##Max = v; } \
		void set##n(const t& v) { m##n = v; } \
		void add##n##Range(const t& v) { if (!m##n##Range.contains(v)) m##n##Range << v; } \
		bool set##n##ByMaxMin(const t& v) { if (v >= m##n##Min && v <= m##n##Max) { m##n = v; return true; } return false; } \
		bool set##n##ByRange(const t& v) { if (m##n##Range.contains(v)) { m##n##Range << v; return true; } return false; } \
	public: \
		const t& get##n() { return m##n; }

#define ro_field(t, n) \
    protected: \
        t m##n; \
		void set##n(const t& v) { m##n = v; } \
    public: \
        const t& get##n() { return m##n; }

inline QString variant_string(QVariant v)
{
    QString s;
    switch (v.type())
    {
    case QVariant::DateTime:
        s = v.toDateTime().toString("yyyy/MM/dd HH:mm:ss.zzz");
        break;
    case QVariant::Date:
        s = v.toDateTime().toString("yyyy/MM/dd");
        break;
    case QVariant::Time:
        s = v.toTime().toString("HH:mm:ss.zzz");
        break;
    default:
        s = v.toString();
    }
    return s;
}

#define to_string(v)		variant_string(QVariant(v))
#define to_xml_string(v)	QString(v).replace("<", "&lt;").replace(">", "&gt;")
#define from_xml_string(v)	QString(v).replace("&lt;", "<").replace("&gt;", ">")
#define remove_quote(v)		v.remove(0, 1); v.remove(v.length() - 1, 1)

#endif
