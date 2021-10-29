#pragma once
#include "dllexport.h"

#include <sstream>

namespace Utility
{
	class Utility_ExportDll StringConverter
	{
	public:
		StringConverter() = delete;
		~StringConverter() = delete;
		
		static float ConvertTo(const std::string& string);
		static std::vector<float> ConvertAll(const std::vector<std::string>& lines);

	private:
		// for simple types like int double, float
		template<class T>
		static T ConvertTo(const std::string& string)
		{
			T value;
			std::stringstream stream(string);
			stream >> value;
			return value;
		}

		template<class T>
		static std::vector<T> ConvertAll(const std::vector<std::string>& lines)
		{
			std::vector<T> result;
			for (const auto& line : lines)
			{
				result.push_back(ConvertTo<T>(line));
			}
			return result;
		}
	};
}