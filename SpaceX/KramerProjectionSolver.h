#pragma once

#include "dllexport.h"

#include "FPoint3D.h"
#include "FLine3D.h"
#include "FMatrix3x3.h"

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
	
	protected:
		// Return matrix representation of line in 3d space
		FMatrix3x3 GetMatrixRepresentation(const FLine3D& line) const;
		
		// Return two non zero points from matrix in 3d space
		std::array<FPoint3D, 2> Get2NonZeroRows(const FMatrix3x3& matrix) const;
	};
}