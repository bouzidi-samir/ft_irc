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

void Utils::sendMessage(User *usr, std::string message) {

	std::string blue = "\033[1;36m";
	std::string red = "\x1b[31m";
	std::string white = "\033[0m";

	std::string msg = red + "Anonymous IRC => " + usr->getNickname() + ": " + white + message;
	send(usr->getSocket(), msg.c_str(), msg.length() + 1, 0);
}

void Utils::sendConectMessage(User *usr) {

	std::string irssi2 = ":" + usr->getNickname() + " 001 " + 
	usr->getNickname() + " :Welcome to the Internet Relay Network " +  usr->getNickname() + "!" +
	 usr->getNickname() + "@" + usr->getHostname() + " \r\n.";
	send(usr->getSocket(), irssi2.c_str(), irssi2.length() + 1, 0);
}

void Utils::printMessage(User *usr, std::string message) {

	std::string blue = "\033[1;36m";
	std::string red = "\x1b[31m";
	std::string white = "\033[0m";

	std::cout << red << "=> " << usr->getNickname() << ": "  << white << message
	<< std::endl;

}

bool Utils::checkconnection(User *usr) {

	std::string blue = "\033[1;36m";
	std::string red = "\x1b[31m";
	std::string white = "\033[0m";
	
	if (!usr->isAuthentified() || !usr->isRegistred())
		return false;
	usr->setConnected(true);
	Utils::sendConectMessage(usr);
	std::cout << blue << usr->getNickname() << " is connected with the realname: " << usr->getRealname() 
	<< " and the hostname " << usr->getHostname() << "." << white << std::endl;
	
	return true;
}
