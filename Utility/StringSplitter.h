#pragma once
#include "dllexport.h"

namespace Utility
{
	class Utility_ExportDll StringSplitter
	{
	public:
		StringSplitter() = delete;
		~StringSplitter() = delete;

		static std::vector<std::string> Split(const std::string& str, const std::string& delim = " ");
	};
}