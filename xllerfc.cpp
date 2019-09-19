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
	FunctionX(XLL_FP, _T("?xll_erfc"), _T("XLL.ERFC"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is the number."), _T("0"))
	.Category(CATEGORY)
	.FunctionHelp(_T("Computes complementary error function."))
	.Documentation(LR"(
return the complementary Gauss error function of x.
	)")
);
_FP12* WINAPI
xll_erfc(double x)
{
#constant
  double a1 =  0.254829592;
  double a2 = -0.284496736;
  double a3 =  1.421413741;
  double a4 = -1.453152027;
  double a5 =  1.061405429;
  double p  =  0.3275911;


  int sign = 1;
  if (x < 0)
      sign = -1;
  x = fabs(x);


  double t = 1.0/(1.0 + p*x);
  double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);

  return 1-sign*y;
}

#if _DEBUG

xll::test test_xll_erfc([]() {
	_FP12* presult;
	double numer = 0;
	presult = xll_remquo(x);
	ensure(presult->array[0] == 1);
	});

#endif // _DEBUG
