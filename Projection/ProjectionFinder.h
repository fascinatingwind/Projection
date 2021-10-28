#pragma once

#include "FPoint3D.h"
#include "FLine3D.h"
#include "SolutionStore.h"

namespace Projection
{
	using namespace SpaceX;

	class ProjectionFinder
	{
	public:
		ProjectionFinder() = delete;
		~ProjectionFinder() = delete;

		static SolutionStore FindNearPointProjection(
			const FLine3D& line, const FPoint3D& input_point);

		static std::vector<SolutionStore> FindNearPointsProjection(
			const std::vector<FPoint3D>& poly_line, const FPoint3D& input_point);
	};
}