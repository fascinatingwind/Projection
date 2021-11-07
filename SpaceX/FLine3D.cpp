#include "FLine3D.h"
#include <stdexcept>

namespace SpaceX
{
	FLine3D::FLine3D(const FPoint3D& point1, const FPoint3D& point2)
	{
		if (point1 == point2)
		{
			throw std::runtime_error("Points for line is equal = "
				+ point1.ToString() + " and " + point2.ToString());
		}

		m_points.front() = point1;
		m_points.back() = point2;
	}
	
	FPoint3D FLine3D::GetNormal() const
	{
		return m_points.back() - m_points.front();
	}
	
	FPoint3D FLine3D::GetStartPoint() const
	{
		return m_points.front();
	}
	
	FPoint3D FLine3D::GetEndPoint() const
	{
		return m_points.back();
	}
}
