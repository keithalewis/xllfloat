// Author: xh2443
// returns e raised to the given power, minus one (ex-1)
// Rename this file to xllexpm1.cpp and implement XLL.EXPM1 which calls expm1
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_expm1(
	FunctionX(XLL_DOUBLE, _T("?xll_expm1"), _T("XLL.EXPM1"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is the floating."))
	.Category(CATEGORY)
	.FunctionHelp(_T("Computes e raised to the given power, minus one."))
	.Documentation(LR"("Computes e raised to the given power, minus one."
	)")
);
double WINAPI
xll_expm1(double x)
{
#pragma XLLEXPORT

	return expm1(x);
}

#ifdef _DEBUG

xll::test test_xll_expm1([]() {
	double presult;
	double param = 1e-20;
	presult = xll_expm1(param);
	ensure(presult == 1e-20);
	});

#endif // _DEBUG 