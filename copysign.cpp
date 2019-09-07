// copysign.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddIn xai_copysign(
	Function(XLL_DOUBLE, _T("?xll_copysign"), _T("COPYSIGN"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is a floating point number"))
	.Arg(XLL_DOUBLE, _T("y"), _T("is a floating point number "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Returns x with the sign of y by calling _copysign()"))
	.Documentation(LR"(
        The copysign functions return a floating-point value that combines the magnitude of
        <codeInline>x</codeInline> and the sign of <codeInline>y</codeInline>. 
        There is no error return.
        Note <codeInline>x == copysign(x,y)</codeInline> is true if 
        <codeInline>x</codeInline> and <codeInline>y</codeInline> have the same sign.
    )")
);
double WINAPI
xll_copysign(double x, double y)
{
#pragma XLLEXPORT

	return _copysign(x, y);
}
