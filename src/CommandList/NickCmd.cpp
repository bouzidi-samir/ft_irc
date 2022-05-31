/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:01:46 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/31 14:35:58 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList.hpp"

bool    nickError(Command cmd)
{
    if (!cmd.getArgs().size())
	{
		cmd.getReplies().at(431)(cmd);
        return false;
	};
          
    std::string nickname = cmd.getArgs()[0];
        
    if (nickname.length() > NICK_SIZE)
    {
        cmd.getReplies().at(432)(cmd);
        return false;
    }

    if (!Utils::isLetter(nickname[0]) && !Utils::isSpecial(nickname[0]))
	{
        cmd.getReplies().at(432)(cmd);
        return false;
    }
    for (size_t i = 1; i < nickname.length(); i++)
	{
		if (!Utils::isLetter(nickname[i]) && !Utils::isSpecial(nickname[i]) && !Utils::isDigit(nickname[i]) && nickname[i] != '-')
		{
            cmd.getReplies().at(432)(cmd);
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
    for ( ; it != ite; it++) {
        if ( (*it)->getNickname() == nickToTest && (*it)->isConnected())
        {
            cmd.getReplies().at(433)(cmd);
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
    if (cmd.getSender()->isConnected())
    {
        cmd.getReplies().at(40)(cmd);             
    }
    cmd.getSender()->setNickname(cmd.getArgs()[0]);
    cmd.getSender()->setRegistred(true);
    //Utils::checkconnection(cmd.getSender());
}