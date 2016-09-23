// limits.cpp - numerical limits
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "float.h"

#undef CATEGORY
#define CATEGORY "Float Constants"

using namespace xll;
/*
static AddInX xai_float_constants(
	Args(CATEGORY)
	.Documentation(
		_T("Various constants from &lt;climits&gt;." )
	)
);
*/
#define HASH(x) #x
#define STR(x) HASH(x)

// Integer
#if 0
XLL_ENUM_DOC(CHAR_BIT, CHAR_BIT, CATEGORY, "number of bits in a char [" STR(CHAR_BIT) "]", _T(""));
XLL_ENUM_DOC(CHAR_MAX, CHAR_MAX, CATEGORY, "maximum char value [" STR(CHAR_MAX) "]", _T(""));
XLL_ENUM_DOC(CHAR_MIN, CHAR_MIN, CATEGORY, "mimimum char value [" STR(CHAR_MIN) "]", _T(""));
XLL_ENUM_DOC(INT_MAX, INT_MAX, CATEGORY, "maximum (signed) int value [" STR(INT_MAX) "]", _T(""));
XLL_ENUM_DOC(INT_MIN, INT_MIN, CATEGORY, "minimum (signed) int value [" STR(INT_MIN) "]", _T(""));
XLL_ENUM_DOC(LONG_MAX, LONG_MAX, CATEGORY, "maximum (signed) long value [" STR(LONG_MAX) "]", _T(""));
XLL_ENUM_DOC(LONG_MIN, LONG_MIN, CATEGORY, "minimum (signed) long value [" STR(LONG_MIN) "]", _T(""));
XLL_ENUM_DOC(SCHAR_MAX, SCHAR_MAX, CATEGORY, "maximum signed char value [" STR(SCHAR_MAX) "]", _T(""));
XLL_ENUM_DOC(SCHAR_MIN, SCHAR_MIN, CATEGORY, "minimum signed char value [" STR(SCHAR_MIN) "]", _T(""));
XLL_ENUM_DOC(SHRT_MAX, SHRT_MAX, CATEGORY, "maximum (signed) short value [" STR(SHRT_MAX) "]", _T(""));
XLL_ENUM_DOC(SHRT_MIN, SHRT_MIN, CATEGORY, "minimum (signed) short value [" STR(SHRT_MIN) "]", _T(""));
XLL_ENUM_DOC(UCHAR_MAX, UCHAR_MAX, CATEGORY, "maximum unsigned char value [" STR(UCHAR_MAX) "]", _T(""));
XLL_ENUM_DOC(UINT_MAX, UINT_MAX, CATEGORY, "maximum unsigned int value [" STR(UINT_MAX) "]", _T(""));
XLL_ENUM_DOC(ULONG_MAX, ULONG_MAX, CATEGORY, "maximum unsigned long value [" STR(ULONG_MAX) "]", _T(""));
XLL_ENUM_DOC(USHRT_MAX, USHRT_MAX, CATEGORY, "maximum unsigned short value [" STR(USHRT_MAX) "]", _T(""));

// Double
XLL_ENUM_DOC(DBL_DIG, DBL_DIG, CATEGORY, "number of decimal digits of precision [" STR(DBL_DIG) "]", _T(""));
XLL_ENUM_DOC(DBL_EPSILON, DBL_EPSILON, CATEGORY, "smallest such that 1.0+DBL_EPSILON != 1.0 [" STR(DBL_EPSILON) "]", _T(""));
XLL_ENUM_DOC(DBL_MANT_DIG, DBL_MANT_DIG, CATEGORY, "number of bits in mantissa [" STR(DBL_MANT_DIG) "]", _T(""));
XLL_ENUM_DOC(DBL_MAX, DBL_MAX, CATEGORY, "max value [" STR(DBL_MAX) "]", _T(""));
XLL_ENUM_DOC(DBL_MAX_10_EXP, DBL_MAX_10_EXP, CATEGORY, "max decimal exponent [" STR(DBL_MAX_10_EXP) "]", _T(""));
XLL_ENUM_DOC(DBL_MAX_EXP, DBL_MAX_EXP, CATEGORY, "max binary exponent [" STR(DBL_MAX_EXP) "]", _T(""));
XLL_ENUM_DOC(DBL_MIN, DBL_MIN, CATEGORY, "min positive value [" STR(DBL_MIN) "]", _T(""));
XLL_ENUM_DOC(DBL_MIN_10_EXP, DBL_MIN_10_EXP, CATEGORY, "min decimal exponent [" STR(DBL_MIN_10_EXP) "]", _T(""));
XLL_ENUM_DOC(DBL_MIN_EXP, DBL_MIN_EXP, CATEGORY, "min binary exponent [" STR(DBL_MIN_EXP) "]", _T(""));

// Float
XLL_ENUM_DOC(FLT_DIG, FLT_DIG, CATEGORY, "number of decimal digits of precision [" STR(FLT_DIG) "]", _T(""));
XLL_ENUM_DOC(FLT_EPSILON, FLT_EPSILON, CATEGORY, "smallest such that 1.0+FLT_EPSILON != 1.0 [" STR(FLT_EPSILON) "]", _T(""));
XLL_ENUM_DOC(FLT_MANT_DIG, FLT_MANT_DIG, CATEGORY, "number of bits in mantissa [" STR(FLT_MANT_DIG) "]", _T(""));
XLL_ENUM_DOC(FLT_MAX, FLT_MAX, CATEGORY, "max value [" STR(FLT_MAX) "]", _T(""));
XLL_ENUM_DOC(FLT_MAX_10_EXP, FLT_MAX_10_EXP, CATEGORY, "max decimal exponent [" STR(FLT_MAX_10_EXP) "]", _T(""));
XLL_ENUM_DOC(FLT_MAX_EXP, FLT_MAX_EXP, CATEGORY, "max binary exponent [" STR(FLT_MAX_EXP) "]", _T(""));
XLL_ENUM_DOC(FLT_MIN, FLT_MIN, CATEGORY, "min positive value [" STR(FLT_MIN) "]", _T(""));
XLL_ENUM_DOC(FLT_MIN_10_EXP, FLT_MIN_10_EXP, CATEGORY, "min decimal exponent [" STR(FLT_MIN_10_EXP) "]", _T(""));
XLL_ENUM_DOC(FLT_MIN_EXP, FLT_MIN_EXP, CATEGORY, "min binary exponent [" STR(FLT_MIN_EXP) "]", _T(""));

// fpclass()
XLL_ENUM_DOC(_FP12CLASS_SNAN, FPCLASS_SNAN, CATEGORY, "signaling NaN [" STR(_FP12CLASS_SNAN) "]", _T(""));
XLL_ENUM_DOC(_FP12CLASS_QNAN, FPCLASS_QNAN, CATEGORY, "quiet NaN [" STR(_FP12CLASS_QNAN) "]", _T(""));
XLL_ENUM_DOC(_FP12CLASS_NINF, FPCLASS_NINF, CATEGORY, "negative infinity [" STR(_FP12CLASS_NINF) "]", _T(""));
XLL_ENUM_DOC(_FP12CLASS_NN, FPCLASS_NN, CATEGORY, "negative normal [" STR(_FP12CLASS_NN) "]", _T(""));
XLL_ENUM_DOC(_FP12CLASS_ND, FPCLASS_ND, CATEGORY, "negative denormal [" STR(_FP12CLASS_ND) "]", _T(""));
XLL_ENUM_DOC(_FP12CLASS_NZ, FPCLASS_NZ, CATEGORY, "-0 [" STR(_FP12CLASS_NZ) "]", _T(""));
XLL_ENUM_DOC(_FP12CLASS_PZ, FPCLASS_PZ, CATEGORY, "+0 [" STR(_FP12CLASS_PZ) "]", _T(""));
XLL_ENUM_DOC(_FP12CLASS_PD, FPCLASS_PD, CATEGORY, "positive denormal [" STR(_FP12CLASS_PD) "]", _T(""));
XLL_ENUM_DOC(_FP12CLASS_PN, FPCLASS_PN, CATEGORY, "positive normal [" STR(_FP12CLASS_PN) "]", _T(""));
XLL_ENUM_DOC(_FP12CLASS_PINF, FPCLASS_PINF, CATEGORY, "positive infinity [" STR(_FP12CLASS_PINF) "]", _T(""));

XLL_ENUM_DOC(std::numeric_limits<double>::signaling_NaN(), SNAN, CATEGORY, "signaling NaN", _T(""));
XLL_ENUM_DOC(std::numeric_limits<double>::quiet_NaN(), QNAN, CATEGORY, "quiet NaN", _T(""));
XLL_ENUM_DOC(std::numeric_limits<double>::infinity(), PINF, CATEGORY, "positive infinity", _T(""));
#endif //!!!0