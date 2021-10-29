#include "Matrix3DHelper.h"

namespace SpaceX
{
	FMatrix3x3 Matrix3DHelper::GetMatrixRepresentation(const FLine3D& line)
	{
		const auto revert = line.GetStartPoint() - line.GetEndPoint();
		const auto normal = line.GetNormal();
		return FMatrix3x3(
			FPoint3D(normal.Y, revert.X, 0),
			FPoint3D(normal.Z, 0, revert.X),
			FPoint3D(0, normal.Z, normal.Y)
		);
	}

	std::array<FPoint3D, 2> Matrix3DHelper::Get2NonZeroRows(const FMatrix3x3& matrix)
	{
		std::array<FPoint3D, 2> result = { FPoint3D(), FPoint3D() };
		int step = 0;
		for (int row = 0; row < FMatrix3x3::GetDimension(); row++)
		{
			if (!matrix.IsZeroRow(row))
			{
				result[step] = matrix.GetRow(row);
				step++;
				if (step == 2)
					break;
			}
		}
		return result;
	}
}
