// float.cpp - floating point status and control
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif
using namespace xll;

static AddIn xai_float(
	Documentation(
		L"Wrappers for &lt;cmath&gt;."
	)
    .Category(CATEGORY)
);
