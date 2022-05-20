#include "../inc/Utils.hpp"
#include <ctime>
#include <iostream>

void Utils::error(std::string message, bool stop)
{
	std::cerr << "error: " << message << std::endl;
	if (stop)
		exit(EXIT_FAILURE);
}

std::map<size_t, std::string>  Utils::map_split(std::string const &str, const char delim)
{
	size_t                        start;
	size_t                        end = 0;
	size_t                        occurrences = 0;
	std::map<size_t, std::string> ret;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		if (str[start] == ':')
			end = str.length();
		ret.insert(make_pair(occurrences, str.substr(start, end - start)));
		occurrences++;
	}
	return (ret);
}

std::vector<std::string> Utils::split(std::string str, std::string limit)
{
	std::vector<std::string> parts;
	size_t start = 0;
	size_t end;

	while ((end = str.find(limit, start)) != std::string::npos)
	{
		std::string local = str.substr(start, end - start);
		start = end + limit.length();
		parts.push_back(local);
	}

	parts.push_back(str.substr(start));
	return parts;
}

std::string Utils::strtoupper(std::string str)
{
	std::string ret;

	for (int i = 0; i < ret.length(); ++i)
    	ret[i] = toupper(ret[i]);
	return ret;
}

void Utils::bufferHandler(char *buffer, int cs) {

	std::string cmd;
	std::string buf;
	std::string temp;
	std::map<size_t, std::string> args;
	size_t      start;
	size_t      end;

	buf = buffer;
	start = std::string(buffer).find_first_not_of(' ');
	end = std::string(buffer).find_first_of(" \r\n", start);
	cmd = std::string(buf).substr(start, end - start);
	start = std::string(buffer).find_first_of(" ", start);
	end = std::string(buffer).find_first_of("\r\n", start);
	temp = std::string(buffer).substr(start + 1, end - start);
	args = map_split(temp, ' ');
	Command ret(cmd, args, cs);
	ret.runCommand();
}

bool Utils::buff_is_onsize(char *buffer, int cs) {

	if (std::string(buffer) == "\r\n")
		return false; 
	if (std::strlen(buffer) > 512)
	{
		send(cs, "Limit message to 512 characteres\r\n", 34, 0);
		std::memset(buffer, 0, BUF_SIZE + 1);
		return false;
	}
	return true;
}
