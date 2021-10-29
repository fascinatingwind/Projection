#pragma once

#include "SolutionStore.h"

namespace Projection
{
	using namespace SpaceX;

	class ConsolePrint
	{
	public:
		ConsolePrint() = delete;
		~ConsolePrint() = delete;

		static void Print(const std::string& message);
		static void PrintResults(const SolutionStore& solution);
	};
}