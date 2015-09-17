// popcount.cpp - count nonzero bits
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "popcount.h"
#include "float.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddInX xai_float_bits(
	FunctionX(XLL_FPX, _T("?xll_float_bits"), _T("FLOAT.BITS"))
	.Arg(XLL_DOUBLEX, _T("Num"), _T("is a floating point number "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Returns 1 x 64 array of the bits of the floating point Number"))
	.Documentation(
	
	)
);
xfp* WINAPI
xll_float_bits(double x)
{
#pragma XLLEXPORT
	static xll::FPX b(1, 64);

	union { double x; long long l; } u;
	u.x = x;

	for (unsigned short i = 0; i < 64; ++i)
		b[63 - i] = (u.l>>i)&1 ? 1 : 0;

	return b.get();
}

static AddInX xai_bits_float(
	FunctionX(XLL_DOUBLEX, _T("?xll_bits_float"), _T("BITS.FLOAT"))
	.Arg(XLL_FPX, _T("Bits"), _T("is an array of 64 bits "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Converts array of 64 bits to a floating point Number"))
	.Documentation(
	
	)
);
double WINAPI
xll_bits_float(const _FP* pb)
{
#pragma XLLEXPORT

	union { double x; long long l; } u;

	try {
		ensure (size(*pb) != 64);
	}
	catch (const std::exception& ex) {
		XLL_INFORMATION(ex.what());

		return std::numeric_limits<double>::quiet_NaN();
	}

	u.l = 0;
	for (xword i = 0; i < 64; ++i)
		if (pb->array[63 - i] != 0)
			u.l |= (1ll<<i);

	return u.x;
}