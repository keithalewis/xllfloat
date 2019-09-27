// fmsroot1d.h - root finding
#pragma once
#include <cassert>
#include <functional>
#include <utility>
#include "xll12/xll/ensure.h"

namespace fms::root1d {

	// Alias for a function taking a double and returning double.
	using F = std::function<double(double)>;

// Remove after implementing.
#pragma warning(push)
#pragma warning(disable: 4100 4189)

	// Bisection: x = (x0 + x1)/2
	// Given a function, f, and bracket x0 < x1 return the next bracket
	inline std::pair<double,double> bisect(const F& f, double x0, double x1)
	{
		ensure(x0 <= x1);

		if (x0 == x1)
			return std::pair(x0, x1);

		std::pair<double, double> p;
		
		double y0 = f(x0);
		if (y0 == 0)
			return std::pair(x0, x0);
		
		double y1 = f(x1);
		if (y1 == 0)
			return std::pair(x1, x1);
		
		ensure(y0 != copysign(y0, y1)); // bracketed

		double x2 = (x0 + x1)/2;
		double y2 = f(x2);

		if (y0 != copysign(y0, y2)) {
			p = std::pair(x0, x2);
		}
		else {
			ensure(y1 != copysign(y1, y2));

			p = std::pair(x2, x1);
		}

		return p;
	}

	// Secant: 0 = m(x - x0) + y0, where m = (y1 - y0)/(x1 - x0) and yi = f(xi), i = 0,1.
	// Return x = !!!insert formula here
	inline double secant(const F& f, double x0, double x1)
	{
		double y0 = f(x0);
		double y1 = f(x1);

		return (x0*y1 - x1*y0)/(y1 - y0); //!!! implement formula for x
	}

	inline std::pair<double,double> false_position(const F& f, double x0, double x1)
	{
		ensure(x0 <= x1);

		if (x0 == x1)
			return std::pair(x0, x1);

		std::pair<double, double> p;

		double y0 = f(x0);
		if (y0 == 0)
			return std::pair(x0, x0);

		double y1 = f(x1);
		if (y1 == 0)
			return std::pair(x1, x1);

		ensure(y0 != copysign(y0, y1)); // bracketed

		double x2 = secant(f, x0, x1);
		double y2 = f(x2);

		if (y0 != copysign(y0, y2)) {
			p = std::pair(x0, x2);
		}
		else {
			ensure(y1 != copysign(y1, y2));

			p = std::pair(x2, x1);
		}

		return p;
	}

#pragma warning(pop)
} // namespace fms::root1d
