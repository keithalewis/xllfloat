// Author: lz2735
// decomposes a number into integer and fractional parts
// Rename this file to xllmodf.cpp and implement XLL.MODF which calls modf
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;
static AddIn xai_modf(
	Function(XLL_FP, _T("?xll_modf"), _T("XLL.MODF"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is a floating point number."))
	.Category(CATEGORY)
	.FunctionHelp(_T("Decomposes a number into integer and fractional parts"))
	.Documentation(LR"(
        The _modf functions return an array with two elements that are the integer part of the number and the fractional part of the number. There is no error return.
    )")
);
_FP12* WINAPI
xll_modf(double x)
{
#pragma XLLEXPORT
	double intpart, fractpart;
	static xll::FP12 result(1, 2);
	fractpart = modf(x, &intpart);
	result[0] = intpart;
	result[1] = fractpart;
	return result.get();
}
#ifdef _DEBUG

xll::test test_xll_modf([]() {
	double param = 2.35;
	ensure((xll_modf(param)->array[0] == 2) && (xll_modf(param)->array[1] == 0.35));
	});
#endif 




