#include "pch.h"
#include "KramerProjectionSolverTest.h"

#include "KramerProjectionSolver.h"

using namespace SpaceX;

TEST_F(KramerProjectionSolverTest, Should_return_projection_point_from_line_1_0_0__2_1_0_and_point)
{
	KramerProjectionSolver solver;
	const auto projection_point = solver.CalculateProjection(
		FLine3D(FPoint3D(1, 0, 0), FPoint3D(2, 1, 0)), FPoint3D(2, 0.5, 0.5));

	ASSERT_EQ(FPoint3D(1.75, 0.75, 0), projection_point);
}

TEST_F(KramerProjectionSolverTest, Should_return_projection_point_from_line_2_1_0__3_1_1_and_point)
{
	KramerProjectionSolver solver;
	const auto projection_point = solver.CalculateProjection(
		FLine3D(FPoint3D(2, 1, 0), FPoint3D(3, 1, 1)), FPoint3D(2, 0.5, 0.5));

	ASSERT_EQ(FPoint3D(2.25, 1, 0.25), projection_point);
}

TEST_F(KramerProjectionSolverTest, Should_return_projection_point_from_line_0_0_0__2_0_0_and_point_1_1_1)
{
	KramerProjectionSolver solver;
	const auto projection_point = solver.CalculateProjection(
		FLine3D(FPoint3D(0, 0, 0), FPoint3D(2, 0, 0)), FPoint3D(1, 1, 1));

	ASSERT_EQ(FPoint3D(1, 0, 0), projection_point);
}

TEST_F(KramerProjectionSolverTest, Should_return_projection_point_from_line_2_0_0__2_2_0_and_point_1_1_1)
{
	// TODO fix 
	// add algorithm for checking zero det matrix
	KramerProjectionSolver solver;
	const auto projection_point = solver.CalculateProjection(
		FLine3D(FPoint3D(2, 0, 0), FPoint3D(2, 2, 0)), FPoint3D(1, 1, 1));
	// return nan fpoint
	ASSERT_EQ(FPoint3D(2, 1, 0), projection_point);
}

TEST_F(KramerProjectionSolverTest, Should_return_projection_point_from_line_2_2_0__0_2_0_and_point_1_1_1)
{
	KramerProjectionSolver solver;
	const auto projection_point = solver.CalculateProjection(
		FLine3D(FPoint3D(2, 2, 0), FPoint3D(0, 2, 0)), FPoint3D(1, 1, 1));

	ASSERT_EQ(FPoint3D(1, 2, 0), projection_point);
}

TEST_F(KramerProjectionSolverTest, Should_return_projection_point_from_line_0_2_0__0_0_0_and_point_1_1_1)
{
	KramerProjectionSolver solver;
	const auto projection_point = solver.CalculateProjection(
		FLine3D(FPoint3D(0, 2, 0), FPoint3D(0, 0, 0)), FPoint3D(1, 1, 1));
	ASSERT_EQ(FPoint3D(0, 1, 0), projection_point);
}

TEST_F(KramerProjectionSolverTest, Should_return_projection_point_from_line_0_2_0__2_2_0_and_point_3_3_3)
{
	KramerProjectionSolver solver;
	const auto projection_point = solver.CalculateProjection(
		FLine3D(FPoint3D(2, 0, 0), FPoint3D(2, 2, 0)), FPoint3D(3, 3, 3));
	ASSERT_EQ(FPoint3D(2, 3, 0), projection_point);
}

TEST_F(KramerProjectionSolverTest, Should_return_projection_point_from_line_2_2_0__0_2_0_and_point_3_3_3)
{
	KramerProjectionSolver solver;
	const auto projection_point = solver.CalculateProjection(
		FLine3D(FPoint3D(2, 2, 0), FPoint3D(0, 2, 0)), FPoint3D(3, 3, 3));
	ASSERT_EQ(FPoint3D(3, 2, 0), projection_point);
}