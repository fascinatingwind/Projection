#include "pch.h"
#include "KramerProjectionSolverTest.h"

#include "KramerProjectionSolver.h"

using namespace SpaceX;

TEST_F(KramerProjectionSolverTest, Should_return_trivial)
{
	KramerProjectionSolver solver; 
	const auto projection_point = solver.CalculateProjection(
		FLine3D(FPoint3D(1, 0, 0), FPoint3D(2, 1, 0)), FPoint3D(2, 0.5, 0.5));

	ASSERT_EQ(FPoint3D(1.75, 0.75, 0), projection_point);
}