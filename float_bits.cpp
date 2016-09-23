// float_bits.cpp - floating point bits
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "float.h"

#ifndef CATEGORY
#define CATEGORY L"Float"
#endif

using namespace xll;

static AddIn xai_float_bits(
	Function(XLL_FP, L"?xll_float_bits", L"FLOAT.BITS")
	.Arg(XLL_DOUBLE, L"Num", L"is a floating point number ")
	.Category(CATEGORY)
	.FunctionHelp(L"Returns 1 x 64 array of the bits of the floating point Number")
	.Documentation(
	
	)
);
xfp* WINAPI
xll_float_bits(double x)
{
#pragma XLLEXPORT
	static xll::FP12 b(1, 64);

	union { double x; long long l; } u;
	u.x = x;

	for (unsigned short i = 0; i < 64; ++i)
		b[63 - i] = (u.l>>i)&1 ? 1 : 0;

	return b.get();
}

static AddIn xai_bits_float(
	Function(XLL_DOUBLE, L"?xll_bits_float", L"BITS.FLOAT")
	.Arg(XLL_FP, L"Bits", L"is an array of 64 bits ")
	.Category(CATEGORY)
	.FunctionHelp(L"Converts array of 64 bits to a floating point Number")
	.Documentation(
	
	)
);
double WINAPI
xll_bits_float(const _FP12* pb)
{
#pragma XLLEXPORT

	union { double x; long long l; } u;

	try {
		ensure (size(*pb) != 64);
	}
	catch (const std::exception& ex) {
		XLL_INFO(ex.what());

		return std::numeric_limits<double>::quiet_NaN();
	}

	u.l = 0;
	for (xword i = 0; i < 64; ++i)
		if (pb->array[63 - i] != 0)
			u.l |= (1ll<<i);

	return u.x;
}