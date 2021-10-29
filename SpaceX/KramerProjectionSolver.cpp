#include "KramerProjectionSolver.h"
#include "FMatrix3x3.h"
#include "Matrix3DHelper.h"

namespace SpaceX
{
	FPoint3D KramerProjectionSolver::CalculateProjection(const FLine3D& line,
		const FPoint3D& point) const
	{
		const auto matrix_representation = Matrix3DHelper::GetMatrixRepresentation(line);
		
		// Get part of SLE
		// if lineAsPlanes have zero row
		const auto lineAsPlanes = Matrix3DHelper::Get2NonZeroRows(matrix_representation);
		
		const auto normal = line.GetNormal();
		const auto pointA = line.GetStartPoint();

		const FMatrix3x3 matrixM(
			lineAsPlanes.front(),
			lineAsPlanes.back(),
			FPoint3D(normal.X, normal.Y, normal.Z));

		const FPoint3D pointP(
			pointA.X * normal.Y - pointA.Y * normal.X,
			pointA.X * normal.Z - pointA.Z * normal.X,
			point.X * normal.X + point.Y * normal.Y + point.Z * normal.Z
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
