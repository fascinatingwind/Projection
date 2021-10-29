#include "NumericComparer.h"

namespace SpaceX
{
    bool NumericComparer::IsEqual(float a, float b, float epsilon)
    {
        return std::abs(a - b) <= std::max(a, b) * epsilon;
    }

    bool NumericComparer::IsGreater(float a, float b, float epsilon)
    {
        return (a - b) > std::max(a, b) * epsilon;
    }

    bool NumericComparer::IsLess(float a, float b, float epsilon)
    {
        return (b - a) > std::max(a, b) * epsilon;
    }
}