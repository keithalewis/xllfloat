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
	.FunctionHelp(_T("Reverses the sign of x by calling _chgsign()."))
	.Documentation(LR"(
        The _chgsign functions return a value that's equal to the floating-point argument x, 
        but with its sign reversed. There is no error return.
    )")
);
double WINAPI
xll_chgsign(double x)
{
#pragma XLLEXPORT

	return _chgsign(x);
}
