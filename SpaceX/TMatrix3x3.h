#pragma once
#include <array>

#include "TPoint3D.h"

namespace SpaceX
{
	template <class T>
	class TMatrix3x3
	{
	public:
		TMatrix3x3() = default;
		~TMatrix3x3() = default;

		T Determinant() const
		{
			T sum = 0;
			
			// calc main diag
			for (int j = 0; j < m_dimension; j++)
			{
				T multiply = 1;
				for (int i = 0; i < m_dimension; i++)
				{
					multiply *= m_array[i][(i + j) % m_dimension];
				}
				sum += multiply;
			}
			
			// calc second diag
			for (int j = m_dimension - 1; j >= 0; --j)
			{
				T multiply = 1;
				for (int i = 0; i < m_dimension; i++)
				{
					multiply *= m_array[(i + j) % m_dimension][i];
				}
				sum -= multiply;
			}
			
			return sum;
		}

		void SetRow(const TPoint3D<T>& point, size_t row)
		{
			if (row >= m_dimension || row < 0)
				return;

			m_array[row] = point.GetArray();
		}

		void SetColumn(const TPoint3D<T>& point, size_t column)
		{
			if (column >= m_dimension || column < 0)
				return;

			const auto point_array = point.GetArray();

			for (int i = 0; i < m_dimension; i++)
			{
				m_array[i][column] = point_array[i];
			}
		}

	private:
		constexpr static size_t m_dimension = 3;
		std::array<std::array<T, m_dimension>, m_dimension> m_array;
	};
}