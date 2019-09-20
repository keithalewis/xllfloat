// fmsroot1d.h - root finding
#pragma once
#include <cassert>
#include <functional>
#include <utility>

namespace fms::root1d {

	// Alias for a function taking double to double.
	using F = std::function<double(double)>;

// Remove after implementing.
#pragma warning(push)
#pragma warning(disable: 4100 4189)

	// Bisection: x = (x0 + x1)/2
	// Given a function, f, and bracket x0, x1 return the next bracket
	inline std::pair<double,double> bisect(const F& f, double x0, double x1)
	{
		double y0 = f(x0);
		double x2 = (x0 + x1)/2;

		if (y0 != copysign(y0, f(x2))) {
			return std::pair(x0, x2);
		}
		else {
			return std::pair(x2, x1);
		}
	}

	// Secant: 0 = m(x - x0) + y0, where m = (y1 - y0)/(x1 - x0) and yi = f(xi), i = 0,1.
	// Return x = !!!insert formula here
	inline double secant(const F& f, double x0, double x1)
	{
		return 0; //!!! implement formula for x
	}

	inline std::pair<double,double> false_position(const F& f, double x0, double x1)
	{
		double x2 = secant(f, x0, x1);

		return std::pair(0, 0); //!!! return the values that bracket the root
	}

#pragma warning(pop)
} // namespace fms::root1d
