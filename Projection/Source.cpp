#include <cstdlib>

#include "FileReader.h"
#include "StringConverter.h"
#include "FPoint3D.h"
#include "FPoint3DParser.h"
#include "ConsolePrint.h"
#include "ProjectionFinder.h"
#include "SolutionStore.h"

using namespace Projection;
using namespace SpaceX;

std::string GetString(char* argv)
{
	return { argv, strlen(argv) };
}

int main(int argc, char* argv[])
{
#pragma region ParseArgs
	if (argc < 3)
	{
		ConsolePrint::Print("Please enter file name with vertex coords and point of projection.");
		return EXIT_SUCCESS;
	}

	const auto file_name = GetString(argv[1]);

	std::string point_values;
	for (int i = 2; i < argc; i++) {
		point_values += GetString(argv[i]) + " ";
	}
#pragma endregion

	FileReader reader(file_name);
	const auto lines = reader.GetLines();

	const auto point_coord = FPoint3DParser::GetPoint(point_values);
	const auto points = FPoint3DParser::GetPoints(lines);

	const auto solutions = ProjectionFinder::FindNearPointsProjection(
		points, point_coord);

	for(const auto& sol : solutions)
		ConsolePrint::PrintResults(sol);
	return EXIT_SUCCESS;
}