#pragma once

namespace Projection
{
	class FileReader
	{
	public:
		FileReader() = default;
		~FileReader() = default;
		
		explicit FileReader(std::string name);
		
		void ReadFile(const std::string& file);
		
		std::vector<std::string> GetLines() const;
	
	private:
		std::string m_file_name;
		std::vector<std::string> m_lines;

		void Read();
	};
}