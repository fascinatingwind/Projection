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
		return NumericComparer::IsEqual(m_x, other.m_x)
			&& NumericComparer::IsEqual(m_y, other.m_y)
			&& NumericComparer::IsEqual(m_y, other.m_y);
	}
}