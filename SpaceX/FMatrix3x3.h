#pragma once
#include "dllexport.h"

#include "TMatrix3x3.h"
#include "FPoint3D.h"

namespace SpaceX
{
	class SpaceX_ExportDll FMatrix3x3 : public TMatrix3x3<float>
	{
	public:
		FMatrix3x3() = default;
		~FMatrix3x3() = default;
		explicit FMatrix3x3(
			const FPoint3D& row0, 
			const FPoint3D& row1, 
			const FPoint3D& row2);

		bool operator==(const FMatrix3x3& other) const;
	};
}