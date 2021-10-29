#pragma once
#include "dllexport.h"

namespace Utility
{
	class Utility_ExportDll FileReader
	{
	public:
		FileReader() = default;
		~FileReader() = default;
		
		explicit FileReader(std::string name);
		
		std::vector<std::string> GetLines() const;
	
	private:
		std::string m_file_name;
		std::vector<std::string> m_lines;

		void Read();
	};
}