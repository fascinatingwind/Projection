#pragma once

#include "FPoint3D.h"

namespace Projection
{
	using namespace SpaceX;

	// Class for parsing 3d points from strings
	class FPoint3DParser
	{
	public:
		FPoint3DParser() = delete;
		~FPoint3DParser() = delete;

		// Parse strings like "3.4 0.1 3" by space delimiter
		static FPoint3D GetPoint(const std::string& string);
		// Parse vector of strings using function above
		static std::vector<FPoint3D> GetPoints(const std::vector<std::string>& string);
	};
}