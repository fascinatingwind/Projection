#include "FileReader.h"

#include <fstream>
#include <iostream>

namespace Utility
{
	FileReader::FileReader(const std::string& name)
	{
		assert(!name.empty());

		std::ifstream in_stream(name);
		if (in_stream.is_open())
		{
			std::string line;
			while (std::getline(in_stream, line))
			{
				m_lines.push_back(line);
			}
			in_stream.close();
		}
		else
		{
			std::cerr << "Can't open file name : " << name << std::endl;
		}
	}

	std::vector<std::string> FileReader::GetLines() const
	{
		return m_lines;
	}
}