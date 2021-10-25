#pragma once
#include "dllexport.h"

#include "FPoint.h"

namespace SpaceX
{
	class SpaceX_ExportDll FLine
	{
	public:
		FLine() = default;
		~FLine() = default;

		void AppendPoint(const FPoint& point);

	protected:
		std::vector<FPoint> m_points;
	};
}