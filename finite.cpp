// finite.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "float.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddInX xai_finite(
	FunctionX(XLL_BOOLX, _T("?xll_finite"), _T("FINITE"))
	.Arg(XLL_DOUBLEX, _T("x"), _T("is a floating point number "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Determines whether the given double-precision floating-point value is finite by calling _finite()"))
	.Documentation(
	)
);
BOOL WINAPI
xll_finite(double x)
{
#pragma XLLEXPORT

	return TRUE == _finite(x);
}
