#pragma once

#include "FMatrix3x3.h"
#include "FLine3D.h"

namespace SpaceX
{
	class RepresentationHelper
	{
	public:
		RepresentationHelper() = delete;
		~RepresentationHelper() = delete;

		static FMatrix3x3 GetMatrixRepresentation(const FLine3D& line);

		// Should I rework it for checking zero rows and cols for found a solution
		// In case det M = 0 we have no solutions or infinity count solution
		static std::array<FPoint3D, 2> Get2NonZeroRows(const FMatrix3x3& matrix);
	};
}