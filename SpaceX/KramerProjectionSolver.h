#pragma once

#include "IProjectionPoint3D.h"

namespace SpaceX
{
	class KramerProjectionSolver final : public IProjectionPoint3D
	{
	public:
		KramerProjectionSolver() = default;
		~KramerProjectionSolver() = default;

		FPoint3D CalculateProjection(const FLine3D& line, const FPoint3D& point) override;
	};
}