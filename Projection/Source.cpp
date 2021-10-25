#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc < 3)
		std::cerr << "Please enter file name with vertex coords and point of projection." << std::endl;

	return EXIT_SUCCESS;
}