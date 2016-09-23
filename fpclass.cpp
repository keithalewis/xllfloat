// fpclass.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "float.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddInX xai_FP12class(
	FunctionX(XLL_LONG, _T("?XLL_FPclass"), _T("FPCLASS"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is a floating point number "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Determine the floating point class of x by calling _FP12class()"))
	.Documentation(
/*		_T("Uses the values from the <codeInline>FPCLASS_*</codeInline> enumeration")
		,
		xml::xlink(_T("Float Constants"))
*/	)
);
LONG WINAPI
XLL_FPclass(double x)
{
#pragma XLLEXPORT

	return _fpclass(x);
}
