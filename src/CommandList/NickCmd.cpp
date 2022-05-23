/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:01:46 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/23 13:54:53 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList.hpp"

bool    nickError(Command cmd)
{
    if (cmd.getArgs().size() != 1)
	{
		Utils::sendMessage(cmd.getSender(), "Usage: NICK <nickname>\n");
        return false;
	};
    if (cmd.getArgs()[0].size() > NICK_SIZE + 1)
    {
        Utils::sendMessage(cmd.getSender(), "Your nickname has to have 9 characters.\n");
        return false;
    }
    for (size_t i = 0; i < cmd.getArgs()[0].size(); i++)
	{
		if (std::isdigit(cmd.getArgs()[0][i]))
		{
            Utils::sendMessage(cmd.getSender(), "Your nickname can't have digital characters.\n");
            return false;
        }
    }
    return true;
}

bool isAvailable(Command cmd) {

    std::vector<User*> Userlist = cmd.getSender()->getServ()->getUserlist();
    
    std::vector<User*>::iterator it = Userlist.begin();
	std::vector<User*>::iterator ite = Userlist.end();
    std::string nickToTest = cmd.getArgs()[0];
    std::cout << cmd.getSender()->getServ()->getUserlist().size()  << std::endl;
    for ( ; it != ite; it++) {
        if ( (*it)->getNickname() == nickToTest /*&& (*it)->isConnected()*/)
        {
            Utils::sendMessage(cmd.getSender(), "This nickname is already use.\n");
            return false;
        }
    }
    return true;
}

void NickCommand(Command cmd) {
    
    if (nickError(cmd) == false)
        return;
    if (isAvailable(cmd) == false)
        return;
    cmd.getSender()->setNickname(cmd.getArgs()[0]);
    Utils::sendMessage(cmd.getSender(), "Your nickname has been set.\n");
}