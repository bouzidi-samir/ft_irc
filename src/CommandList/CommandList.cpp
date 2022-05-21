/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandList.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:40:02 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/22 01:40:06 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList/CommandList.hpp"

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
    else
        cmd.getSender()->setAuthentified(true);
}

bool    nickError(Command cmd)
{
    int senderSocket = cmd.getSender()->getSocket();
    
    std::string	message = "Usage: NICK <nickname>\n";
    if (cmd.getArgs().size() != 1)
	{
        send(senderSocket, message.c_str(),  message.length() + 1, 0);
		return false;
	};
    return true;
}

void NickCommand(Command cmd) {
    
    int senderSocket = cmd.getSender()->getSocket();
    bool isConnected = cmd.getSender()->isConnected();

    if (nickError(cmd) == false)
        return;
    cmd.getSender()->setNickname(cmd.getArgs()[0]);
    Utils::sendMessage(cmd.getSender(), "Your nickname has been set.\n");
}

//Commande USER: Premiere commande qui est censé etre envoiyée par le client.
//Avec cette commande le client m'envoit ses infos je les récupère et les stock.
//Si tous les formats de la commande sont respecté je lui renvoi un message de confirmation.
//AprÈs cela le client est officiellement connecté.

void UserCommand(Command cmd) {
    
    int senderSocket = cmd.getSender()->getSocket();
    std::string messageA = ":Unauthorized\n";
    std::string messageB = ":Not enough parameters\n";
    bool isConnected = cmd.getSender()->isConnected();

    if (isConnected)
    {    
        Utils::sendMessage(cmd.getSender(), "You are already registred.\n");
        return;
    }
    if (cmd.getArgs().size() != 1)
    {
        Utils::sendMessage(cmd.getSender(), "Usage: USER <username>\n");
        return;
    }
	if (cmd.getSender()->getUsername() == "Guest")
	{
		cmd.getSender()->setUsername(cmd.getArgs()[1]);
		cmd.getSender()->setHostname(cmd.getArgs()[3]);
		cmd.getSender()->setRealname(cmd.getArgs()[4]);
	}
    cmd.getSender()->setConnected(true);
    Utils::sendConectMessage(cmd.getSender());
}

void OperCommand(Command cmd) {

   
}