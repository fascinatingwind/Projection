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

		void InsertPoint(const FPoint3D& point, size_t pos);
		
		// return (x2-x1, y2 - y1, z2 - z1) from canonical equation
		// x - x1   y - y1   z - z1
		// ------ = ------ = -------
		// x2 - x1  y2 - y1  z2 - z1
		FPoint3D GetNormal() const;

		// return (-x1, -y1, -z1) from canonical equation
		// x - x1   y - y1   z - z1
		// ------ = ------ = -------
		// x2 - x1  y2 - y1  z2 - z1
		FPoint3D GetUpperPoint() const;

	protected:
		constexpr static size_t size = 2;
		std::array<FPoint3D, size> m_points;
	};
}