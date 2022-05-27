/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:57:36 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/27 14:54:08 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>
#include "./server.hpp"
#include "./User.hpp"

class User;

namespace Utils
{
	void error(std::string message, bool stop);
	bool isLetter(char c);
	bool isSpecial(char c);
	bool isDigit(char c);
	std::vector<std::string> split(std::string str, std::string limit);
	std::map<size_t, std::string> map_split(std::string const &str, const char delim);
	bool buff_is_onsize(char *buffer, int cs);
	void bufferHandler(char *buffer, int cs);	
	void sendMessage(User *usr, std::string message);
	void sendConectMessage(User *usr);
	void printMessage(User *usr, std::string message);
	bool checkconnection(User *usr);
}

#endif