#pragma once
#include "dllexport.h"

#include "FPoint3D.h"

namespace SpaceX
{
	class SpaceX_ExportDll FLine
	{
	public:
		FLine() = default;
		~FLine() = default;

		void AppendPoint(const FPoint3D& point);

	protected:
		std::vector<FPoint3D> m_points;
	};
}