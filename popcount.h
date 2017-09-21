// popcount.h - compute the Hamming weight of an unsigned int
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
// Hamming weight is number of bits that are 1.
// Hamming distance is weight of xor.
#pragma once
#include <cstdint>

template<class I>
constexpr I popcount(I i)
{
    return !i ? 0 : 1 + popcount(i & (i - 1));
}