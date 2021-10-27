#include "RepresentationHelper.h"

namespace SpaceX
{
	FMatrix3x3 RepresentationHelper::GetMatrixRepresentation(const FLine3D& line)
	{
		const auto revert = line.GetStartPoint() - line.GetEndPoint();
		const auto normal = line.GetNormal();
		return FMatrix3x3(
			FPoint3D(normal.Y, revert.X, 0),
			FPoint3D(normal.Z, 0, revert.X),
			FPoint3D(0, normal.Z, normal.Y)
		);
	}
}
