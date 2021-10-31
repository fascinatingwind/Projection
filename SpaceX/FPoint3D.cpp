#include "FPoint3D.h"

#include "NumericComparer.h"

namespace SpaceX
{
	FPoint3D::FPoint3D(float x, float y, float z)
		: m_X(x), m_Y(y), m_Z(z)
	{
	}

	float FPoint3D::X() const
	{
		return m_X;
	}

	float FPoint3D::Y() const
	{
		return m_Y;
	}

	float FPoint3D::Z() const
	{
		return m_Z;
	}

	bool FPoint3D::operator==(const FPoint3D& other) const
	{
		return NumericComparer::IsEqual(m_X, other.m_X)
			&& NumericComparer::IsEqual(m_Y, other.m_Y)
			&& NumericComparer::IsEqual(m_Z, other.m_Z);
	}
	FPoint3D& FPoint3D::operator+=(const FPoint3D& other)
	{
		m_X += other.m_X;
		m_Y += other.m_Y;
		m_Z += other.m_Z;

		return *this;
	}

	FPoint3D FPoint3D::operator+(const FPoint3D& other) const
	{
		return FPoint3D(m_X + other.m_X, m_Y + other.m_Y, m_Z + other.m_Z);
	}
	FPoint3D FPoint3D::operator-(const FPoint3D& other) const
	{
		return FPoint3D(m_X - other.m_X, m_Y - other.m_Y, m_Z - other.m_Z);
	}

	FPoint3D FPoint3D::operator-() const
	{
		return FPoint3D(-m_X, -m_Y, -m_Z);
	}

	FPoint3D FPoint3D::operator*(const FPoint3D& other) const
	{
		return FPoint3D(m_X * other.m_X, m_Y * other.m_Y, m_Z * other.m_Z);
	}

	float FPoint3D::Sum() const
	{
		return m_X + m_Y + m_Z;
	}

	bool FPoint3D::operator<(const FPoint3D& other) const
	{
		return m_X < other.m_X 
			|| (NumericComparer::IsEqual(m_X, other.m_X) && m_Y < other.m_Y)
			|| (NumericComparer::IsEqual(m_X, other.m_X) 
				&& NumericComparer::IsEqual(m_Y, other.m_Y) && m_Z < other.m_Z);
	}

	bool FPoint3D::operator>(const FPoint3D& other) const
	{
		return !operator<(other) && !operator==(other);
	}
}