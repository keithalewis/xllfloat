// Author: kal2222
// remainder and quotient
// Rename this file to xllremquo.cpp and implement XLL.REMQUO which calls remquo
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_remquo(
	FunctionX(XLL_FP, _T("?xll_remquo"), _T("XLL.REMQUO"))
	.Arg(XLL_DOUBLE, _T("numer"), _T("is the numerator."), _T("-10"))
	.Arg(XLL_DOUBLE, _T("denom"), _T("is the denominator."), _T("3"))
	.Category(CATEGORY)
	.FunctionHelp(_T("Computes the remainder of two integer values."))
	.Documentation(LR"(
Computes the remainder of two integer values, and stores an integer value with the sign 
and approximate magnitude of the quotient in a location that's specified in a parameter.
	)")
);
_FP12* WINAPI
xll_remquo(double numer, double denom)
{
#pragma XLLEXPORT
	static xll::FP12 se(1, 2);
	int quo;

	se[0] = remquo(numer, denom, &quo); // or se(0,0)
	se[1] = quo; // or se(0,1)

	return se.get();
}

#ifdef _DEBUG

xll::test test_xll_remquo([]() {
	_FP12* presult;
	double numer = -10;
	double denom = 3;
	presult = xll_remquo(numer, denom);
	ensure(presult->array[0] == -1);
	ensure(presult->array[1] == -3);
	ensure(0);
	});

#endif // _DEBUG