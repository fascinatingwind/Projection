#pragma once
#include "dllexport.h"

#include "NumericComparer.h"

namespace SpaceX
{
	template<class T>
	struct SpaceX_ExportDll TPoint3D
	{
		T X;
		T Y;
		T Z;

		TPoint3D() = default;
		~TPoint3D() = default;

		explicit TPoint3D(T x, T y, T z) : X (x), Y(y), Z(z){}

		std::array<T, 3> GetArray() const
		{
			return { X, Y, Z };
		}
	};
}