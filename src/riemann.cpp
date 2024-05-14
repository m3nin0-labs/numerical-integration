#include "xtensor/xarray.hpp"
#include "xtensor/xmath.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include "xtensor/xadapt.hpp"

#include "riemann.hpp"

xt::xarray<double> LeftApply(double (*f)(double), xt::xarray<double> xData)
{
    std::vector<double> fy;

    for(double x: xData)
    {
        fy.push_back(f(x));
    }
    return xt::adapt(fy, xData.shape());
}

xt::xarray<double> RightApply(double (*f)(double), const xt::xarray<double> xData)
{
    std::vector<double> fy;
    
    
    for(int i = 0; i < xData.size(); ++i)
    {
        fy.push_back(f(xData(i + 1)));
    }
    return xt::adapt(fy, xData.shape());
}

xt::xarray<double> MiddleApply(double (*f)(double), const xt::xarray<double> xData)
{
    std::vector<double> fy;
    
    for(int i = 0; i < xData.size(); ++i)
    {        
        fy.push_back(f((xData(i + 1) + xData(i)) / 2));
    }
    return xt::adapt(fy, xData.shape());
}

double NumericalIntegration::RiemannSum(double (*f)(double), double integralStart, double integralEnd, double parts)
{
    double result = 0; 
    double h = (integralEnd - integralStart) /  parts;
    xt::xarray<double> subIntervals = xt::arange(integralStart, integralEnd + h, h);

    xt::xarray<double> yValues = LeftApply(f, subIntervals);
    
    for(int i = 0; i < subIntervals.size() - 1; ++i)
    {
        result += (subIntervals(i + 1) - subIntervals(i)) * yValues(i);
    }
    return result;
}
