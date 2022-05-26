/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replies.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:43:07 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/27 00:45:09 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Replies.hpp"

//Replie for the connection command:

void RPL_WELCOME(Command cmd) {

    std::string irssi2 = PREFIX " 001 " + 
	cmd.getSender()->getNickname() + " :Welcome to the Internet Relay Network " +  
    cmd.getSender()->getNickname() + "!" + cmd.getSender()->getNickname() + "@" + 
    cmd.getSender()->getHostname() + " \r\n";
	
    send(cmd.getSender()->getSocket(), irssi2.c_str(), irssi2.length() + 1, 0);
}

//Replies for the NICK command:

void ERR_ERRONEUSNICKNAME(Command cmd) { 
    
   std::string mess = PREFIX " 432 " + cmd.getSender()->getNickname() + 
   " " + cmd.getArgs()[0] + " :Erroneous Nickname\r\n";

    send(cmd.getSender()->getSocket(), mess.c_str(), mess.length() + 1, 0);
}

void ERR_NICKNAMEINUSE(Command cmd) {

    std::string mess = PREFIX " 433 " + cmd.getSender()->getNickname() + 
   " " + cmd.getArgs()[0] + " :Nickname is already in use\r\n";

    send(cmd.getSender()->getSocket(), mess.c_str(), mess.length() + 1, 0);
}


