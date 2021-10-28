#include "FPoint3D.h"

#include "NumericComparer.h"

namespace SpaceX
{
	FPoint3D::FPoint3D(float x, float y, float z)
		: TPoint3D(x, y, z)
	{
	}

	bool FPoint3D::operator==(const FPoint3D& other) const
	{
		return NumericComparer::IsEqual(X, other.X)
			&& NumericComparer::IsEqual(Y, other.Y)
			&& NumericComparer::IsEqual(Z, other.Z);
	}
	FPoint3D& FPoint3D::operator+=(const FPoint3D& other)
	{
		X += other.X;
		Y += other.Y;
		Z += other.Z;

		return *this;
	}

	FPoint3D FPoint3D::operator+(const FPoint3D& other) const
	{
		return FPoint3D(X + other.X, Y + other.Y, Z + other.Z);
	}
	FPoint3D FPoint3D::operator-(const FPoint3D& other) const
	{
		return FPoint3D(X - other.X, Y - other.Y, Z - other.Z);
	}

	FPoint3D FPoint3D::operator-() const
	{
		return FPoint3D(-X, -Y, -Z);
	}

	FPoint3D FPoint3D::operator*(const FPoint3D& other) const
	{
		return FPoint3D(X * other.X, Y * other.Y, Z * other.Z);
	}

	float FPoint3D::Sum() const
	{
		return X + Y + Z;
	}

	bool FPoint3D::operator<(const FPoint3D& other) const
	{
		return X < other.X && Y < other.Y && Z < other.Z;
	}

	bool FPoint3D::operator>(const FPoint3D& other) const
	{
		return !operator<(other) && !operator==(other);
	}
}