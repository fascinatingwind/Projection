#include "FPoint.h"

#include "NumericComparer.h"

namespace SpaceX
{
	FPoint::FPoint(float x, float y, float z)
		: TPoint(x, y, z)
	{
	}

	bool FPoint::operator==(const FPoint& other)
	{
		return NumericComparer::IsEqual(m_x, other.m_x)
			&& NumericComparer::IsEqual(m_y, other.m_y)
			&& NumericComparer::IsEqual(m_y, other.m_y);
	}
}