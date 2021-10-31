#include "pch.h"
#include "KramerProjectionSolverTest.h"

#include "KramerProjectionSolver.h"

INSTANTIATE_TEST_CASE_P(
	SLE_variants_,
	KramerProjectionSolverTest,
	::testing::Values(
		Param(FLine3D(FPoint3D(1, 0, 0), FPoint3D(2, 1, 0)), FPoint3D(2, 0.5, 0.5), FPoint3D(1.75, 0.75, 0)),
		Param(FLine3D(FPoint3D(2, 1, 0), FPoint3D(3, 1, 1)), FPoint3D(2, 0.5, 0.5), FPoint3D(2.25, 1, 0.25)),
		Param(FLine3D(FPoint3D(0, 0, 0), FPoint3D(2, 0, 0)), FPoint3D(1, 1, 1), FPoint3D(1, 0, 0)),
		Param(FLine3D(FPoint3D(2, 0, 0), FPoint3D(2, 2, 0)), FPoint3D(1, 1, 1), FPoint3D(2, 1, 0)),
		Param(FLine3D(FPoint3D(2, 2, 0), FPoint3D(0, 2, 0)), FPoint3D(1, 1, 1), FPoint3D(1, 2, 0)),
		Param(FLine3D(FPoint3D(0, 2, 0), FPoint3D(0, 0, 0)), FPoint3D(1, 1, 1), FPoint3D(0, 1, 0)),
		Param(FLine3D(FPoint3D(2, 0, 0), FPoint3D(2, 2, 0)), FPoint3D(3, 3, 3), FPoint3D(2, 3, 0)),
		Param(FLine3D(FPoint3D(2, 2, 0), FPoint3D(0, 2, 0)), FPoint3D(3, 3, 3), FPoint3D(3, 2, 0))
	)
);

TEST_P(KramerProjectionSolverTest, Should_return_expected_point)
{
	auto params = GetParam();

	const auto projection_point = KramerProjectionSolver::CalculateProjection(
		params.InputLine(), params.InputPoint());
	
	const auto expected = params.ExpectedPoint();
	ASSERT_EQ(expected, projection_point);
}
