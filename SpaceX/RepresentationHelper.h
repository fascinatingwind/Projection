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
	};
}