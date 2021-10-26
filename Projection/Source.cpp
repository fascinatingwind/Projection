#include <cstdlib>
#include <iostream>

#include "FileReader.h"
#include "StringConverter.h"

using namespace Projection;

std::string GetString(char* argv)
{
	return { argv, strlen(argv) };
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cerr << "Please enter file name with vertex coords and point of projection." << std::endl;
		return EXIT_SUCCESS;
	}

	const auto file_name = GetString(argv[1]);

	std::vector<std::string> point_values;
	for (int i = 2; i < argc; i++) {
		point_values.push_back(GetString(argv[i]));
	}

	FileReader reader(file_name);
	const auto lines = reader.GetLines();

	const auto point_coord = StringConverter::ConvertAll(point_values);
	const auto values = StringConverter::ConvertAll(lines);

	return EXIT_SUCCESS;
}