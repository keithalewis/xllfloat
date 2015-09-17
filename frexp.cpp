// frexp.c - calls corresponding C library function
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "float.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_frexp(
	FunctionX(XLL_FPX, _T("?xll_frexp"), _T("FREXP"))
	.Arg(XLL_DOUBLEX, _T("x"), _T("is a floating point number "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Returns array {sig, exp} where 0.5 le sig lt 1 and x = sig*2^exp"))
	.Documentation(
		_T("The inverse of <codeInline>LDEXP</codeInline>. ")
		, // see also
		xml::xlink("LDEXP")
	)
);
xfp* WINAPI
xll_frexp(double x)
{
#pragma XLLEXPORT
	static xll::FP se(1, 2);
	int exp;

	se[0] = frexp(x, &exp);
	se[1] = exp;

	return se.get();
}
