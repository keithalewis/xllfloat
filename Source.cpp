// Author: tz2446
// nearest integer, rounding away from zero in halfway cases
// Rename this file to xllround.cpp and implement XLL.ROUND which calls round
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_round(
	FunctionX(XLL_DOUBLE, _T("?xll_round"), _T("XLL.ROUND"))
	.Arg(XLL_DOUBLE, _T("x"), _T("value to be rounded"))
	.Category(CATEGORY)
	.FunctionHelp(_T("Returns the integral value that is nearest to x, with halfway cases rounded away from zero."))
	.Documentation(LR"(The round() function in C++ returns the integral value that is nearest to the argument, with halfway cases rounded away from zero.)")
);

double WINAPI
xll_round(double value_to_round)
{
	/*here I disable the warning sign because the compile will automatically regard warning as error and stop the program*/
	/*the warning arises because I am converting a "double" into "int", but I think it is okay for this specific function*/
#pragma XLLEXPORT/*
#pragma warning(push)
#pragma warning(disable:4244)*/
	int round_result = round(value_to_round);
	return round_result;/*
#pragma warning(pop)*/
}

#ifdef _DEBUG
xll::test test_xll_round([]() {
	int presult;
	double input = 10.5;
	presult = xll_round(input);
	ensure(presult == 10);
	});
#endif