#include "KramerProjectionSolver.h"
#include "FMatrix3x3.h"

namespace SpaceX
{
	FPoint3D KramerProjectionSolver::CalculateProjection(const FLine3D& line,
		const FPoint3D& point)
	{
		const auto normal = line.GetNormal();
		const auto pointA = line.GetStartPoint();
		const auto pointB = line.GetEndPoint();
		const auto revert = pointA - pointB;

		const FMatrix3x3 matrixM(
			FPoint3D(normal.Y, revert.X, 0),
			FPoint3D(normal.Z, 0, revert.X),
			FPoint3D(normal.X, normal.Y, normal.Z));

		const FPoint3D pointP(
			pointA.X * normal.Y + pointA.Y * normal.X,
			pointA.X * normal.Z + pointA.Z * normal.X,
			point.X * revert.X + point.Y * revert.Y + point.Z * revert.Z
		);

		const auto detM = matrixM.Determinant();

		FMatrix3x3 temp_matrix = matrixM;
		temp_matrix.SetColumn(pointP, 0);
		const auto detXM = temp_matrix.Determinant();

		temp_matrix = matrixM;
		temp_matrix.SetColumn(pointP, 1);
		const auto detYM = temp_matrix.Determinant();

		temp_matrix = matrixM;
		temp_matrix.SetColumn(pointP, 2);
		const auto detZM = temp_matrix.Determinant();

		return FPoint3D(detXM / detM, detYM / detM, detZM / detM);
	}
}
