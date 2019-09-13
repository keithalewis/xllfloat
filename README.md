# Floating Point Numbers

Floating point routines from &lt;cmath&gt; and various utilities.

## Introduction

IEEE floating point numbers do some trickery to get 
an extra bit of precision in the significand (aka mantissa). Every floating point 
number is represented as

> f = &plusmn; sig &times; 2<sup>exp</sup>,

where the significand satisfies <math>1 &le; sig &lt; 2</math>.
The function `frexp(f)` 
returns the <math>sig/2</math> and <math>exp+1</math> of <math>f</math>.
The function `ldexp(s,e)` converts the significant and exponent
back to the original floating point number.

For IEEE 64 bit floats, 
the sign is 1 bit, he exponent is 11 bits, and the mantissa 
is 53 bits. Note 1 + 11 + 53 = 65, which is 1 greater than 64.
The sign bit is 0 for positive and 1 for negative.
To convert the exponent bits, take the 
11 bit base 2 number and subtract the bias = 1023. 
To convert the mantissa, put a base 2 decimal point in front and
tack a 1 on the front of the 52 mantissa bits. 

### Machine Epsilon

Unlike the mathematical real numbers we can have <math>1 + x =
1</math> with <math>x&ne;0<math>.  The smallest such positive
floating point number is called _machine epsilon_. For 64-bit
floating point numbers it is approximately 2.22e-16 and is denoted
`std::numeric_limits<double>::epsilon()` in C++, or `DBL_EPSILON` in C.

This may seem annoying at first, but it is quite useful when it
comes to summing series. E.g., how many terms of
<math>&Sigma;<sub>n&ge;0</sub> x<sup>n</sup>/n!</math> should we
use when computing <math>exp(x)</math>? Stop when the terms are
less than machine epsilon.

## Special Numbers

Certain bit patterns have special meaning.

### Positive and Negative Zero

If all the bits are 0 then corresponding floating point is 0.
If the first bit is 1 then the floating point number is -0
which is not equal to 0.

### Denormal Numbers

There are many numbers less than machine epsilon that are not 0,
for example 2<sup>-52</sup> to 2<sup>-1022</sup>. There are even
smaller non zero floating point numbers. If all exponent bits
are 0 then the significand no longer has the implicit 1 prefixed.
and the exponent is -1022.

### Not A Number

If all the exponent bits are 1 then the number is a NaN:
not a number. There are 2 &times; 2<sup>52</sup> NaNs. Any arithmetical
computation with a NaN results in a NaN. It is also the case
no two NaN are equal. In fact `x != x` is a way to test if
`x` is a NaN.

### Infinity

If all the exponent bits are 1 and all the significand bits
are 0 then the number is infinity. There is also a negative infinity.

### Units in the Last Place

One handy feature of the IEEE representation is the the order of
the underlying bits, interpreted as a 64 bit integer, is the same
as the ordering of the corrresponding floats. Units in the last
place is the number of such integer values between two floats (plus 1).

## References

https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
