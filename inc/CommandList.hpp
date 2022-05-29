/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandList.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:41:19 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/27 23:44:02 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDLIST_HPP
#define COMMANDLIST_HPP

#define NICKSIZE 30
#define PREFIX ":*.ft_irc"

#include "User.hpp"
#include "server.hpp"
#include "Command.hpp"
#include "Channel.hpp"

class Command;

void PassCommand(Command cmd);
void NickCommand(Command cmd);
void UserCommand(Command cmd);
void PingCommand(Command cmd);
void ModeCommand(Command cmd);
void JoinCommand(Command cmd);




#endif