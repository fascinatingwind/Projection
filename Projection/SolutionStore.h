#pragma once
#include "FPoint3D.h"

namespace Projection
{
	using namespace SpaceX;

	struct SolutionStore
	{
		FPoint3D m_projection;
		float m_lambda_parameter = 0;
		size_t m_segment_number = 0;
	};
}