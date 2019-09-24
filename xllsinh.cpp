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
	FunctionX(XLL_DOUBLE, _T("?xll_sinh"), _T("XLL.SINH"))
	.Arg(XLL_DOUBLE, _T("value"), _T("is the input value."), _T("0"))
	.Category(CATEGORY)
	.FunctionHelp(_T("Computes the hyperbolic sine of the input value"))
	.Documentation(LR"(
Computes the the hyperbolic sine of one value, and stores an integer value with the sign 
and approximate magnitude of the result in a location that's specified in a parameter.
	)")
);

double WINAPI
xll_sinh(double value)
{
#pragma XLLEXPORT
	double se(1.0);

	se = sinh(value); // or se(0,0)

	return se;
}

#ifdef _DEBUG

xll::test test_xll_sinh([]() {
	double presult;
	double value = 0;
	presult = xll_sinh(value);
	ensure(presult == 0);
	});

#endif // _DEBUG 