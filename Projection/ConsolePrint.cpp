#include "ConsolePrint.h"

#include <iostream>

namespace Projection
{
	void ConsolePrint::Print(const std::string& message)
	{
		std::cout << message << std::endl;
	}

	void ConsolePrint::PrintResults(const SolutionStore& solution)
	{
		std::cout
			<< "Segment "
			<< solution.m_segment_number
			<< " parameter "
			<< solution.m_lambda_parameter
			<< " point "
			// for fix negative zero output
			<< solution.m_projection.X() + 0.f << " "
			<< solution.m_projection.Y() + 0.f << " "
			<< solution.m_projection.Z() + 0.f << " "
			<< std::endl;
	}
}