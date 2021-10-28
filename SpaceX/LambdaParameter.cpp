#include "LambdaParameter.h"

namespace SpaceX
{
	float LambdaParameter::CalculateLambda(const FLine3D& line,
		const FPoint3D& projection_point)
	{
		const auto normal = line.GetNormal();
		return ((projection_point - line.GetStartPoint()) * (normal)).Sum() / (normal * normal).Sum();
	}
}
