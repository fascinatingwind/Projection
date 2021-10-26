#include "FLine.h"

namespace SpaceX
{
	void FLine::AppendPoint(const FPoint3D& point)
	{
		m_points.push_back(point);
	}
}
