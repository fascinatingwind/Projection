#include "StringConverter.h"

namespace Utility
{
	float StringConverter::ConvertTo(const std::string& line)
	{
		return ConvertTo<float>(line);
	}

	std::vector<float> StringConverter::ConvertAll(const std::vector<std::string>& lines)
	{
		return ConvertAll<float>(lines);
	}
}