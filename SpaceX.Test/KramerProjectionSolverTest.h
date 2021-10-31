#pragma once

using namespace SpaceX;

class Param
{
	FLine3D m_input_line;
	FPoint3D m_input_point;
	FPoint3D m_expected_point;

public:
	Param(FLine3D input_line, FPoint3D input_point, FPoint3D expected_point)
		: m_input_line(input_line),
		m_input_point(input_point),
		m_expected_point(expected_point)
	{
	}

	FLine3D InputLine() const { return m_input_line; }
	FPoint3D InputPoint() const { return m_input_point; }
	FPoint3D ExpectedPoint() const { return m_expected_point; }
};

class KramerProjectionSolverTest : public ::testing::TestWithParam<Param>
{
};

