﻿/* This class framework is generated by Core Frame Builder. */
/* For more information, refer to http://www.one-lab.net/ */

/* Data Handling Class */
#ifndef _CLS_H_
#define _CLS_H_

#include "config.h"
#include "values.h"
namespace qtns {
	class cls {
		public:
			virtual bool FuncBool() = 0;
			virtual onelab::Bytes FuncBytes() = 0;
			virtual QDate FuncDate() = 0;
			virtual QDateTime FuncDateTime() = 0;
			virtual double FuncDouble() = 0;
			virtual float FuncFloat() = 0;
			virtual int FuncInt32() = 0;
			virtual QString FuncText() = 0;
			virtual QTime FuncTime() = 0;
			virtual unsigned int FuncUInt32() = 0;
		public:
			void _invoke_(const QString& entry, const QString& input, QString& output);
		};//interface cls
	}//namespace qtns

#endif