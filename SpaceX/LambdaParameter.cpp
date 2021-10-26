#include "LambdaParameter.h"

namespace SpaceX
{
	float LambdaParameter::CalculateLambda(const FLine3D& line)
	{
		return	(line.GetStartPoint() * (line.GetStartPoint() - line.GetEndPoint())).Sum() / (line.GetNormal() * line.GetNormal()).Sum();
	}
}
