#pragma once
#include "dllexport.h"

#include "FPoint3D.h"

namespace SpaceX
{
	// Line in 3d space using float numbers
	class SpaceX_ExportDll FLine3D
	{
	public:
		FLine3D() = default;
		~FLine3D() = default;
		
		// Initialize constructor.
		FLine3D(const FPoint3D& point1, const FPoint3D& point2);
		
		// Return normal vector of line.
		FPoint3D GetNormal() const;

		// Return point1
		FPoint3D GetStartPoint() const;
		// Return point2
		FPoint3D GetEndPoint() const;

	protected:
		constexpr static size_t size = 2;
		std::array<FPoint3D, size> m_points;
	};
}