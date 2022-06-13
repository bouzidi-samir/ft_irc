/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PingCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:59:06 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/06/13 14:52:24 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList.hpp"

void PingCommand(Command cmd) {

    if (cmd.getArgs().size() == 0)
    {
    	cmd.getReplies().at(409)(cmd);
        return;
    }
    std::string mess = ":*.ft_irc PONG :" + cmd.getArgs()[0] + "\r\n";
    send(cmd.getSender()->getSocket(), mess.c_str(), mess.length(), 0);
}