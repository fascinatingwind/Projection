#pragma once
#ifndef SOLUTION_STORE_H
#define SOLUTION_STORE_H

#include "FPoint3D.h"

namespace SpaceX
{
	struct SolutionStore
	{
		FPoint3D m_projection;
		float m_lambda_parameter = 0.f;
		size_t m_segment_number = 0;
		float m_length_projection_segment = 0.f;
	};
}

#endif // SOLUTION_STORE_H