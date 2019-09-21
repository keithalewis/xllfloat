#pragma once
#include<utility>
#include<functional>
namespace fms {
	inline std::pair<double,double> bisect(double x0, double x1, const std::function<double(double)>&f)  {
		double x2 = (x0 + x1) / 2;
		double y2 = f(x2);
		double y1 = f(x1);
		//double y0 = f(x0);
		if (y2 > 0 && y1 > 0)
			return std::pair<double, double>{x0, x2};
		if (y2 < 0 && y1 < 0 )
			return std::pair<double, double>{x0, x2};
		return std::pair<double, double>{x1, x2};
	}
}