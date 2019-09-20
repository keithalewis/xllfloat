// Author: ct2966
// computes the inverse hyperbolic cosine (arcosh(x))
// Rename this file to xllacosh.cpp and implement XLL.ACOSH which calls acosh
// Add documentation and a test function that runs in debug mode.



// chgsign.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddIn xai_arcosh(
	Function(XLL_DOUBLE, _T("?xll_arcosh"), _T("ARCOSH"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is a floating point number."))
	.Category(CATEGORY)
	.FunctionHelp(_T("computes the inverse hyperbolic cosine (arcosh(x)) by calling acosh()"))
	.Documentation(LR"(
        The _arcosh functions return a value that's the inverse hyperbolic cosine (arcosh(x))
    )")
);
double WINAPI
xll_arcosh(double x)
{
#pragma XLLEXPORT

	return acosh(x);
}


#if _DEBUG


xll::test test_xll_arcosh([]()
	{

		double input = 1.000;
		double result = xll_arcosh(input);

		ensure(result == 0.0000);
	});

#endif // _DEBUG
