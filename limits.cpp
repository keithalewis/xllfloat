// limits.cpp - numerical limits
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "float.h"

#undef CATEGORY
#define CATEGORY L"Float Limits"

using namespace xll;
/*
static AddInX xai_float_constants(
	Args(CATEGORY)
	.Documentation(
		_T("Various constants from &lt;climits&gt;." )
	)
);
*/
#define HASH(x) L#x
#define STR(x) HASH(x)

//#define XLL_ENUM_DOC XLL_ENUM
// Integer
XLL_ENUM_DOC(CHAR_BIT, CHAR_BIT, CATEGORY, _T("number of bits in a char [") STR(CHAR_BIT) _T("]."), _T(""));
XLL_ENUM_DOC(CHAR_MAX, CHAR_MAX, CATEGORY, _T("maximum char value [") STR(CHAR_MAX) _T("]"), _T(""));
XLL_ENUM_DOC(CHAR_MIN, CHAR_MIN, CATEGORY, _T("mimimum char value [") STR(CHAR_MIN) _T("]"), _T(""));
XLL_ENUM_DOC(INT_MAX, INT_MAX, CATEGORY, _T("maximum (signed) int value [") STR(INT_MAX) _T("]"), _T(""));
XLL_ENUM_DOC(INT_MIN, INT_MIN, CATEGORY, _T("minimum (signed) int value [") STR(INT_MIN) _T("]"), _T(""));
XLL_ENUM_DOC(LONG_MAX, LONG_MAX, CATEGORY, _T("maximum (signed) long value [") STR(LONG_MAX) _T("]"), _T(""));
XLL_ENUM_DOC(LONG_MIN, LONG_MIN, CATEGORY, _T("minimum (signed) long value [") STR(LONG_MIN) _T("]"), _T(""));
XLL_ENUM_DOC(SCHAR_MAX, SCHAR_MAX, CATEGORY, _T("maximum signed char value [") STR(SCHAR_MAX) _T("]"), _T(""));
XLL_ENUM_DOC(SCHAR_MIN, SCHAR_MIN, CATEGORY, _T("minimum signed char value [") STR(SCHAR_MIN) _T("]"), _T(""));
XLL_ENUM_DOC(SHRT_MAX, SHRT_MAX, CATEGORY, _T("maximum (signed) short value [") STR(SHRT_MAX) _T("]"), _T(""));
XLL_ENUM_DOC(SHRT_MIN, SHRT_MIN, CATEGORY, _T("minimum (signed) short value [") STR(SHRT_MIN) _T("]"), _T(""));
XLL_ENUM_DOC(UCHAR_MAX, UCHAR_MAX, CATEGORY, _T("maximum unsigned char value [") STR(UCHAR_MAX) _T("]"), _T(""));
//XLL_ENUM_DOC(UINT_MAX, UINT_MAX, CATEGORY, _T("maximum unsigned int value [") STR(UINT_MAX) _T("]"), _T(""));
//XLL_ENUM_DOC(ULONG_MAX, ULONG_MAX, CATEGORY, _T("maximum unsigned long value [") STR(ULONG_MAX) _T("]"), _T(""));
XLL_ENUM_DOC(USHRT_MAX, USHRT_MAX, CATEGORY, _T("maximum unsigned short value [") STR(USHRT_MAX) _T("]"), _T(""));

// Double
XLL_ENUM_DOC(DBL_DIG, DBL_DIG, CATEGORY, _T("number of decimal digits of precision [") STR(DBL_DIG) _T("]"), _T(""));
XLL_ENUM_DOC(DBL_EPSILON, DBL_EPSILON, CATEGORY, _T("smallest such that 1.0+DBL_EPSILON != 1.0 [") STR(DBL_EPSILON) _T("]"), _T(""));
XLL_ENUM_DOC(DBL_MANT_DIG, DBL_MANT_DIG, CATEGORY, _T("number of bits in mantissa [") STR(DBL_MANT_DIG) _T("]"), _T(""));
XLL_ENUM_DOC(DBL_MAX, DBL_MAX, CATEGORY, _T("max value [") STR(DBL_MAX) _T("]"), _T(""));
XLL_ENUM_DOC(DBL_MAX_10_EXP, DBL_MAX_10_EXP, CATEGORY, _T("max decimal exponent [") STR(DBL_MAX_10_EXP) _T("]"), _T(""));
XLL_ENUM_DOC(DBL_MAX_EXP, DBL_MAX_EXP, CATEGORY, _T("max binary exponent [") STR(DBL_MAX_EXP) _T("]"), _T(""));
XLL_ENUM_DOC(DBL_MIN, DBL_MIN, CATEGORY, _T("min positive value [") STR(DBL_MIN) _T("]"), _T(""));
XLL_ENUM_DOC(DBL_MIN_10_EXP, DBL_MIN_10_EXP, CATEGORY, _T("min decimal exponent [") STR(DBL_MIN_10_EXP) _T("]"), _T(""));
XLL_ENUM_DOC(DBL_MIN_EXP, DBL_MIN_EXP, CATEGORY, _T("min binary exponent [") STR(DBL_MIN_EXP) _T("]"), _T(""));

// Float
XLL_ENUM_DOC(FLT_DIG, FLT_DIG, CATEGORY, _T("number of decimal digits of precision [") STR(FLT_DIG) _T("]"), _T(""));
XLL_ENUM_DOC(FLT_EPSILON, FLT_EPSILON, CATEGORY, _T("smallest such that 1.0+FLT_EPSILON != 1.0 [") STR(FLT_EPSILON) _T("]"), _T(""));
XLL_ENUM_DOC(FLT_MANT_DIG, FLT_MANT_DIG, CATEGORY, _T("number of bits in mantissa [") STR(FLT_MANT_DIG) _T("]"), _T(""));
XLL_ENUM_DOC(FLT_MAX, FLT_MAX, CATEGORY, _T("max value [") STR(FLT_MAX) _T("]"), _T(""));
XLL_ENUM_DOC(FLT_MAX_10_EXP, FLT_MAX_10_EXP, CATEGORY, _T("max decimal exponent [") STR(FLT_MAX_10_EXP) _T("]"), _T(""));
XLL_ENUM_DOC(FLT_MAX_EXP, FLT_MAX_EXP, CATEGORY, _T("max binary exponent [") STR(FLT_MAX_EXP) _T("]"), _T(""));
XLL_ENUM_DOC(FLT_MIN, FLT_MIN, CATEGORY, _T("min positive value [") STR(FLT_MIN) _T("]"), _T(""));
XLL_ENUM_DOC(FLT_MIN_10_EXP, FLT_MIN_10_EXP, CATEGORY, _T("min decimal exponent [") STR(FLT_MIN_10_EXP) _T("]"), _T(""));
XLL_ENUM_DOC(FLT_MIN_EXP, FLT_MIN_EXP, CATEGORY, _T("min binary exponent [") STR(FLT_MIN_EXP) _T("]"), _T(""));

// fpclass()
XLL_ENUM_DOC(_FPCLASS_SNAN, FPCLASS_SNAN, CATEGORY, _T("signaling NaN [") STR(_FPCLASS_SNAN) _T("]"), _T(""));
XLL_ENUM_DOC(_FPCLASS_QNAN, FPCLASS_QNAN, CATEGORY, _T("quiet NaN [") STR(_FPCLASS_QNAN) _T("]"), _T(""));
XLL_ENUM_DOC(_FPCLASS_NINF, FPCLASS_NINF, CATEGORY, _T("negative infinity [") STR(_FPCLASS_NINF) _T("]"), _T(""));
XLL_ENUM_DOC(_FPCLASS_NN, FPCLASS_NN, CATEGORY, _T("negative normal [") STR(_FPCLASS_NN) _T("]"), _T(""));
XLL_ENUM_DOC(_FPCLASS_ND, FPCLASS_ND, CATEGORY, _T("negative denormal [") STR(_FPCLASS_ND) _T("]"), _T(""));
XLL_ENUM_DOC(_FPCLASS_NZ, FPCLASS_NZ, CATEGORY, _T("-0 [") STR(_FPCLASS_NZ) _T("]"), _T(""));
XLL_ENUM_DOC(_FPCLASS_PZ, FPCLASS_PZ, CATEGORY, _T("+0 [") STR(_FPCLASS_PZ) _T("]"), _T(""));
XLL_ENUM_DOC(_FPCLASS_PD, FPCLASS_PD, CATEGORY, _T("positive denormal [") STR(_FPCLASS_PD) _T("]"), _T(""));
XLL_ENUM_DOC(_FPCLASS_PN, FPCLASS_PN, CATEGORY, _T("positive normal [") STR(_FPCLASS_PN) _T("]"), _T(""));
XLL_ENUM_DOC(_FPCLASS_PINF, FPCLASS_PINF, CATEGORY, _T("positive infinity [") STR(_FPCLASS_PINF) _T("]"), _T(""));

XLL_ENUM_DOC(std::numeric_limits<double>::signaling_NaN(), SNAN, CATEGORY, _T("signaling NaN"), _T(""));
XLL_ENUM_DOC(std::numeric_limits<double>::quiet_NaN(), QNAN, CATEGORY, _T("quiet NaN"), _T(""));
XLL_ENUM_DOC(std::numeric_limits<double>::infinity(), PINF, CATEGORY, _T("positive infinity"), _T(""));
