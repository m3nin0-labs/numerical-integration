#include <math.h>
#include <iostream>
#include "riemann.hpp"
#include "trapezoidal.hpp"

// functions to be integrated by numerical integration methods
double f(double x)
{
    return std::pow(x, 2);
}

double f2(double x)
{
    return 1 / x;
}

int main()
{
    std::cout << "RiemannSum" << std::endl;
    std::cout << "Integration of f(x): Riemman(f(x), 1, 2, 2) = " << NumericalIntegration::RiemannSum(f, 1.0, 2.0, 2.0) << std::endl;
    std::cout << "Integration of f(x): Riemman(f(x), 1, 2, 4) = " << NumericalIntegration::RiemannSum(f, 1.0, 2.0, 4.0) << std::endl;

    std::cout << "\n\nTrapezoidalRule" << std::endl;
    std::cout << "Integration of f(x): TrapezoidalRule(f2(x), 1, 3) = " << NumericalIntegration::TrapezoidalRule(f2, 1, 3) << std::endl;
    std::cout << "Integration of f(x): TrapezoidalRuleRepeated(f2(x), 1.0, 3.0, 350.0) = " << NumericalIntegration::TrapezoidalRuleRepeated(f2, 1.0, 3.0, 350.0) << std::endl;

    return 0;
}
