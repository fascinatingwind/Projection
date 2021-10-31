#include "KramerProjectionSolver.h"

#include <stdexcept>

#include "NumericComparer.h"

namespace SpaceX
{
	FPoint3D KramerProjectionSolver::CalculateProjection(const FLine3D& line,
		const FPoint3D& point) 
	{
		const auto matrix_representation = GetMatrixRepresentation(line);
		
		// Get part of SLE
		// if lineAsPlanes have zero row
		const auto lineAsPlanes = Get2NonZeroRows(matrix_representation);
		
		const auto normal = line.GetNormal();
		const auto pointA = line.GetStartPoint();

		const FMatrix3x3 matrixM(
			lineAsPlanes.front(),
			lineAsPlanes.back(),
			FPoint3D(normal.X(), normal.Y(), normal.Z()));

		const FPoint3D pointP(
			pointA.X() * normal.Y() - pointA.Y() * normal.X(),
			pointA.X() * normal.Z() - pointA.Z() * normal.X(),
			point.X() * normal.X() + point.Y() * normal.Y() + point.Z() * normal.Z()
		);

		const auto detM = matrixM.Determinant();
		if (NumericComparer::IsEqual(detM, 0.f))
		{
			throw std::runtime_error("Devide by zero exception.");
		}
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
	
	FMatrix3x3 KramerProjectionSolver::GetMatrixRepresentation(const FLine3D& line)
	{
		const auto revert = line.GetStartPoint() - line.GetEndPoint();
		const auto normal = line.GetNormal();
		return FMatrix3x3(
			FPoint3D(normal.Y(), revert.X(), 0),
			FPoint3D(normal.Z(), 0, revert.X()),
			FPoint3D(0, normal.Z(), normal.Y())
		);
	}
	
	std::array<FPoint3D, 2> KramerProjectionSolver::Get2NonZeroRows(const FMatrix3x3& matrix)
	{
		std::array<FPoint3D, 2> result = { FPoint3D(), FPoint3D() };
		size_t step = 0;
		for (size_t row = 0; row < FMatrix3x3::GetDimension(); row++)
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
