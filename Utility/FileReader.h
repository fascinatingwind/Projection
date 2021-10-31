#pragma once
#ifndef FILE_READER_H
#define FILE_READER_H

#include "dllexport.h"

namespace Utility
{
	// Read file by file name.
	class Utility_ExportDll FileReader
	{
	public:
		// Read file by lines and store in class.
		explicit FileReader(const std::string& name);
		~FileReader() = default;
		
		// Return stored lines of readed file.
		std::vector<std::string> GetLines() const;
	
	private:
		std::vector<std::string> m_lines;
	};
}

#endif // !FILE_READER_H