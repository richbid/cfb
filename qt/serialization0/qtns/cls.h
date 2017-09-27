﻿/* This class framework is generated by Core Frame Builder. */
/* For more information, refer to http://www.one-lab.net/ */

/* Data Handling Class */
#ifndef _CLS_H_
#define _CLS_H_

#include "config.h"
#include "values.h"
namespace qtns {
	class cls {
			rw_field(bool, PBool)

			rw_field(onelab::Bytes, PBytes)

			rw_field(QDate, PDate)

			rw_field(QDateTime, PDateTime)

			rw_field(double, PDouble)

			rw_field(float, PFloat)

			rw_field(int, PInt32)

			rw_field(QString, PText)

			rw_field(QTime, PTime)

			rw_field(unsigned int, PUInt32)

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
			cls(const bool& aPBool, const onelab::Bytes& aPBytes, const QDate& aPDate, const QDateTime& aPDateTime, const double& aPDouble, const float& aPFloat, const int& aPInt32, const QString& aPText, const QTime& aPTime, const unsigned int& aPUInt32);
		public:
			void _invoke_(const QString& entry, const QString& input, QString& output);
	};//class cls
}//namespace qtns

#endif