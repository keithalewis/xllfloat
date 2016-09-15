# Floating Point Numbers

Floating point routines from &lt;cmath&gt; and various utilities.

## Introduction

IEEE floating point numbers do some trickery to get 
an extra bit of precision in the mantissa. Every floating point 
number is represented as
$$f = &plusmn; sig &times; 2<sup>exp</sup>$$,
where the significand satisfies 
<math>0.5 &le; sig &lt; 1</math>
The function `_frexp(f)` 
returns the <math>sig</math> and <math>exp</math> of <math>f</math>.
For IEEE 64 bit floats, 
the sign is 1 bit, the exponent is 11 bits, and the mantissa 
is 53 bits. Note 1 + 11 + 53 = 65, which is 1 greater than 64 
for all values of 1. To convert the exponent bits, take the 
11 bit base 2 number and subtract the bias = `DBL_MIN_EXP` - 1 = 1022. 
To convert the mantissa, tack a 1 on the front of the 52 mantissa bits 
then put a base 2 decimal point in front. 

One might think the smallest number that can be represented in this way 
is therefore 0.5 * 2<markup><sup>-1022</sup></markup> = 1.112E-308, but one would be wrong. 
This would correspond to all 11 exponent bits being zero, but that has 
special meaning in IEEE floats . The smallest `normalized` number is in 
fact 0.5 * 2<markup><sup>-1021</sup></markup> = 2.225E-308 = `DBL_MIN`.

The smallest nonzero positve (denormalized) IEEE 64 bit number is really 
0.5 * 2<markup><sup>-1073</sup></markup> = `_nextafter(0, 1)`. 
But don`t try to get Excel to display `NEXTAFTER` correctly. 
You can use `FLOAT.BITS` to see that Excel is giving you the right 
IEEE float, or use `ULP` to verify the result is indeed one unit in the the last place after 0. 
		
Denormalized Numbers,
A _denormalized_ (or _denormal_ or 
_subnormal_) number lies between `-DBL_MIN` 
and `DBL_MIN`. 
The lead significant digit is zero as are all the exponent bits. 
