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
	const auto point = GetString(argv[2]);
	FileReader reader(file_name);
	const auto lines = reader.GetLines();
	
	const auto point_value = StringConverter::ConvertTo(point);
	const auto values = StringConverter::ConvertAll(lines);

	return EXIT_SUCCESS;
}