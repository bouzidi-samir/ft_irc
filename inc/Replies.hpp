/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replies.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:45:38 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/30 16:46:30 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define PREFIX ":*.ft_irc"
#define BLUE "\033[1;36m";
#define RED "\x1b[31m";
#define WHITE "\033[0m";

#include "./Command.hpp"

class Command;

void RPL_WELCOME(Command cmd);
void RPL_HOST(Command cmd);
void RPL_ENDOFMOTD(Command cmd);

//Replies for MODE:

void RPL_UMODEIS(Command cmd);
void ERR_USERSDONTMATCH(Command cmd);
void ERR_UMODEUNKNOWNFLAG(Command cmd);

//Replies for OPER:

void ERR_PASSWDMISMATCH(Command cmd);
void RPL_YOUREOPER(Command cmd);


//Replies for the NICK command:

void ERR_ERRONEUSNICKNAME(Command cmd);
void ERR_NICKNAMEINUSE(Command cmd);
void ERR_NONICKNAMEGIVEN(Command cmd);
void ERR_NEEDMOREPARAMS(Command cmd);
void NICKCHANGED(Command cmd);
