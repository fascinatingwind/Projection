#include "NumericComparer.h"

namespace SpaceX
{
    bool NumericComparer::IsEqual(float a, float b, float epsilon)
    {
        return essentiallyEqual(a, b, epsilon);
    }
    bool NumericComparer::IsGreater(float a, float b, float epsilon)
    {
        return definitelyGreaterThan(a, b, epsilon);
    }

    bool NumericComparer::IsLess(float a, float b, float epsilon)
    {
        return definitelyLessThan(a, b, epsilon);
    }

    bool NumericComparer::IsEqual(double a, double b, double epsilon)
    {
        return essentiallyEqual(a, b, epsilon);
    }

    bool NumericComparer::IsGreater(double a, double b, double epsilon)
    {
        return definitelyGreaterThan(a, b, epsilon);
    }
    
    bool NumericComparer::IsLess(double a, double b, double epsilon)
    {
        return definitelyLessThan(a, b, epsilon);
    }
}