// Author: sf3000
// smaller of two floating point values
// Rename this file to xllfmin.cpp and implement XLL.FMIN which calls fmin
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"
#include <algorithm>

#ifndef CATEGORY
#define CATEGORY "Float"
#endif


using namespace xll;

static AddInX xai_fmin(
	FunctionX(XLL_DOUBLE, _T("?xll_fmin"), _T("XLL.FMIN"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is the first input floating point value."), _T("1.1"))
	.Arg(XLL_DOUBLE, _T("y"), _T("is the second input floating point value."), _T("3.22"))
	.Category(CATEGORY)
	.FunctionHelp(_T("Computes the smaller of two floating point values."))
	.Documentation(LR"(
		Returns the smaller of two floating point values.
	)")
);


double WINAPI
xll_fmin(double x, double y) 
{
#pragma XLLEXPORT
	return std::min(x, y);
}

#if _DEBUG

xll::test test_xll_fmin([]() {
	double x = 1.1;
	double y = 3.22;
	double result = xll_fmin(x, y);
	ensure(fabs(result-1.1)<=1e-6);
});

#endif // _DEBUG





