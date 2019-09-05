// float.cpp - floating point status and control
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif
#if 0
using namespace xll;

/*
static AddInX xai_float(
	DocumentX(CATEGORY)
	.Documentation(
		xml::Conceptual(_T("Floating point routines from &lt;cmath&gt; and various utilities."))
		.section(_T("Introduction"),
			_T("IEEE floating point numbers do some trickery to get ")
			_T("an extra bit of precision in the mantissa. Every floating point ")
			_T("number is represented as <math>f</math> = ") ENT_plusmn _T("<math>sig</math> ")
			ENT_times _T(" 2<math><markup><sup>exp</sup></markup></math>, where the significand satisfies ")
			_T("0.5 ") ENT_le _T(" sig &lt; 1. The function <codeInline>_frexp(f)</codeInline> ")
			_T("returns the <math>sig</math> and <math>exp</math> of <math>f</math>. For IEEE 64 bit floats, ")
			_T("the sign is 1 bit, the exponent is 11 bits, and the mantissa ")
			_T("is 53 bits. Note 1 + 11 + 53 = 65, which is 1 greater than 64 ")
			_T("for all values of 1. To convert the exponent bits, take the ")
			_T("11 bit base 2 number and subtract the bias = <codeInline>DBL_MIN_EXP</codeInline> - 1 = 1022. ")
			_T("To convert the mantissa, tack a 1 on the front of the 52 mantissa bits ")
			_T("then put a base 2 decimal point in front. ")
			_T("</para><para>")
			_T("One might think the smallest number that can be represented in this way ")
			_T("is therefore 0.5 * 2<markup><sup>-1022</sup></markup> = 1.112E-308, but one would be wrong. ")
			_T("This would correspond to all 11 exponent bits being zero, but that has ")
			_T("special meaning in IEEE floats . The smallest 'normalized' number is in ")
			_T("fact 0.5 * 2<markup><sup>-1021</sup></markup> = 2.225E-308 = <codeInline>DBL_MIN</codeInline>.")
			_T("</para><para>")
			_T("The smallest nonzero positve (denormalized) IEEE 64 bit number is really ")
			_T("0.5 * 2<markup><sup>-1073</sup></markup> = <codeInline>_nextafter(0, 1)</codeInline>. ")
			_T("But don't try to get Excel to display <codeInline>NEXTAFTER</codeInline> correctly. ")
			_T("You can use <codeInline>FLOAT.BITS</codeInline> to see that Excel is giving you the right ")
			_T("IEEE float, or use <codeInline>ULP</codeInline> to verify the result is indeed one unit in the the last place after 0. ")
		)
		.section(_T("Denormalized Numbers"),
			_T("A <newTerm>denormalized</newTerm> (or <newTerm>denormal</newTerm> or ")
			_T("<newTerm>subnormal</newTerm>) number lies between <codeInline>-DBL_MIN</codeInline> ")
			_T("and <codeInline>DBL_MIN</codeInline>. ")
			_T("The lead significant digit is zero as are all the exponent bits. ")
		)
		,
		xml::element()
			.content(xml::xlink(_T("NEXTAFTER")))
			.content(xml::xlink(_T("FLOAT.BITS")))
			.content(xml::xlink(_T("ULP")))
			.content(xml::externalLink(_T("http://support.microsoft.com/kb/78113"), _T("Floating-point arithmetic may give inaccurate results in Excel")))
	)
);
*/
//
// floating point control
//

#ifdef _DEBUG

static AddIn xai_clearfp(Args(
	L"?xll_clearfp", XLL_LONG,
	L"CLEARFP", L"",
	CATEGORY//!!!, "Gets and clears the floating-point status word by calling _clearfp()")
);
LONG WINAPI
xll_clearfp()
{
#pragma XLLEXPORT

	return _clearfp();
}

static AddIn xai_controlfp(
	L"?xll_controlfp", XLL_LONG XLL_LONG XLL_LONG,
	L"CONTROLFP", L"new, mask",
	CATEGORY//!!!, "Gets and sets the floating-point control word by calling _controlfp_s()"
);
LONG WINAPI
xll_controlfp(LONG n, LONG m)
{
#pragma XLLEXPORT
	int err;
	unsigned int s;

	try {
		ensure (0 == (err = _controlfp_s(&s, n, m)));
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());

		return err;
	}

	return s;
}

static AddIn xai_statusfp(
	L"?xll_statusfp", XLL_LONG,
	L"STATUSFP", L"",
	CATEGORY//!!!, "Get the floating point status word by calling _statusfp()"
);
LONG WINAPI
xll_statusfp()
{
#pragma XLLEXPORT

	return _statusfp();
}

static AddIn xai_statusfp2(
	L"?xll_statusfp2", XLL_FP,
	L"STATUSFP2", L"",
	CATEGORY //, L"Get the x87 and SSE2 floating point status words by calling _statusfp2()"
);
_FP12* WINAPI
xll_statusfp2()
{
#pragma XLLEXPORT
	static xll::FP12 s(1, 2);
	unsigned int s0, s1;

	_statusfp2(&s0, &s1);

	s[0] = s0;
	s[1] = s1;

	return s.get();
}

static AddIn xai_fpreset(
	L"?xll_fpreset", XLL_LONG,
	L"FPRESET", L"",
	CATEGORY//!!!, "Resets the floating-point package by calling _fpreset()"
);
LONG WINAPI
xll_fpreset()
{
#pragma XLLEXPORT

	_fpreset();

	return 0;
}

#endif // _DEBUG
#endif // 0