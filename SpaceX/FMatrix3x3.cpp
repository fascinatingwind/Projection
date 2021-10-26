#include "FMatrix3x3.h"

#include "NumericComparer.h"

namespace SpaceX
{
    FMatrix3x3::FMatrix3x3(
        const FPoint3D& row0, 
        const FPoint3D& row1, 
        const FPoint3D& row2)
    {
        m_array[0] = row0.GetArray();
        m_array[1] = row1.GetArray();
        m_array[2] = row2.GetArray();
    }

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