/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PingCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:59:06 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/27 16:34:41 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList.hpp"

void PingCommand(Command cmd) {

    std::string mess = ":*.ft_irc PONG :" + cmd.getArgs()[0] + "\r\n";
    //Utils::sendMessage(cmd.getSender(), mess);
    send(cmd.getSender()->getSocket(), mess.c_str(), mess.length(), 0);
}