#include "FLine.h"

namespace SpaceX
{
	void FLine::InsertPoint(const FPoint3D& point, size_t pos)
	{
		if (pos < 0 || pos > size)
			return;

		m_points[pos] = point;
	}
	
	FPoint3D FLine::GetNormal() const
	{
		return m_points[1] - m_points[0];
	}
	
	FPoint3D FLine::GetUpperPoint() const
	{
		return -m_points[0];
	}
}
