#pragma once
#include "dllexport.h"

#include "TPoint.h"

namespace SpaceX
{
	class SpaceX_ExportDll FPoint : public TPoint<float>
	{
	public:
		FPoint() = default;
		~FPoint() = default;

		explicit FPoint(float x, float y, float z);

		bool operator==(const FPoint& other);
	};
}