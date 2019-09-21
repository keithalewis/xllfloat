#include "fmsroot1d_1.h"
#include "xll12//xll/xll.h"
#include<functional>
using namespace xll;
static AddIn xai_bisect(
	Function(XLL_FP, L"?xll_bisect", L"BISECT")
		.Arg(XLL_DOUBLE, L"x0", L"is the first arg.")
		.Arg(XLL_DOUBLE, L"x1", L"is the second arg.")
		.Arg(XLL_HANDLE, L"f", L"is the function.")
		.Category(L"ROOT1D")
		.FunctionHelp(L"Return next bisection guess.")
);
_FP12* WINAPI xll_bisect(double x0, double x1, HANDLEX f) {
#pragma XLLEXPORT
	static xll::FP12 se(1,2);
	std::function<double(double)> F = [f](double x) { return Excel(xlUDF, OPER(f), OPER(x)); };
	std::pair<double,double> p= fms::bisect(x0, x1,F);
	se[0] = p.first;
	se[1] = p.second;
	return se.get();
}

static AddIn kahan_a(
	Function(XLL_DOUBLE, L"?xll_kahan_a", L"KAHAN.A")
		.Arg(XLL_DOUBLE, L"x0", L"is the first arg.")
		.Arg(XLL_HANDLE, L"f", L"is the function.")
		.Category(L"ROOT1D")
		.FunctionHelp(L"Return next bisection guess.")
);
double xll_kahan_a(double x0) {
#pragma XLLEXPORT
	return x0 - pow(x0, 4) + 1;
}