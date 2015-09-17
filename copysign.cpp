// copysign.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "float.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddInX xai_copysign(
	FunctionX(XLL_DOUBLEX, _T("?xll_copysign"), _T("COPYSIGN"))
	.Arg(XLL_DOUBLEX, _T("x"), _T("is a floating point number"))
	.Arg(XLL_DOUBLEX, _T("y"), _T("is a floating point number "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Returns x with the sign of y by calling _copysign()"))
	.Documentation(
	)
);
double WINAPI
xll_copysign(double x, double y)
{
#pragma XLLEXPORT

	return _copysign(x, y);
}
