#pragma once
#ifndef PROJECTION_FINDER_H
#define PROJECTION_FINDER_H

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
	
		// Returns all projection points of a poly line
		static std::list<SolutionStore> FindNearPointsProjection(
			const std::vector<FPoint3D>& poly_line, const FPoint3D& input_point);
	
	private:
		// Build line from neighboring points
		static std::vector<FLine3D> GetLinesFromVectorPoints(const std::vector<FPoint3D>& poly_line);

		// Returns the projection point of a line segment.
		static SolutionStore FindNearPointProjection(
			const FLine3D& line, const FPoint3D& input_point);

	};
}

#endif // !PROJECTION_FINDER_H