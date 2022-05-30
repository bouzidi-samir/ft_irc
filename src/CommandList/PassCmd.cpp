/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:59:36 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/30 21:12:03 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList.hpp"

void PassCommand(Command cmd) 
{
    if (cmd.getArgs().size() != 1)
    {
        cmd.getReplies().at(461)(cmd);
        return;
    }
     if (cmd.getSender()->isConnected())
    {
        cmd.getReplies().at(462)(cmd);
        return;
    }
    if (cmd.getArgs()[0] != cmd.getSender()->getPass())
    {
        cmd.getReplies().at(464)(cmd);
        return;
    }
    cmd.getSender()->setAuthentified(true);
    cmd.checkconnection(cmd.getSender());
}