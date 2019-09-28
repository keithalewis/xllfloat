// Author: mw3302
// complementary error function
// Rename this file to xllerfc.cpp and implement XLL.ERFC which calls erfc
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_erfc(
	FunctionX(XLL_DOUBLE, _T("?xll_erfc"), _T("XLL.ERFC"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is the number."), _T("0"))
	.Category(CATEGORY)
	.FunctionHelp(_T("Computes complementary error function."))
	.Documentation(LR"(
Return the complementary Gauss error function of x.
	)")
);
double WINAPI
xll_erfc(double x)
{
#pragma XLLEXPORT
  return erfc(x);
}

#ifdef _DEBUG

xll::test test_xll_erfc([]() {
	double presult;
	double numer = 0;
	presult = xll_erfc(numer);
	ensure(presult == 1);
	});

#endif // _DEBUG
