/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:01:02 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/30 16:46:44 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList.hpp"

void OperCommand(Command cmd) {

    if (cmd.getArgs().size() != 2)
	{
        cmd.getReplies().at(461)(cmd);
        return;
    }
    if (cmd.getArgs()[1] != cmd.getSender()->getServ()->getOperpass())
	{
        cmd.getReplies().at(464)(cmd);
        return;
    }
    cmd.getReplies().at(381)(cmd);    
    if (cmd.getSender()->getMode().find('o') == std::string::npos)
	{
		cmd.getSender()->setMode(cmd.getSender()->getMode() + "o");
        cmd.getReplies().at(221)(cmd);
	}
}