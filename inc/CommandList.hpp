/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandList.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:41:19 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/22 16:37:50 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDLIST_HPP
#define COMMANDLIST_HPP

#include "User.hpp"
#include "server.hpp"
#include "Command.hpp"

class Command;

void PassCommand(Command cmd);
void NickCommand(Command cmd);
void UserCommand(Command cmd);



#endif