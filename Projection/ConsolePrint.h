#pragma once
#include "SolutionStore.h"

namespace Projection
{
	class ConsolePrint
	{
	public:
		ConsolePrint() = delete;
		~ConsolePrint() = delete;

		static void Print(const std::string& message);
		static void PrintResults(const SolutionStore& solution);
	};
}