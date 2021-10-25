#include "FileReader.h"

#include <fstream>
#include <iostream>

namespace Projection
{
	FileReader::FileReader(std::string name)
		: m_file_name(std::move(name))
	{
		Read();
	}
	
	void FileReader::ReadFile(const std::string& file)
	{
		m_file_name = file;
		Read();
	}

	std::vector<std::string> FileReader::GetLines() const
	{
		return m_lines;
	}
	
	void FileReader::Read()
	{
		std::ifstream in_stream(m_file_name);
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
			std::cerr << "Can't open file name : " << m_file_name << std::endl;
		}
	}
}