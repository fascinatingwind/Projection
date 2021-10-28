#pragma once

#include "FLine3D.h"
#include "FPoint3D.h"

namespace SpaceX
{
	class IProjectionPoint3D
	{
	public:
		IProjectionPoint3D() = default;
		~IProjectionPoint3D() = default;

		virtual FPoint3D CalculateProjection(const FLine3D& line, const FPoint3D& point) = 0;
	};
}