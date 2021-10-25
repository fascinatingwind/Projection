#include "FLine.h"

namespace SpaceX
{
	void FLine::AppendPoint(const FPoint& point)
	{
		m_points.push_back(point);
	}
}
