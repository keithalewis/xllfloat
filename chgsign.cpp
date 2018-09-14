// chgsign.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "float.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddIn xai_chgsign(
	Function(XLL_DOUBLE, _T("?xll_chgsign"), _T("CHGSIGN"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is a floating point number."))
	.Category(CATEGORY)
	.FunctionHelp(_T("Reverses the sign of x by calling _chgsign()"))
	.Documentation(
	)
);
double WINAPI
xll_chgsign(double x)
{
#pragma XLLEXPORT

	return _chgsign(x);
}
