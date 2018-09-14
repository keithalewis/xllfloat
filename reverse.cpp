// reverse.cpp - reverse elements of an array
#include <algorithm>
#include "xll12/xll/xll.h"

using namespace xll;

AddIn xai_reverse(
    Function(XLL_FP, L"?xll_reverse", L"REVERSE")
    .Arg(XLL_FP, L"array", L"is an array of numbers.")
    .FunctionHelp(L"Reverse an array of numbers.")
    .Category(L"XLL")
);
_FP12* WINAPI xll_reverse(_FP12* pa)
{
#pragma XLLEXPORT

    std::reverse(begin(*pa), end(*pa));

    return pa;
}