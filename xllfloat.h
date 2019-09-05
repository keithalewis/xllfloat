// xllfloat.h - common header for Float category
// Copyright (c) 2011-2019 KALX, LLC. All rights reserved. No warranty is made.
#pragma once
#include <cfloat>
#include <cmath>
#include "xll12/xll/xll.h"

#ifndef CATEGORY
#define CATEGORY L"Float"
#endif

#ifdef _T
#undef _T
#endif
#define _T(s) L##s
