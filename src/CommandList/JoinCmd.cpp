/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:05:16 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/06/13 13:17:07 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList.hpp"

bool JoinError(Command cmd) {

   // Channel *chan = cmd.getSender()->getServ()->getChannelist()[cmd.getArgs()[0]];

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
    if (cmd.getArgs()[0][0] != '#')
	{
		cmd.getReplies().at(476)(cmd);
		return false;
	}
    //if (chan->getMode().find('i') != std::string::npos)
	//{
	//	cmd.getReplies().at(473)(cmd);
	//	return false;
	//}
    
    
    
    
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
   
}
