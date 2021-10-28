#pragma once

#include "FPoint3D.h"

namespace Projection
{
	using namespace SpaceX;

	class FPoint3DParser
	{
	public:
		FPoint3DParser() = delete;
		~FPoint3DParser() = delete;

		static FPoint3D GetPoint(const std::string& string);
		static std::vector<FPoint3D> GetPoints(const std::vector<std::string>& string);
	};
}