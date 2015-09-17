// float.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "float.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddInX xai_logb(
	FunctionX(XLL_DOUBLEX, _T("?xll_logb"), _T("LOGB"))
	.Arg(XLL_DOUBLEX, _T("x"), _T("is a floating point number "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Return log of fabs(x) using radix of the machine's floating point arithmetic using _logb()"))
	.Documentation(
	)
);
double WINAPI
xll_logb(double x)
{
#pragma XLLEXPORT

	return _logb(x);
}
