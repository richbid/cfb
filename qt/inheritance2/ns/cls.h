﻿/* This class framework is generated by Core Frame Builder. */
/* For more information, refer to http://www.one-lab.net/ */

/* Data Handling Class */
#ifndef _CLS_H_
#define _CLS_H_

#include "config.h"
namespace ns {
	class cls {
		friend class clsList;

			rw_field(bool, PBool)

		public:
			static int field_count();
		protected:
			virtual int input_field(const QString& key, const QVariant& value, bool _set_value);
		private:
			int validate_field(const QString& key, const QVariant& value);
			int validate_field(int index, const QVariant& value);
			int input_field(int index, const QVariant& value, bool _set_value);
		public:
			virtual int to_json(QString& output);
			int from_json(const QString& output);
			int from_json(const QMap<QString, QVariant>& map);
			virtual int to_xml(QString& output, const QString& rowTag);
			virtual int to_sv(QString& output, const QString& spliter);
			int from_xml(const QDomElement& element, QHash<QString, QString>& values);
			int from_xml(const QString& input, const QString& rowTag);
			int from_sv(const QString& input, const QString& spliter);
		protected:
			inline bool compare_to(cls& aValue) const;
		public:
			inline void clone_from(cls& aValue);
			inline bool operator==(cls &aValue) const { return compare_to(aValue); }
			inline bool operator!=(cls &aValue) const { return !compare_to(aValue); }
			#ifdef _MSC_VER
				inline void operator=(cls &aValue) { clone_from(aValue); }
			#endif
		public:
			~cls();
			cls();
			cls(const bool& aPBool);
		public:
			void _invoke_(const QString& entry, const QString& input, QString& output);
	};//class cls
	class clsList {
		private:
			inline bool compare_to(clsList& aValue) const;
		public:
			QList<cls> Items;
			inline bool operator==(clsList& aValue) const { return compare_to(aValue); }
			inline bool operator!=(clsList& aValue) const { return !compare_to(aValue); }
			int to_json(QString& output, const QString& tag = "cls");
			int from_json(const QString& input, const QString& tag = "cls");
			int to_xml(QString& output, const QString& rowTag, const QString& tableTag);
			int from_xml(const QString& input, const QString& rowTag, const QString& tableTag);
			int to_sv(QString& output, const QString& spliter);
			int from_sv(const QString& input, const QString& spliter);
	};//class clsList
}//namespace ns

#endif