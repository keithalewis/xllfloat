// Author: gw2376
// error function
// Rename this file to xllerf.cpp and implement XLL.ERF which calls erf
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"
#include <math.h>       /* erf */
#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_erf(
	FunctionX(XLL_DOUBLE, _T("?xll_erf"), _T("XLL.ERF"))
	.Arg(XLL_DOUBLE, _T("X"), _T("is the valur of input in the erf."), _T("1"))
	.Category(CATEGORY)
	.FunctionHelp(_T("Computes the ERF values with respect to the input 'X'."))
	.Documentation(LR"(
In mathematics, the error function (also called the Gauss error function) is a special function (non-elementary) 
of sigmoid shape that occurs in probability, statistics, and partial differential equations describing diffusion.
	)")
);
double WINAPI
xll_erf(double X)
{
#pragma XLLEXPORT
	double se(1.0);

	se = erf(X); // or se(0,0)

	return se;
}

#ifdef _DEBUG

xll::test test_xll_erf([]() {
	double presult;
	double input = 0.5;

	presult = xll_erf(input);
	ensure(fabs(presult - 0.520499877813) < pow(10, -5));

	});

#endif // _DEBUG
