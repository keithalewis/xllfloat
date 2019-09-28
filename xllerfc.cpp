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
return the complementary Gauss error function of x.
	)")
);
double WINAPI
xll_erfc(double x)
{
#pragma XLLEXPORT
  double alpha1 =  0.2548295;
  double alpha2 = -0.2844967;
  double alpha3 =  1.4214137;
  double alpha4 = -1.4531520;
  double alpha5 =  1.0614054;
  double beta  =  0.3275911;


  int sign = 1;
  if (x < 0)
      sign = -1;
  x = fabs(x);


  double z = 1.0/(1.0 + beta*x);
  double y = 1.0 - (((((alpha5*z + alpha4)*z) + alpha3)*z + alpha2)*z + alpha1)*z*exp(-x*x);
  double anw = 1.0 - sign * y;
  return anw;
}

#ifdef _DEBUG

xll::test test_xll_erfc([]() {
	double presult;
	double numer = 0;
	presult = xll_erfc(numer);
	ensure(presult == 1);
	});

#endif // _DEBUG
