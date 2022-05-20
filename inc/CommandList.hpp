/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandList.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:41:19 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/20 14:50:21 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef COMMANDLIST_HPP
#define COMMANDLIST_HPP

#include "./User.hpp"
#include "./server.hpp"
#include "./Command.hpp"

class Command;

void NickCommand(Command cmd);
void UserCommand(Command cmd);
void OperCommand(Command cmd);



#endif