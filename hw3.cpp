// hw3.cpp
#include "fmsroot1d.h"
#include "xll12/xll/xll.h"

using namespace fms::root1d;
using namespace xll;

static AddIn xai_udf(
	Function(XLL_DOUBLE, L"?xll_udf", L"XLL.UDF")
	.Arg(XLL_HANDLE, L"f", L"is a handle to the user defined function to call.")
	.Arg(XLL_DOUBLE, L"x", L"is the argument to the function.")
	.Uncalced()
	.Category(L"XLL")
	.FunctionHelp(L"Call a user defined function with an argument.")
);
double WINAPI xll_udf(HANDLEX f, double x)
{
#pragma XLLEXPORT
	return Excel(xlUDF, OPER(f), OPER(x));
}

static AddIn xai_bisect(
	Function(XLL_FP, L"?xll_bisect", L"BISECT")
	.Arg(XLL_HANDLE, L"f", L"is the function.")
	.Arg(XLL_DOUBLE, L"x0", L"is the lower bracket.")
	.Arg(XLL_DOUBLE, L"x1", L"is the upper bracket.")
	.Category(L"ROOT1D")
	.FunctionHelp(L"Return the next bracket for the root.")
);
_FP12* WINAPI xll_bisect(HANDLEX f, double x0, double x1)
{
#pragma XLLEXPORT
	static xll::FP12 result(1, 2); // 1 x 2 array of doubles

	try {
		ensure(x0 <= x1);

		std::function<double(double)> F = [f](double x) { 
			return Excel(xlUDF, OPER(f), OPER(x)); 
		};
		std::pair<double, double> p = bisect(F, x0, x1);

		result[0] = p.first;
		result[1] = p.second;
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());

		return 0; // shows as #NUM! in Excel
	}

	return result.get();
}

//!!! implement FALSE.POSITION
static AddIn xai_false_position(
	Function(XLL_FP, L"?xll_false_position", L"FALSE_POSITION")
	.Arg(XLL_HANDLE, L"f", L"is the function.")
	.Arg(XLL_DOUBLE, L"x0", L"is the lower bracket.")
	.Arg(XLL_DOUBLE, L"x1", L"is the upper bracket.")
	.Category(L"ROOT1D")
	.FunctionHelp(L"Return the next bracket for the root.")
);
_FP12* WINAPI xll_false_position(HANDLEX f, double x0, double x1)
{
#pragma XLLEXPORT
	static xll::FP12 result(1, 2); // 1 x 2 array of doubles

	try {
		ensure(x0 <= x1);

		std::function<double(double)> F = [f](double x) {
			return Excel(xlUDF, OPER(f), OPER(x));
		};
		std::pair<double, double> p = false_positio(F, x0, x1);

		result[0] = p.first;
		result[1] = p.second;
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());

		return 0; // shows as #NUM! in Excel
	}

	return result.get();
}
// See https://www.hpl.hp.com/hpjournal/pdfs/IssuePDFs/1979-12.pdf Fig. 6 page 24.

static AddIn xai_kahan_a(
	Function(XLL_DOUBLE, L"?xll_kahan_a", L"KAHAN.A")
	.Arg(XLL_DOUBLE, L"x", L"is the argument.")
	.Category(L"XLL")
	.FunctionHelp(L"Evaluate 6 x - x^4 - 1.")
);
double WINAPI xll_kahan_a(double x)
{
#pragma XLLEXPORT
	return 6 * x - pow(x, 4) - 1;
}

//!!! Implement KAHAN.B for Fig. 6 example (b) 	
static AddIn xai_kahan_b(
	Function(XLL_DOUBLE, L"?xll_kahan_b", L"KAHAN.B")
	.Arg(XLL_DOUBLE, L"x", L"is the argument.")
	.Category(L"XLL")
	.FunctionHelp(L"Evaluate exp(6x - x^4 - 1) - 1.")
);
double WINAPI xll_kahan_b(double x)
{
#pragma XLLEXPORT
	return exp(6 * x - pow(x, 4) - 1) - 1;
}
//!!! Implement KAHAN.C for Fig. 6 example (c) 	
static AddIn xai_kahan_c(
	Function(XLL_DOUBLE, L"?xll_kahan_c", L"KAHAN.C")
	.Arg(XLL_DOUBLE, L"x", L"is the argument.")
	.Category(L"XLL")
	.FunctionHelp(L"Evaluate ln(6x - x^4).")
);
double WINAPI xll_kahan_c(double x)
{
#pragma XLLEXPORT
	return log(6*x - pow(x,4));
}
