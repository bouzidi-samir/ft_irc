/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:01:46 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/22 16:34:41 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList.hpp"

bool    nickError(Command cmd)
{
    int senderSocket = cmd.getSender()->getSocket();
    
    std::string	message = "Usage: NICK <nickname>\n";
    if (cmd.getArgs().size() != 1)
	{
        send(senderSocket, message.c_str(),  message.length() + 1, 0);
		return false;
	};
    return true;
}

void NickCommand(Command cmd) {
    
    if (nickError(cmd) == false)
        return;
    cmd.getSender()->setNickname(cmd.getArgs()[0]);
    Utils::sendMessage(cmd.getSender(), "Your nickname has been set.\n");
}