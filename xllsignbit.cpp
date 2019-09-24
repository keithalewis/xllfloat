// Author: jz3198
// checks if the given number is negative
// Rename this file to xllsignbit.cpp and implement XLL.SIGNBIT which calls signbit
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddIn xai_signbit(
	Function(XLL_DOUBLE, _T("?xll_signbit"), _T("XLL.SIGNBIT"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is a floating point number."))
	.Category(CATEGORY)
	.FunctionHelp(_T("Reverses the sign of x by calling _signbit()"))
	.Documentation(LR"(
        The signbit functions return a value that's equal to the floating-point argument x, 
        Nonzero integral value if arg is negative, 0 otherwise. There is no error return.
    )")
);
double WINAPI
xll_signbit(double x)
{
#pragma XLLEXPORT

	return signbit(x);
}

#ifdef _DEBUG

xll::test test_xll_signbit([]() {
_FP12* presult;
	double input = -3.0;

	presult = xll_signbit(input);
	ensure(presult->array[0] == 0);

	});

#endif // _DEBUG
