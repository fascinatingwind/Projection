#include "pch.h"
#include "FMatrix3x3Test.h"

#include "FMatrix3x3.h"
#include "FPoint3D.h"

using namespace SpaceX;

TEST_F(FMatrix3x3Test, Should_found_a_determinant_with_main_diag_values)
{
	FMatrix3x3 matrix;
	matrix.SetRow(FPoint3D{ 1.f, 0.f, 0.f }, 0);
	matrix.SetRow(FPoint3D{ 0.f, 1.f, 0.f }, 1);
	matrix.SetRow(FPoint3D{ 0.f, 0.f, 1.f }, 2);

	const auto det = matrix.Determinant();
	ASSERT_EQ(1, det);
}

TEST_F(FMatrix3x3Test, Should_found_a_determinant_with_second_diag_values)
{
	FMatrix3x3 matrix;
	matrix.SetRow(FPoint3D{ 0.f, 0.f, 1.f }, 0);
	matrix.SetRow(FPoint3D{ 0.f, 1.f, 0.f }, 1);
	matrix.SetRow(FPoint3D{ 1.f, 0.f, 0.f }, 2);

	const auto det = matrix.Determinant();
	ASSERT_EQ(-1, det);
}

TEST_F(FMatrix3x3Test, Should_found_a_determinant_equals_5)
{
	FMatrix3x3 matrix;
	matrix.SetRow(FPoint3D{ 2.f, 0.f, 1.f }, 0);
	matrix.SetRow(FPoint3D{ 0.f, 1.f, 0.f }, 1);
	matrix.SetRow(FPoint3D{ 1.f, 0.f, 3.f }, 2);

	const auto det = matrix.Determinant();
	ASSERT_EQ(5, det);
}

TEST_F(FMatrix3x3Test, Should_found_a_determinant_equals_3)
{
	FMatrix3x3 matrix;
	matrix.SetRow(FPoint3D{ 1.f, 2.f, 3.f }, 0);
	matrix.SetRow(FPoint3D{ 1.f, 1.f, 2.f }, 1);
	matrix.SetRow(FPoint3D{ 3.f, 2.f, 2.f }, 2);

	const auto det = matrix.Determinant();
	ASSERT_EQ(3, det);
}