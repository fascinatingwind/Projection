#include "LambdaParameter.h"

namespace SpaceX
{
	float LambdaParameter::CalculateLambda(const FLine3D& line, const FPoint3D& projection_point)
	{
		return	(projection_point * (line.GetStartPoint() - line.GetEndPoint())).Sum() / (line.GetNormal() * line.GetNormal()).Sum();
	}
}
