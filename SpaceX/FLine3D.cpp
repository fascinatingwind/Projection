#include "FLine3D.h"

namespace SpaceX
{
	FLine3D::FLine3D(const FPoint3D& point1, const FPoint3D& point2)
	{
		InsertPoint(point1, 0);
		InsertPoint(point2, 1);
	}

	void FLine3D::InsertPoint(const FPoint3D& point, size_t pos)
	{
		if (pos < 0 || pos > size)
			return;

		m_points[pos] = point;
	}
	
	FPoint3D FLine3D::GetNormal() const
	{
		return m_points[1] - m_points[0];
	}
	
	FPoint3D FLine3D::GetUpperPoint() const
	{
		return -m_points[0];
	}
}
