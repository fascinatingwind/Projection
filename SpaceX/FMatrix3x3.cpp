#include "FMatrix3x3.h"

#include "NumericComparer.h"

namespace SpaceX
{
    bool FMatrix3x3::operator==(const FMatrix3x3& other) const
    {
        for (int row = 0; row < m_dimension; row++)
        {
            for (int col = 0; col < m_dimension; col++)
            {
                if (!NumericComparer::IsEqual(m_array[row][col], other.m_array[row][col]))
                    return false;
            }
        }
        return true;
    }
}