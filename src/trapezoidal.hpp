#ifndef _TRAPEZOIDAL_INTEGRATION_
#define _TRAPEZOIDAL_INTEGRATION_

namespace NumericalIntegration
{
    /**
     * Integrates function by Trapezoidal Rule
     * 
     * @param f function to be integrated
     * @param integralStart Initial point of integration
     * @param integralEnd end point of integration
     * @return Integrated area
     */
    double TrapezoidalRule(double (*f)(double), double integralStart, double integralEnd);
    
    
    /**
     * Integrates function by Trapezoidal Rule Repeated 
     * (This generates several trapezoids of equal sizes to cover the area to be integrated)
     * 
     * @param f function to be integrated
     * @param integralStart Initial point of integration
     * @param integralEnd end point of integration
     * @param parts Number of range divisions
     * @return Integrated area
     */
    double TrapezoidalRuleRepeated(double (*f)(double), double integralStart, double integralEnd, double parts);
}

#endif
