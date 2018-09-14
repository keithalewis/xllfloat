// nextafter.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddInX xai_nextafter(
	FunctionX(XLL_DOUBLE, _T("?xll_nextafter"), _T("NEXTAFTER"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is a floating point number"))
	.Arg(XLL_LONG, _T("n"), _T("is an integer "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Returns the n-th closest representable neighbor of x by calling _nextafter()"))
	.Documentation(
		_T("Note <codeInline>ULP(y, x) = n</codeInline> if and only if <codeInline>y = NEXTAFTER(x, n)</codeInline>.")
/*		, // see also
		xml::xlink("ULP")
*/	)
);
double WINAPI
xll_nextafter(double x, LONG n)
{
#pragma XLLEXPORT

	if (n > 0) {
		while (n--)
			x = _nextafter(x, x + 1);
	}
	else if (n < 0) {
		while (n++)
			x = _nextafter(x, x - 1);
	}

	return x;
}
