#include "StringConverter.h"

#include <sstream>

namespace Utility
{
	float StringConverter::ConvertTo(const std::string& string)
	{
		float value = 0.f;
		std::stringstream stream(string);
		stream >> value;
		return value;
	}

	std::vector<float> StringConverter::ConvertAll(const std::vector<std::string>& lines)
	{
		std::vector<float> result;
		result.reserve(lines.size());

		for (const auto& line : lines)
		{
			result.push_back(ConvertTo(line));
		}
		return result;
	}
}