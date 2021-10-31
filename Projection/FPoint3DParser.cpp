#include "FPoint3DParser.h"
#include "StringSplitter.h"
#include "StringConverter.h"

namespace Projection
{
	using namespace Utility;

	FPoint3D FPoint3DParser::GetPoint(const std::string& string)
	{
		const auto lines = StringConverter::ConvertAll(StringSplitter::Split(string));
		assert(lines.size() == 3);
		if (lines.size() != 3)
			return FPoint3D();
		
		return FPoint3D( lines[0], lines[1], lines[2]);
	}

	std::vector<FPoint3D> FPoint3DParser::GetPoints(const std::vector<std::string>& string)
	{
		std::vector<FPoint3D> result;
		for (const auto& line : string)
		{
			result.push_back(GetPoint(line));
		}
		return result;
	}
}
