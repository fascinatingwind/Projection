#include "FMatrix3x3.h"

#include <stdexcept>

#include "NumericComparer.h"

namespace SpaceX
{
	FMatrix3x3::FMatrix3x3(
		const FPoint3D& row0,
		const FPoint3D& row1,
		const FPoint3D& row2)
	{
		m_array[0][0] = row0.X();
		m_array[0][1] = row0.Y();
		m_array[0][2] = row0.Z();

		m_array[1][0] = row1.X();
		m_array[1][1] = row1.Y();
		m_array[1][2] = row1.Z();

		m_array[2][0] = row2.X();
		m_array[2][1] = row2.Y();
		m_array[2][2] = row2.Z();
	}

	bool FMatrix3x3::operator==(const FMatrix3x3& other) const
	{
		for (size_t row = 0; row < m_dimension; row++)
		{
			for (size_t col = 0; col < m_dimension; col++)
			{
				if (!NumericComparer::IsEqual(m_array[row][col], other.m_array[row][col]))
					return false;
			}
		}
		return true;
	}

	bool FMatrix3x3::IsZeroRow(size_t row) const
	{
		if (row > m_dimension || row < 0)
			throw std::runtime_error("Incorrect index : " + std::to_string(row));

		return NumericComparer::IsEqual(m_array[row][0], 0.f)
			&& NumericComparer::IsEqual(m_array[row][1], 0.f)
			&& NumericComparer::IsEqual(m_array[row][2], 0.f);
	}

	FPoint3D FMatrix3x3::GetRow(size_t row) const
	{
		if (row > m_dimension || row < 0)
			return FPoint3D();

		return FPoint3D(m_array[row][0], m_array[row][1], m_array[row][2]);
	}

	float FMatrix3x3::Determinant() const
	{
		float sum = 0;

		// calc main diag
		for (size_t shift = 0; shift < m_dimension; shift++)
		{
			float multiply = 1;
			for (size_t col = 0; col < m_dimension; col++)
			{
				multiply *= m_array[col][(col + shift) % m_dimension];
			}
			sum += multiply;
		}

		// calc second diag
		for (size_t shift = 0; shift < m_dimension; shift++)
		{
			float multiply = 1;
			for (size_t col = 0; col < m_dimension; col++)
			{
				multiply *= m_array[m_dimension - col - 1][(col + shift) % m_dimension];
			}
			sum -= multiply;
		}

		return sum;
	}

	void FMatrix3x3::SetRow(const FPoint3D& point, size_t row)
	{
		assert(row >= 0 && row <= m_dimension);
		if (row > m_dimension || row < 0)
			return;

		m_array[row][0] = point.X();
		m_array[row][1] = point.Y();
		m_array[row][2] = point.Z();
	}

	void FMatrix3x3::SetColumn(const FPoint3D& point, size_t column)
	{
		assert(column >= 0 && column <= m_dimension);
		if (column >= m_dimension || column < 0)
			return;

		m_array[0][column] = point.X();
		m_array[1][column] = point.Y();
		m_array[2][column] = point.Z();
	}

	size_t FMatrix3x3::GetDimension()
	{
		return m_dimension;
	}
}