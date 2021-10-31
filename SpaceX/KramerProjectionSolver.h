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
		KramerProjectionSolver() = delete;
		~KramerProjectionSolver() = delete;

		// Find projection point using Kramer's method for solve SLE
		static FPoint3D CalculateProjection(const FLine3D& line, const FPoint3D& point);
	
	private:
		// Return matrix representation of line in 3d space
		static FMatrix3x3 GetMatrixRepresentation(const FLine3D& line);
		
		// Return two non zero points from matrix in 3d space
		static std::array<FPoint3D, 2> Get2NonZeroRows(const FMatrix3x3& matrix);
	};
}