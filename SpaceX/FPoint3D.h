#pragma once
#include "dllexport.h"

#include "TPoint.h"

namespace SpaceX
{
	class SpaceX_ExportDll FPoint3D : public TPoint3D<float>
	{
	public:
		FPoint3D() = default;
		~FPoint3D() = default;

		explicit FPoint3D(float x, float y, float z);

		bool operator==(const FPoint3D& other);
	};
}