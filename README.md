# Floating Point Numbers

Floating point routines from <cmath> and various utilities.

## Introduction

IEEE floating point numbers do some trickery to get 
an extra bit of precision in the mantissa. Every floating point 
number is represented as

> f = &plusmn; sig &times; 2<sup>exp</sup>,

where the significand satisfies <math>1 &le; sig &lt; 2</math>.
The function `ldexp(f)` 
returns the <math>sig</math> and <math>exp</math> of <math>f</math>.
For IEEE 64 bit floats, 
the sign is 1 bit, the exponent is 11 bits, and the mantissa 
is 53 bits. Note 1 + 11 + 53 = 65, which is 1 greater than 64 
for all values of 1. To convert the exponent bits, take the 
11 bit base 2 number and subtract the bias = `DBL_MIN_EXP` = 1021. 
To convert the mantissa, tack a 1 on the front of the 52 mantissa bits 
then put a base 2 decimal point in front. 

## Machine Epsilon

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

The smallest nonzero positve (denormalized) IEEE 64 bit number is
really 2<markup><sup>-1073</sup></markup> = `_nextafter(0, 1)`.
But don't try to get Excel to display `NEXTAFTER` correctly.  You can
use `FLOAT.BITS` to see that Excel is giving you the right IEEE float,
or use `ULP` to verify the result is indeed one unit in the the last
place after 0.
