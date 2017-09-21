// popcount.cpp - count nonzero bits
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "popcount.h"
#include "float.h"

#ifdef _DEBUG
#include <random>

std::minstd_rand r;

template<class I>
I slow_popcount(I i)
{
    I count = 0;

    for (I j = i; j; ++count)
        j &= j - 1;

    return count;
}
template<class I>
void test_popcount(void)
{
    r.seed(std::random_device()());

    for (int n = 0; n < 100; ++n) {
        I i = r(); // uint32_t
        I c0 = slow_popcount(i);
        I c1 = popcount(i);
        ensure (c0 == c1);
    }
}

xll::test xll_test_popcount(test_popcount<uint32_t>);
#endif // _DEBUG

#if 0
#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddIn xai_popcount0(
	Function(XLL_LONG, _T("?xll_popcount0"), _T("POPCOUNT0"))
	.Arg(XLL_LONG, _T("Integer"), _T("is an integer "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Hamming weight of Integer best for small number of 1 bits"))
);
LONG WINAPI
xll_popcount0(LONG l)
{
#pragma XLLEXPORT

	return popcount0<LONG>(l);
}

static AddIn xai_popcount1(
	Function(XLL_LONG, _T("?xll_popcount1"), _T("POPCOUNT1"))
	.Arg(XLL_LONG, _T("Integer"), _T("is an integer "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Hamming weight of Integer best for small number of 0 bits"))
);
LONG WINAPI
xll_popcount1(LONG l)
{
#pragma XLLEXPORT

	return popcount1<LONG>(l);
}

static AddIn xai_popcountl(
	Function(XLL_LONG, _T("?xll_popcountl"), _T("POPCOUNT.INT"))
	.Arg(XLL_LONG, _T("Integer"), _T("is an integer "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Returns the Hamming weight of 32-bit integer Int"))
	.Documentation(_T("The Hamming weight is the number of 1 bits in the base 2 representation"))
);
LONG WINAPI
xll_popcountl(LONG l)
{
#pragma XLLEXPORT

	return popcount(l);
}

static AddIn xai_popcount(
	Function(XLL_LONG, _T("?xll_popcount"), _T("POPCOUNT.NUM"))
	.Arg(XLL_DOUBLE, _T("Num"), _T("is a floating point number "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Returns the Hamming weight of 64-bit floating point Num. It is the number of 1 bits in the base 2 representation"))
	.Documentation(_T("The Hamming weight is the number of 1 bits in the base 2 representation. "))
);
LONG WINAPI
xll_popcount(double x)
{
#pragma XLLEXPORT

	return popcount(x);
}
#endif // 0