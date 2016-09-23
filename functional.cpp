// functional.cpp - STL <functional>
//#include "function.h"
#include "xll/xll.h"

#ifndef CATEGORY
#define CATEGORY "Function"
#endif
#ifndef dimof
#define dimof(x) sizeof(x)/sizeof(*x)
#endif

using namespace xll;

typedef xll::traits<XLOPERX>::xcstr xcstr;
typedef xll::traits<XLOPERX>::xfp xfp;
typedef xll::traits<XLOPERX>::xword xword;

static xcstr xav_sum[] = {
	_T("is the first argument"),
	_T("is the second argument")
};
static AddInX xai_sum(
	_T("?xll_sum"), XLL_DOUBLE XLL_DOUBLE XLL_DOUBLE,
	_T("FUNCTION.ADD"), _T("Arg1, Arg2"),
	CATEGORY, _T("Returns Arg1 + Arg2"),
	dimof(xav_sum), xav_sum
);
double WINAPI
xll_sum(double x1, double x2)
{
#pragma XLLEXPORT

	return x1 + x2;
}

static xcstr xav_difference[] = {
	_T("is the first argument"),
	_T("is the second argument")
};
static AddInX xai_difference(
	_T("?xll_difference"), XLL_DOUBLE XLL_DOUBLE XLL_DOUBLE,
	_T("FUNCTION.SUB"), _T("Arg1, Arg2"),
	CATEGORY, _T("Returns Arg1 - Arg2"),
	dimof(xav_difference), xav_difference
);
double WINAPI
xll_difference(double x1, double x2)
{
#pragma XLLEXPORT

	return x1 - x2;
}

static xcstr xav_product[] = {
	_T("is the first argument"),
	_T("is the second argument")
};
static AddInX xai_product(
	_T("?xll_product"), XLL_DOUBLE XLL_DOUBLE XLL_DOUBLE,
	_T("FUNCTION.MUL"), _T("Arg1, Arg2"),
	CATEGORY, _T("Returns Arg1 * Arg2"),
	dimof(xav_product), xav_product
);
double WINAPI
xll_product(double x1, double x2)
{
#pragma XLLEXPORT

	return x1 * x2;
}

static xcstr xav_quotient[] = {
	_T("is the first argument"),
	_T("is the second argument")
};
static AddInX xai_quotient(
	_T("?xll_quotient"), XLL_DOUBLE XLL_DOUBLE XLL_DOUBLE,
	_T("FUNCTION.DIV"), _T("Arg1, Arg2"),
	CATEGORY, _T("Returns Arg1 / Arg2"),
	dimof(xav_quotient), xav_quotient
);
double WINAPI
xll_quotient(double x1, double x2)
{
#pragma XLLEXPORT

	double x = x1/x2;

	return x;
}

static xcstr xav_fmod[] = {
	_T("is the first argument"),
	_T("is the second argument")
};
static AddInX xai_fmod(
	_T("?xll_fmod"), XLL_DOUBLE XLL_DOUBLE XLL_DOUBLE,
	_T("FUNCTION.FMOD"), _T("Arg1, Arg2"),
	CATEGORY, _T("Returns fmod(Arg1, Arg2) where fmod is the C standard library function."),
	dimof(xav_fmod), xav_fmod
);
double WINAPI
xll_fmod(double x1, double x2)
{
#pragma XLLEXPORT
	return x2 != 0 ? fmod(x1, x2) : std::numeric_limits<double>::quiet_NaN();
}

static xcstr xav_mod[] = {
	_T("is the first argument"),
	_T("is the second argument")
};
static AddInX xai_mod(
	_T("?xll_mod"), XLL_LPOPERX XLL_LONG XLL_LONG,
	_T("FUNCTION.MOD"), _T("Arg1, Arg2"),
	CATEGORY, _T("Returns Arg1 % Arg2. Not the same as Excel built-in MOD(Arg1, Arg2)"),
	dimof(xav_mod), xav_mod
);
LPOPERX WINAPI
xll_mod(LONG x1, LONG x2)
{
#pragma XLLEXPORT
	static OPERX o;

	if (x2 != 0) {
		o.xltype = xltypeNum;
		o.val.num = x1 % x2;
	}
	else {
		o.xltype = xltypeErr;
		o.val.err = xlerrValue;
	}

	return &o;
}

static xcstr xav_not[] = {
	_T("is the first argument")
};
static AddInX xai_not(
	_T("?xll_not"), XLL_WORDX XLL_WORDX XLL_WORDX,
	_T("FUNCTION.NOT"), _T("Arg"),
	CATEGORY, _T("Returns ~Arg"),
	dimof(xav_not), xav_not
);
WORD WINAPI
xll_not(WORD x)
{
#pragma XLLEXPORT

	return ~x;
}

static xcstr xav_and[] = {
	_T("is the first argument"),
	_T("is the second argument")
};
static AddInX xai_and(
	_T("?xll_and"), XLL_WORDX XLL_WORDX XLL_WORDX,
	_T("FUNCTION.AND"), _T("Arg1, Arg2"),
	CATEGORY, _T("Returns Arg1 & Arg2"),
	dimof(xav_and), xav_and
);
WORD WINAPI
xll_and(WORD x1, WORD x2)
{
#pragma XLLEXPORT

	return x1 & x2;
}

static xcstr xav_or[] = {
	_T("is the first argument"),
	_T("is the second argument")
};
static AddInX xai_or(
	_T("?xll_or"), XLL_WORDX XLL_WORDX XLL_WORDX,
	_T("FUNCTION.OR"), _T("Arg1, Arg2"),
	CATEGORY, _T("Returns Arg1 % Arg2"),
	dimof(xav_or), xav_or
);
WORD WINAPI
xll_or(WORD x1, WORD x2)
{
#pragma XLLEXPORT

	return x1 | x2;
}

static xcstr xav_xor[] = {
	_T("is the first argument"),
	_T("is the second argument")
};
static AddInX xai_xor(
	_T("?xll_xor"), XLL_WORDX XLL_WORDX XLL_WORDX,
	_T("FUNCTION.XOR"), _T("Arg1, Arg2"),
	CATEGORY, _T("Returns Arg1 ^ Arg2"),
	dimof(xav_xor), xav_xor
);
WORD WINAPI
xll_xor(WORD x1, WORD x2)
{
#pragma XLLEXPORT

	return x1 ^ x2;
}

static xcstr xav_shift[] = {
	_T("is the argument whose bits are to be shifted"),
	_T("is number of bits to shifted to the left if positive or right if negative")
};
static AddInX xai_shift(
	_T("?xll_shift"), XLL_WORDX XLL_WORDX XLL_SHORTX,
	_T("FUNCTION.SHIFT"), _T("Arg, N"),
	CATEGORY, _T("Returns Arg << N or Arg >> N"),
	dimof(xav_shift), xav_shift
);
WORD WINAPI
xll_shift(WORD x, SHORT n)
{
#pragma XLLEXPORT

	return n > 0 ? x << n : n < 0 ? x >> -n : x;
}

static xcstr xav_equals[] = {
	_T("is the first argument"),
	_T("is the second argument")
};
static AddInX xai_equals(
	_T("?xll_equals"), XLL_BOOL XLL_DOUBLE XLL_DOUBLE,
	_T("FUNCTION.EQUALS"), _T("Arg1, Arg2"),
	CATEGORY, _T("Returns true if Arg1 is equal to Arg2"),
	dimof(xav_equals), xav_equals
);
BOOL WINAPI
xll_equals(double x1, double x2)
{
#pragma XLLEXPORT

	return x1 == x2;
}

static xcstr xav_identity[] = {
	_T("is the argument to be returned")
};
static AddInX xai_identity(
	_T("?xll_identity"), XLL_DOUBLE XLL_DOUBLE,
	_T("FUNCTION.IDENTITY"), _T("Arg"),
	CATEGORY, _T("Returns Arg"),
	dimof(xav_identity), xav_identity
);
double WINAPI
xll_identity(double x)
{
#pragma XLLEXPORT

	return x;
}
/*
static xcstr xav_equals[] = {
	_T("is the first argument"),
	_T("is the second argument")
};
static AddInX xai_equals(
	_T("?xll_equals"), XLL_BOOL XLL_LPOPERX XLL_LPOPERX,
	_T("FUNCTION.EQUALS"), _T("Arg1, Arg2"),
	CATEGORY, _T("Returns true if Arg1 is equal to Arg2"),
	dimof(xav_equals), xav_equals
);
BOOL WINAPI
xll_equals(LPOPERX px1, LPOPERX px2)
{
#pragma XLLEXPORT

	return *px1 == *px2;
}

static xcstr xav_identity[] = {
	_T("is the argument to be returned")
};
static AddInX xai_identity(
	_T("?xll_identity"), XLL_LPOPERX XLL_LPOPERX,
	_T("FUNCTION.IDENTITY"), _T("Arg"),
	CATEGORY, _T("Returns Arg"),
	dimof(xav_identity), xav_identity
);
LPOPERX WINAPI
xll_identity(LPOPERX px)
{
#pragma XLLEXPORT

	return px;
}
*/