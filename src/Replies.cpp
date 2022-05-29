/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replies.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:43:07 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/28 20:54:37 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Replies.hpp"

//Replie for the connection command:

void freenode (Command cmd) {

    std::string irssi1 = PREFIX " NOTICE * :*** Looking up your ident...\r\n";
    std::string irssi2 = PREFIX " NOTICE * :*** Looking up your hostname...\r\n";
    std::string irssi3 = PREFIX " NOTICE * :*** Found your hostname (177.10.22.109.rev.sfr.net)\r\n";
    std::string irssi4 = PREFIX " CAP * LS :account-notify account-tag away-notify batch cap-notify chghost draft/relaymsg echo-message extended-join inspircd.org/poison inspircd.org/standard-replies invite-notify labeled-response message-tags multi-prefix sasl server-time setname userhost-in-names\r\n";
    send(cmd.getSender()->getSocket(), irssi1.c_str(), irssi2.length(), 0);
    send(cmd.getSender()->getSocket(), irssi2.c_str(), irssi2.length(), 0);
    send(cmd.getSender()->getSocket(), irssi3.c_str(), irssi2.length(), 0);
    send(cmd.getSender()->getSocket(), irssi4.c_str(), irssi2.length(), 0);
}


void RPL_WELCOME(Command cmd) {

    std::string irssi2 = PREFIX " 001 " + 
	cmd.getSender()->getNickname() + " :Welcome to the Internet Relay Network " +  
    cmd.getSender()->getNickname() + "!" + cmd.getSender()->getNickname() + "@" + 
    cmd.getSender()->getHostname() + " \r\n";
	
    send(cmd.getSender()->getSocket(), irssi2.c_str(), irssi2.length(), 0);
}

void RPL_HOST(Command cmd) {
    
    std::string irssi2 = PREFIX " 002 " + 
    cmd.getSender()->getNickname() + " :Your host is " + cmd.getSender()->getHostname() + " \r\n";

    send(cmd.getSender()->getSocket(), irssi2.c_str(), irssi2.length(), 0);
}

void RPL_ENDOFMOTD(Command cmd) {

    std::string irssi2 = PREFIX " 376 " + cmd.getSender()->getNickname() + " :End of /MOTD command\r\n";
    send(cmd.getSender()->getSocket(), irssi2.c_str(), irssi2.length(), 0);
}

//Replies for the MODE command :

void RPL_UMODEIS(Command cmd) {

    std::string mess = PREFIX " 221 " + cmd.getSender()->getNickname() + " +" + 
    cmd.getSender()->getMode() + "\r\n";

    send(cmd.getSender()->getSocket(), mess.c_str(), mess.length(), 0);    
}

void ERR_USERSDONTMATCH(Command cmd) {

    std::string mess = PREFIX " 502 :Cant change mode for other users\r\n";

    send(cmd.getSender()->getSocket(), mess.c_str(), mess.length(), 0);     
}

void ERR_UMODEUNKNOWNFLAG(Command cmd) { 

    std::string mess = PREFIX " 501 :Unknown MODE flag\r\n";

    send(cmd.getSender()->getSocket(), mess.c_str(), mess.length(), 0); 

}

//Replies for the NICK command:

void NICKCHANGED(Command cmd) {

    std::vector<User*> Userlist = cmd.getSender()->getServ()->getUserlist();
    std::vector<User*>::iterator it = Userlist.begin();
	std::vector<User*>::iterator ite = Userlist.end();
    std::string nickname = cmd.getArgs()[0];
    std::string mess = PREFIX " NICK :" + nickname + "\r\n";
    //send(cmd.getSender()->getSocket(), mess.c_str(), mess.length(), 0);
    for ( ; it != ite; it++) {
        send((*it)->getSocket(), mess.c_str(), mess.length(), 0);
   }
}

void  ERR_NONICKNAMEGIVEN(Command cmd) {

    std::string mess = PREFIX " 431 :No nickname given\r\n";

    send(cmd.getSender()->getSocket(), mess.c_str(), mess.length(), 0);
}

void ERR_ERRONEUSNICKNAME(Command cmd) { 
    
   std::string mess = PREFIX " 432 " + cmd.getSender()->getNickname() + 
   " " + cmd.getArgs()[0] + " :Erroneous Nickname\r\n";

    send(cmd.getSender()->getSocket(), mess.c_str(), mess.length(), 0);
}

void ERR_NICKNAMEINUSE(Command cmd) {

    std::string mess = PREFIX " 433 " + cmd.getSender()->getNickname() + 
   " " + cmd.getArgs()[0] + " :Nickname is already in use\r\n";

    send(cmd.getSender()->getSocket(), mess.c_str(), mess.length(), 0);
}

void ERR_NEEDMOREPARAMS(Command cmd) { 
    
    std::string mess = PREFIX " " + cmd.getCommand() + " 461 :Not enough parameters\r\n";

    send(cmd.getSender()->getSocket(), mess.c_str(), mess.length(), 0);
}