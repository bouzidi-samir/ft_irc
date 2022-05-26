/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:59:36 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/27 00:12:12 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList.hpp"

void PassCommand(Command cmd) 
{
    if (cmd.getSender()->isConnected())
    {    
        Utils::sendMessage(cmd.getSender(), "You are already connected.\n");
        return;
    }
    if (cmd.getArgs().size() != 1)
    {
        Utils::sendMessage(cmd.getSender(), "Not enough parameters.\n");
        return;
    }
    if (cmd.getArgs()[0] != cmd.getSender()->getPass())
    {
        Utils::sendMessage(cmd.getSender(), "Wrong password.\n");
        return;
    }
    cmd.getSender()->setAuthentified(true);
    cmd.checkconnection(cmd.getSender());
}