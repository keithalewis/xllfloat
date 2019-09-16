// Author: rl3107
// computes sine (sin(x))
// Rename this file to xllsin.cpp and implement XLL.SIN which calls sin
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddIn xai_sin(
	Function(XLL_DOUBLE, _T("?xll_sin"), _T("XLL.SIN"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is a floating number."))
	.FunctionHelp(_T("Returns sin(x)"))
	.Category(CATEGORY)
	.Documentation(LR"(
        Evaluates the sin(x) using the Horner method.
    )")
);
double WINAPI
xll_sin(double x)
{
#pragma XLLEXPORT

	return sin(x);
}

#if _DEBUG

xll::test test_xll_sin([]() {
	double presult;
	double x = 0;
	presult = xll_sin(x);
	ensure(presult == 0);
	});

#endif // _DEBUG
