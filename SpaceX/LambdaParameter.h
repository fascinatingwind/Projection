#pragma once
#include "FLine3D.h"

namespace SpaceX
{
	class LambdaParameter
	{
	public:
		LambdaParameter() = delete;
		~LambdaParameter() = delete;

		static float CalculateLambda(const FLine3D& line, const FPoint3D& projection_point);
	};
}