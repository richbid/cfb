﻿/* This class framework is generated by Core Frame Builder. */
/* For more information, refer to http://www.one-lab.net/ */

/* Data Handling Class */
using System;
using System.Text;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.IO;

namespace csns {
interface cls {
	//--------------------------------------------------------------------------------
	int FuncBool(ref Boolean aReturn);
	//--------------------------------------------------------------------------------
	int FuncBytes(ref onelab.Bytes aReturn);
	//--------------------------------------------------------------------------------
	int FuncDate(ref DateTime aReturn);
	//--------------------------------------------------------------------------------
	int FuncDateTime(ref DateTime aReturn);
	//--------------------------------------------------------------------------------
	int FuncDouble(ref Double aReturn);
	//--------------------------------------------------------------------------------
	int FuncFloat(ref Single aReturn);
	//--------------------------------------------------------------------------------
	int FuncInt32(ref Int32 aReturn);
	//--------------------------------------------------------------------------------
	int FuncText(ref String aReturn);
	//--------------------------------------------------------------------------------
	int FuncTime(ref DateTime aReturn);
	//--------------------------------------------------------------------------------
	int FuncUInt32(ref UInt32 aReturn);
	}//interface
}//namespace csns