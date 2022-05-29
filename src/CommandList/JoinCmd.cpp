/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:05:16 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/28 15:42:10 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList.hpp"

bool JoinError(Command cmd) {

    if (!cmd.getSender()->isConnected())
	{
        Utils::sendMessage(cmd.getSender(), "You are not connected.\n");
        return false;
    }
    if (cmd.getArgs().size() == 0)
    {
		cmd.getReplies().at(461)(cmd);
        return false;
    }
	if (cmd.getArgs().size() != 1)
	{
        Utils::sendMessage(cmd.getSender(), "Not enough parameters.\n");
    	return false;
    }  
    return true;
}

bool isOnServer(Command cmd) {

    std::string name = cmd.getArgs()[0];
    std::map<std::string, Channel*> channelist = cmd.getSender()->getServ()->getChannelist();
    std::map<std::string, Channel*>::iterator it = channelist.begin();
	std::map<std::string, Channel*>::iterator ite = channelist.end();

    for (; it != ite; it++) 
	{
		if((*it).first == name)
            return true;
	}
    return false;
}

void JoinCommand(Command cmd) {

    std::map<std::string, Channel*> channelist = cmd.getSender()->getServ()->getChannelist();
    if (!JoinError(cmd))
        return;
//    if (isOnServer)
//    {


//    }
//    else
//    {
//        Channel *chan = new Channel(cmd.getArgs()[0]);
//    }
}
