// Author: ml4403
// raises a number to the given power (xy)
// Rename this file to xllpow.cpp and implement XLL.POW which calls pow
// Add documentation and a test function that runs in debug mode.
// copysign.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddIn xai_pow(
	Function(XLL_DOUBLE, _T("?xll_pow"), _T("POW"))
	.Arg(XLL_DOUBLE, _T("x"), _T("the number to be raised"))
	.Arg(XLL_DOUBLE, _T("y"), _T("The power that it raise to "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Returns x raised to the power of y"))
	.Documentation(LR"(
		The pow function returns the x raised to the power of y
		There is no error return.
        
    )")
);
double WINAPI
xll_pow(double x, double y)
{
#pragma XLLEXPORT

	return pow(x, y);
}

#if _DEBUG
xll::test test_xll_pow([]() {
	double base = 9;
	double power = 2;
	double presult = xll_pow(base, power);
	ensure(presult == 81);
	});

#endif // DEBUG