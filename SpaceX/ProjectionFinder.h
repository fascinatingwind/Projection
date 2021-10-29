#pragma once
#include "dllexport.h"

#include "FPoint3D.h"
#include "FLine3D.h"
#include "SolutionStore.h"

namespace SpaceX
{
	// Contain methods for find projection point for poly line
	class SpaceX_ExportDll ProjectionFinder
	{
	public:
		ProjectionFinder() = delete;
		~ProjectionFinder() = delete;

		// Returns the projection point of a line segment.
		static SolutionStore FindNearPointProjection(
			const FLine3D& line, const FPoint3D& input_point);

		// Returns all projection points of a poly line
		static std::vector<SolutionStore> FindNearPointsProjection(
			const std::vector<FPoint3D>& poly_line, const FPoint3D& input_point);
	};
}