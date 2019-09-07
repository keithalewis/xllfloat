// finite.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddIn xai_finite(
	Function(XLL_BOOL, _T("?xll_finite"), _T("FINITE"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is a floating point number "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Determines whether the given double-precision floating-point value is finite by calling _finite()"))
	.Documentation(LR"(
        This function returns TRUE if x is either a normal or subnormal finite value. 
        It returns FALSE if the argument is infinite or a NaN. 
    )")
);
BOOL WINAPI
xll_finite(double x)
{
#pragma XLLEXPORT

	return TRUE == _finite(x);
}
