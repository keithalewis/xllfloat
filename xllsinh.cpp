// Author: cr2771
// computes hyperbolic sine (sh(x))
// Rename this file to xllsinh.cpp and implement XLL.SINH which calls sinh
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_sinh(
	FunctionX(XLL_FP, _T("?xll_sinh"), _T("XLL.SINH"))
	.Arg(XLL_DOUBLE, _T("value"), _T("is the input value."), _T("0"))
	.Category(CATEGORY)
	.FunctionHelp(_T("Computes the hyperbolic sine of the input value"))
	.Documentation(LR"(
Computes the the hyperbolic sine of one value, and stores an integer value with the sign 
and approximate magnitude of the result in a location that's specified in a parameter.
	)")
);

_FP12* WINAPI
xll_sinh(double value)
{
#pragma XLLEXPORT
	static xll::FP12 se(1, 1);

	se[0] = sinh(value); // or se(0,0)

	return se.get();
}

#if _DEBUG

xll::test test_xll_sinh([]() {
	_FP12* presult;
	double value = 0;
	presult = xll_sinh(value);
	ensure(presult->array[0] == 0);
	});

#endif // _DEBUG