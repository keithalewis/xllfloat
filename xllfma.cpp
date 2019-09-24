// Author: ge2247
// fused multiply-add operation
// Rename this file to xllfma.cpp and implement XLL.FMA which calls fma
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_fma(
	FunctionX(XLL_DOUBLE, _T("?xll_fma"), _T("XLL.FMA"))
	.Arg(XLL_DOUBLE, _T("a"), _T("is the first input."), _T("10"))
	.Arg(XLL_DOUBLE, _T("b"), _T("is the second input."), _T("20"))
	.Arg(XLL_DOUBLE, _T("c"), _T("is the third input."), _T("30"))
	.Category(CATEGORY)
	.FunctionHelp(_T("Computes the sum of the product of the first and second inputs and the third input.\n\n a*b+c"))
	.Documentation(LR"(
Computes the sum of the product of the first and second inputs and the third inputs (Fused Multiply-Add)
Given three inputs a, b, and c, the function computes a * b + c without loss of precision in any intermediate step.
)")
);

double WINAPI
xll_fma(double a, double b, double c)
{
#pragma XLLEXPORT
	double se(1.0);

	se = fma(a, b, c);

	return se;
}

#ifdef _DEBUG

xll::test test_xll_fma([]() {
	double presult;
	double one = 10;
	double two = 20;
	double three = 30;
	presult = xll_fma(one, two, three);
	ensure(presult == 230);
	});

#endif // _DEBUG
