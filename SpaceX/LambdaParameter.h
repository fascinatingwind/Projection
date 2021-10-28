#pragma once
#include "dllexport.h"

#include "FLine3D.h"
#include "FPoint3D.h"

namespace SpaceX
{
	class SpaceX_ExportDll LambdaParameter
	{
	public:
		LambdaParameter() = delete;
		~LambdaParameter() = delete;

		static float CalculateLambda(const FLine3D& line, const FPoint3D& projection_point);
	};
}