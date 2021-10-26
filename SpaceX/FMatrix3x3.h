#pragma once
#include "dllexport.h"

#include "TMatrix3x3.h"

namespace SpaceX
{
	class SpaceX_ExportDll FMatrix3x3 : public TMatrix3x3<float>
	{
	public:
		FMatrix3x3() = default;
		~FMatrix3x3() = default;
	};
}