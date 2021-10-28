#pragma once
namespace Projection
{
	class StringSplitter
	{
	public:
		StringSplitter() = delete;
		~StringSplitter() = delete;

		static std::vector<std::string> Split(const std::string& str, const std::string& delim = " ");
	};
}