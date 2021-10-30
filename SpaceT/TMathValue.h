#pragma once
#include "dllexport.h"

namespace SpaceT
{
	// Template class with math operation for inner calculus system
	// It may be fnumber : public MathValue<float>
	template<class T>
	class SpaceT_ExportDll TMathValue
	{
	public:
		TMathValue() = default;
		virtual ~TMathValue() = default;

		// Initializer.
		TMathValue(T value) 
			: m_value(value)
		{
		}

		// Compare values.
		bool operator==(const T& other) const
		{
			return m_value == other;
		}

		// Compare values.
		bool operator!=(const T& other) const
		{
			return m_value != other;
		}

		// Return sum of two values.
		T operator+(const T& other) const
		{
			return m_value + other;
		}

		// Return increment value by another one.
		T& operator+=(const T& other)
		{
			m_value += other;
			return *this;
		}
		
		// Return decrement value by another one.
		T& operator-=(const T& other)
		{
			m_value -= other;
			return *this;
		}

		// Return difference of two values.
		T operator-(const T& other) const
		{
			return m_value - other;
		}

		// Return a negative value.
		T operator-() const
		{
			return -m_value;
		}

		// Return the product of two values.
		T operator*(const T& other) const
		{
			return m_value * other;
		}

		// Check if one value is less than another.
		bool operator<(const T& other) const
		{
			return m_value < other;
		}

		// Check if one value is greater than another.
		bool operator>(const T& other) const
		{
			return m_value > other;
		}

	private:
		T m_value;
	};
}