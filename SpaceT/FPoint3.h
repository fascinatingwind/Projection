#pragma once
#include "dllexport.h"

#include "TDimensionObject.h"

namespace SpaceT
{
	class SpaceT_ExportDll FPoint3 final : public TDimensionObject<float, 3>
	{
	public:
		FPoint3() = default;
		virtual ~FPoint3() = default;

		FPoint3(float x, float y, float z);
	};
}