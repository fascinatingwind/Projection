#pragma once
#include "dllexport.h"

#include "FPoint3D.h"

namespace SpaceX
{
	class SpaceX_ExportDll FLine3D
	{
	public:
		FLine3D() = default;
		~FLine3D() = default;
		
		FLine3D(const FPoint3D& point1, const FPoint3D& point2);
		
		FPoint3D GetNormal() const;

		FPoint3D GetStartPoint() const;
		FPoint3D GetEndPoint() const;

	protected:
		constexpr static size_t size = 2;
		std::array<FPoint3D, size> m_points;
	};
}