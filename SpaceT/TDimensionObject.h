#pragma once
#include "dllexport.h"

namespace SpaceT
{
	template<class T, size_t S>
	class SpaceT_ExportDll TDimensionObject
	{
	public:
		TDimensionObject() = default;
		virtual ~TDimensionObject() = default;

		template<class... T>
		TDimensionObject(T... args)
		{
			m_values = { args... };
		}

		// Compare values.
		bool operator==(const TDimensionObject<T, S>& other) const
		{
			assert(m_size == other.m_size);

			for (size_t i = 0; i < m_size; i++)
			{
				if (m_values[i] != other.m_values[i])
				{
					return false;
				}
			}

			return true;
		}

		// Compare values.
		bool operator!=(const TDimensionObject<T, S>& other) const
		{
			return !operator==(other);
		}

		// Return sum of two values.
		TDimensionObject<T, S> operator+(const TDimensionObject<T, S>& other) const
		{
			assert(m_size == other.m_size);
			TDimensionObject<T, S> result;
			for (size_t i = 0; i < m_size; i++)
			{
				result.m_values[i] = m_values[i] + other.m_values[i];
			}

			return result;
		}

		// Return increment value by another one.
		TDimensionObject<T, S>& operator+=(const TDimensionObject<T, S>& other)
		{
			assert(m_size == other.m_size);
			for (size_t i = 0; i < m_size; i++)
			{
				m_values[i] += other.m_values[i];
			}

			return *this;
		}

		// Return difference of two values.
		TDimensionObject<T, S> operator-(const TDimensionObject<T, S>& other) const
		{
			assert(m_size == other.m_size);
			TDimensionObject<T, m_size> result;
			for (size_t i = 0; i < S; i++)
			{
				result.m_values[i] = m_values[i] - other.m_values[i];
			}

			return result;
		}

		// Return a negative value.
		TDimensionObject<T, S> operator-() const
		{
			TDimensionObject<T, S> result;
			for (size_t i = 0; i < m_size; i++)
			{
				result.m_values[i] = -m_values[i];
			}

			return result;
		}

		// Return the product of two values.
		TDimensionObject<T, S> operator*(const TDimensionObject<T, S>& other) const
		{
			assert(m_size == other.m_size);
			TDimensionObject<T, S> result;
			for (size_t i = 0; i < m_size; i++)
			{
				result.m_values[i] = m_values[i] * other.m_values[i];
			}

			return result;
		}

		// Check if one value is less than another.
		bool operator<(const TDimensionObject<T, S>& other) const
		{
			assert(m_size == other.m_size);
			for (size_t i = 0; i < m_size; i++)
			{
				if (m_values[i] >= other.m_values[i])
					return false;
			}

			return true;
		}

		// Check if one value is greater than another.
		bool operator>(const TDimensionObject<T, S>& other) const
		{
			assert(m_size == other.m_size);
			for (size_t i = 0; i < m_size; i++)
			{
				if (m_values[i] <= other.m_values[i])
					return false;
			}

			return true;
		}

		size_t GetSize() const
		{
			return m_values.size();
		}

	protected:
		size_t m_size = S;
		std::array<T, S> m_values;
	};
}