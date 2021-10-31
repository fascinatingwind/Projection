#pragma once
#ifndef CONSOLE_PRINT_H
#define CONSOLE_PRINT_H

#include "SolutionStore.h"

namespace Projection
{
	using namespace SpaceX;

	// Class use for print in std out
	class ConsolePrint
	{
	public:
		ConsolePrint() = delete;
		~ConsolePrint() = delete;

		// Print message in std out with end line.
		static void Print(const std::string& message);
		// Print information of projection like
		// segment, parameter and projection point
		static void PrintResults(const SolutionStore& solution);
	};
}

#endif // !CONSOLE_PRINT_H