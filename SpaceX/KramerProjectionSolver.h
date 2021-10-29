#pragma once

#include "dllexport.h"

#include "FPoint3D.h"
#include "FLine3D.h"

namespace SpaceX
{
	class SpaceX_ExportDll KramerProjectionSolver 
	{
	public:
		KramerProjectionSolver() = default;
		~KramerProjectionSolver() = default;

		FPoint3D CalculateProjection(const FLine3D& line, const FPoint3D& point) const;
	};
}