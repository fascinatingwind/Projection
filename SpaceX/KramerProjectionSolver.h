#pragma once

#include "dllexport.h"

#include "IProjectionPoint3D.h"

namespace SpaceX
{
	class SpaceX_ExportDll KramerProjectionSolver final : public IProjectionPoint3D
	{
	public:
		KramerProjectionSolver() = default;
		~KramerProjectionSolver() = default;

		FPoint3D CalculateProjection(const FLine3D& line, const FPoint3D& point) override;
	};
}