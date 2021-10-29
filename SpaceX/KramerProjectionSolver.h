#pragma once

#include "dllexport.h"

#include "FPoint3D.h"
#include "FLine3D.h"

namespace SpaceX
{
	// Store method for find projection point
	class SpaceX_ExportDll KramerProjectionSolver 
	{
	public:
		KramerProjectionSolver() = default;
		~KramerProjectionSolver() = default;

		// Find projection point using Kramer's method for solve SLE
		FPoint3D CalculateProjection(const FLine3D& line, const FPoint3D& point) const;
	};
}