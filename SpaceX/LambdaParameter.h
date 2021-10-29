#pragma once
#include "dllexport.h"

#include "FLine3D.h"
#include "FPoint3D.h"

namespace SpaceX
{
	// Store method for find lambda parameter
	class SpaceX_ExportDll LambdaParameter
	{
	public:
		LambdaParameter() = delete;
		~LambdaParameter() = delete;

		// Find lambda parameter for segment line and point on line
		static float CalculateLambda(const FLine3D& line, const FPoint3D& projection_point);
	};
}