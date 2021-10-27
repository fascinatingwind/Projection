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

	bool FMatrix3x3::IsZeroRow(size_t row) const
	{
		// should be better way using accumulate for rid of explicit column set
		return NumericComparer::IsEqual(m_array[row][0], 0.f)
			&& NumericComparer::IsEqual(m_array[row][1], 0.f)
			&& NumericComparer::IsEqual(m_array[row][2], 0.f);
	}

	bool FMatrix3x3::IsZeroColumn(size_t column) const
	{
		// should be better way using accumulate for rid of explicit row set
		return NumericComparer::IsEqual(m_array[0][column], 0.f)
			&& NumericComparer::IsEqual(m_array[1][column], 0.f)
			&& NumericComparer::IsEqual(m_array[2][column], 0.f);
	}

	FPoint3D FMatrix3x3::GetRow(size_t row) const
	{
		if (row >= m_dimension || row < 0)
			return FPoint3D();

		return FPoint3D(m_array[row][0], m_array[row][1], m_array[row][2]);
	}
}