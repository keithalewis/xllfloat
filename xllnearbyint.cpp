// Author: cz2573
// nearest integer using current rounding mode
// Rename this file to xllnearbyint.cpp and implement XLL.NEARBYINT which calls nearbyint
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_nearbyint(
	FunctionX(XLL_DOUBLE, _T("?xll_nearbyint"), _T("XLL.NEARBYINT"))
	.Arg(XLL_DOUBLE, _T("X"), _T("is the input number."))
	.Category(CATEGORY)
	.FunctionHelp(_T("Return the nearest integer value to arg, according to the current rounding mode, is returned."))
	.Documentation(LR"(
Return the nearest integer value to arg, according to the current rounding mode.
	)")
);
int WINAPI
xll_nearbyint(double value_input)
{
#pragma XLLEXPORT
	/*Since the input data is double while output is integer, warning 4244 will always interupt the compilation.
	Hence warning is disabled to ensure the compilation could proceed without interuption.*/
#pragma warning(push)
#pragma warning(disable:4244)
	int result = nearbyint(value_input);
	return result;
#pragma warning(pop)
}

#if _DEBUG

xll::test test_xll_nearbyint([]() {
	int result;
	double value_input = 14.3;
	result = xll_nearbyint(value_input);
	ensure(result == 14);
	});

#endif // _DEBUG