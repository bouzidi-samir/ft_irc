/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:59:36 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/23 14:10:55 by sbouzidi         ###   ########.fr       */
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
    Utils::checkconnection(cmd.getSender());
}