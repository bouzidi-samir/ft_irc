#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>
#include "./server.hpp"

namespace Utils
{
	void error(std::string message, bool stop);
	std::vector<std::string> split(std::string str, std::string limit);
	std::string strtoupper(std::string str);
	std::map<size_t, std::string> map_split(std::string const &str, const char delim);
	bool buff_is_onsize(char *buffer, int cs);
	void bufferHandler(char *buffer, int cs);	
}

#endif