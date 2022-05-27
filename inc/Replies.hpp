/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replies.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:45:38 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/27 14:29:20 by sbouzidi         ###   ########.fr       */
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

//Replies for the NICK command:

void ERR_ERRONEUSNICKNAME(Command cmd);
void ERR_NICKNAMEINUSE(Command cmd);
void ERR_NONICKNAMEGIVEN(Command cmd);
