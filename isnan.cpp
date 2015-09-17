// isnan.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "float.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddInX xai_isnan(
	FunctionX(XLL_BOOLX, _T("?xll_isnan"), _T("ISNAN"))
	.Arg(XLL_DOUBLEX, _T("x"), _T("is a floating point number "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Determines whether the given double-precision floating-point value is Not a Number by calling _isnan()"))
	.Documentation(
		_T("In floating point calculation, NaN (Not a Number) is a value of the numeric data type representing an undefined or unrepresentable value. ")
	)
);
BOOL WINAPI
xll_isnan(double x)
{
#pragma XLLEXPORT

	return TRUE == _isnan(x);
}

static AddInX xai_nan(
	FunctionX(XLL_FPX, _T("?xll_nan"), _T("NAN"))
	.Category(CATEGORY)
	.FunctionHelp(_T("Returns a floating point number representing Not A Number."))
	.Documentation(
		_T("In floating point calculation, NaN (Not a Number) is a value of the numeric data type representing an undefined or unrepresentable value. ")
	)
);
xfp* WINAPI
xll_nan(void)
{
#pragma XLLEXPORT
	static xfp x;

	x.rows = 1;
	x.columns = 1;
	x.array[0] = std::numeric_limits<double>::quiet_NaN();

	return &x;
}

