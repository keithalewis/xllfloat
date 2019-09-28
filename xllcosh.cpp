// Author: bjs2205
// computes hyperbolic cosine (ch(x))
// Rename this file to xllcosh.cpp and implement XLL.COSH which calls cosh
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h" // this includes the xllfloat.h header file that was given to us that makes the declarations all of our .cpp files will use

#ifndef CATEGORY // checks whether the token "CATEGORY" has been defined earlier 
#define CATEGORY "Float" // if not defines CATEGORY as float
#endif

using namespace xll; // uses the xll namespace to eliminate neccessity of writing xll::function

static AddInX xai_cosh( // create a static function which 
	FunctionX(XLL_DOUBLE, _T("?xll_cosh"), _T("XLL.COSH"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is x within cosh(x)."), _T("0"))
	.Category(CATEGORY)
	.FunctionHelp(_T("Computes the hyperbolic cosine."))
	.Documentation(LR"(Computes the hyperbolic	cosine.)")
);

double WINAPI
xll_cosh(double x)
{
#pragma XLLEXPORT
	double se;
	se = cosh(x);

	return se;
}

#ifdef _DEBUG

xll::test test_xll_cosh([]() {
	double presult;
	double x = 0;
	presult = xll_cosh(x);
	ensure(presult == 1);
	});

#endif // _DEBUG