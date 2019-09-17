// Author: ts3157
// hyperbolic tangent
// Rename this file to xlltanh.cpp and implement XLL.TANH which calls tanh
// Add documentation and a test function that runs in debug mode.
// tanh.c - calls corresponding C library function
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"
#include <cmath>
#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_tanh(
	FunctionX(XLL_FP, _T("?xll_tanh"), _T("XLL.TANH"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is a floating point number "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Returns tanh(x)"))
	.Documentation(LR"(Computes the hyperbolic tangent of x)")
);
_FP12* WINAPI
xll_tanh(double x)
{
#pragma XLLEXPORT
	static xll::FP12 se(1, 1);
	
	se[0]= tanh(x);
	//se[1] = exp;

	return se.get();
}

#if _DEBUG
xll::test test_xll_tanh([]() {
	_FP12* presult;
	double x = 1;
	presult = xll_tanh(x);
	ensure(presult->array[0] == std::tanh(1));
	});
#endif