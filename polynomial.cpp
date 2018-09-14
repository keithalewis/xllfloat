// polynomial.cpp evaluate a polynomial
#include "xll12/xll/xll.h"

using namespace xll;

AddIn xai_polynomial(
    Function(XLL_DOUBLE, L"?xll_polynomial", L"POLYNOMIAL")
    .Arg(XLL_FP, L"coefficients", L"is an array of polynomial coefficients.")
    .Arg(XLL_DOUBLE, L"x", L"is the value at which to evaluate the polynomial.")
    .FunctionHelp(L"Returns c[0] + c[1]*x + c[2]*x^2 + ... where c is the array of coefficients")
    .Category(L"XLL")
);
double WINAPI xll_polynomial(const _FP12* pc, double x)
{
#pragma XLLEXPORT
    double result = 0;

    auto n = size(*pc);
    for (int i = 1; i <= n; ++i) {
        result = pc->array[n - i] + x * result; // Horner method
    }

    return result;
}