#pragma once
#ifndef STRING_CONVERTER_H
#define STRING_CONVERTER_H

#include "dllexport.h"

namespace Utility
{
	// Use for parsing string to other types like int, float, etc.
	// In current case implement float parsing
	class Utility_ExportDll StringConverter
	{
	public:
		StringConverter() = delete;
		~StringConverter() = delete;
		
		// Return float number from string like 213.0asda
		static float ConvertTo(const std::string& string);
		// Return all float numbers from vector of strings
		static std::vector<float> ConvertAll(const std::vector<std::string>& lines);
	};
}

#endif // !STRING_CONVERTER_H