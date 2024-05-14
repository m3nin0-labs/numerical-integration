#ifndef _RIEMANN_INTEGRATION_
#define _RIEMANN_INTEGRATION_

namespace NumericalIntegration
{
    /**
     * Integrates function by Riemman Sum
     * 
     * @param f function to be integrated
     * @param integralStart Initial point of integration
     * @param integralEnd end point of integration
     * @param parts Number of range divisions
     * @return Integrated area
     */
    double RiemannSum(double (*f)(double), double integralStart, double integralEnd, double parts);    
}

#endif
