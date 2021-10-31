#pragma once
#include "dllexport.h"

namespace Utility
{
	// Use for parse string by delimeter.
	class Utility_ExportDll StringSplitter
	{
	public:
		StringSplitter() = delete;
		~StringSplitter() = delete;

		// Returns substrings of original string separated by a string delimiter
		static std::vector<std::string> Split(const std::string& str, const std::string& delim = " ");
	};
}