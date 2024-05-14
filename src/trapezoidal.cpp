#include <vector>
#include "xtensor/xarray.hpp"
#include "xtensor/xmath.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include "xtensor/xadapt.hpp"

#include "trapezoidal.hpp"

xt::xarray<double> Apply(double (*f)(double), xt::xarray<double> xData)
{
    std::vector<double> fy;

    for(double x: xData)
    {
        fy.push_back(f(x));
    }
    return xt::adapt(fy, xData.shape());
}

double NumericalIntegration::TrapezoidalRule(double (*f)(double), double integralStart, double integralEnd)
{
    double steps = (integralEnd - integralStart);
    xt::xarray<double> yValues = Apply(f, xt::linspace(integralStart, integralEnd, steps));
    xt::xarray<double> result = xt::sum(yValues) * ((integralEnd - integralStart) / 2);

    return result.data()[0];
}

double NumericalIntegration::TrapezoidalRuleRepeated(double (*f)(double), double integralStart, double integralEnd, double parts)
{
    double h = (integralEnd - integralStart) / parts;
    
    xt::xarray<double> yValues = Apply(f, xt::arange(integralStart, integralEnd + h, h));
    
    
    xt::xarray<double> trapezoidalBetweenInterval = 
                            xt::view(yValues, xt::drop(0, yValues.size()), xt::all());
    
    // applying generalized trapezoidal area rule
    xt::xarray<double> trapezoidalArea = yValues(0) + 
                            ( 2 * xt::sum(trapezoidalBetweenInterval) ) + yValues(yValues.size() - 1);
    
    return trapezoidalArea.data()[0] * (h / 2);
}
