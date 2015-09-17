// popcount.cpp - count nonzero bits
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "popcount.h"
#include "float.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddInX xai_popcount0(
	FunctionX(XLL_LONGX, _T("?xll_popcount0"), _T("POPCOUNT0"))
	.Arg(XLL_LONGX, _T("Integer"), _T("is an integer "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Hamming weight of Integer best for small number of 1 bits"))
);
LONG WINAPI
xll_popcount0(LONG l)
{
#pragma XLLEXPORT

	return popcount0<LONG>(l);
}

static AddInX xai_popcount1(
	FunctionX(XLL_LONGX, _T("?xll_popcount1"), _T("POPCOUNT1"))
	.Arg(XLL_LONGX, _T("Integer"), _T("is an integer "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Hamming weight of Integer best for small number of 0 bits"))
);
LONG WINAPI
xll_popcount1(LONG l)
{
#pragma XLLEXPORT

	return popcount1<LONG>(l);
}

static AddInX xai_popcountl(
	FunctionX(XLL_LONGX, _T("?xll_popcountl"), _T("POPCOUNT.INT"))
	.Arg(XLL_LONGX, _T("Integer"), _T("is an integer "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Returns the Hamming weight of 32-bit integer Int"))
	.Documentation(_T("The Hamming weight is the number of 1 bits in the base 2 representation"))
);
LONG WINAPI
xll_popcountl(LONG l)
{
#pragma XLLEXPORT

	return popcount<unsigned int>(l);
}

static AddInX xai_popcount(
	FunctionX(XLL_LONGX, _T("?xll_popcount"), _T("POPCOUNT.NUM"))
	.Arg(XLL_DOUBLEX, _T("Num"), _T("is a floating point number "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Returns the Hamming weight of 64-bit floating point Num. It is the number of 1 bits in the base 2 representation"))
	.Documentation(_T("The Hamming weight is the number of 1 bits in the base 2 representation. "))
);
LONG WINAPI
xll_popcount(double x)
{
#pragma XLLEXPORT

	return popcount<double>(x);
}
