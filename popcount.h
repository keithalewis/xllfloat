// popcount.h - compute the Hamming weight of an unsigned int
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
// Hamming weight is number of bits that are 1.
// Hamming distance is weight of xor.
#pragma once

// use if most digits are 0
template<class I>
inline int
popcount0(I x)
{
	unsigned int c;
	
	for (c = 0; x != 0; ++c)
		x &= x-1;
    
	return c;
}

// use if most digits are 1
template<class I>
inline int
popcount1(I x)
{
	unsigned int c;
	
	for (c = 8*sizeof(unsigned int); x != -1; --c)
		x |= x+1;
    
	return c;
}

// Hamming weights for 0..255
const int popcount8[] = {
0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
};


template <class I> inline int popcount(I);

static_assert(sizeof(unsigned int) == 4, "unsigned ints must have 4 bytes");
template<>
inline int
popcount<unsigned int>(unsigned int i)
{
	int c;

	c  = popcount8[i&0xFF];
	i >>= 8;
	c += popcount8[i&0xFF];
	i >>= 8;
	c += popcount8[i&0xFF];
	i >>= 8;
	c += popcount8[i&0xFF];

	return c;
}

template<>
inline int
popcount<double>(double x)
{
	union { double d; unsigned int i[2]; } u;

	u.d = x;

	return popcount(u.i[0]) + popcount(u.i[1]);

}
