#pragma once
#include "dllexport.h"

#include "TPoint3D.h"

namespace SpaceX
{
	struct SpaceX_ExportDll FPoint3D : public TPoint3D<float>
	{
	public:
		FPoint3D() = default;
		~FPoint3D() = default;

		explicit FPoint3D(float x, float y, float z);

		bool operator==(const FPoint3D& other) const;

		FPoint3D& operator+=(const FPoint3D& other);

		FPoint3D operator+(const FPoint3D& other) const;

		FPoint3D operator-(const FPoint3D& other) const;
		
		FPoint3D operator-() const;
	};
}