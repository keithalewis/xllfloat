// popcount.cpp - count nonzero bits
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "popcount.h"
#include "xllfloat.h"

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

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

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

    union {
        int64_t l;
        double x;
    } u;
    u.x = x;

	return static_cast<LONG>(popcount(u.l));
}
