// Author: bjs2205
// computes hyperbolic cosine (ch(x))
// Rename this file to xllcosh.cpp and implement XLL.COSH which calls cosh
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_cosh(
	FunctionX(XLL_FP, _T("?xll_cosh"), _T("XLL.COSH"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is x within cosh(x)."), _T("0"))
	.Category(CATEGORY)
	.FunctionHelp(_T("Computes the hyperbolic cosine."))
	.Documentation(LR"(Computes the hyperbolic cosine.)")
);
_FP12* WINAPI
xll_cosh(double x)
{
#pragma XLLEXPORT
	static xll::FP12 se(1, 1);

	se[0] = cosh(x);

	return se.get();
}

#if _DEBUG

xll::test test_xll_cosh([]() {
	_FP12* presult;
	double x = 0;
	presult = xll_cosh(x);
	ensure(presult->array[0] == 1);
	});

#endif // _DEBUG