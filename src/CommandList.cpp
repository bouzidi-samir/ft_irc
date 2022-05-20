/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandList.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:40:02 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/20 18:10:17 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/CommandList.hpp"

bool    nickError(Command cmd)
{
    int senderSocket = cmd.getSender().getSocket();
    
    std::string	message = "Usage: /nick <nickname>\n";
	if (cmd.getArgs().size() != 1)
	{
        send(senderSocket, message.c_str(), 25, 0);
		return false;
	};
    return true;
}

void NickCommand(Command cmd) {
    
    int senderSocket = cmd.getSender().getSocket();
    bool isConnected = cmd.getSender().isConnected();

    if (nickError(cmd) == false)
        return;
    cmd.getSender().setNickname(cmd.getArgs()[1]);
    std::string	message = "Nick name changed\n";
    send(senderSocket, message.c_str(), 19, 0);
}

//Commande USER: Premiere commande qui est censé etre envoiyée par le client.
//Avec cette commande le client m'envoit ses infos je les récupère et les stock.
//Si tous les formats de la commande sont respecté je lui renvoi un message de confirmation.
//AprÈs cela le client est officiellement connecté.

void UserCommand(Command cmd) {
    
    int senderSocket = cmd.getSender().getSocket();
    std::string messageA = ":Unauthorized\n";
    std::string messageB = ":Not enough parameters\n";
    bool isConnected = cmd.getSender().isConnected();
    
    if (isConnected)
    {    
        send(senderSocket, messageA.c_str(), 22, 0);
        return;
    }
    if (cmd.getArgs().size() != 1)
    {
        send(senderSocket, messageA.c_str(), 19, 0);
        return;
    }
	if (cmd.getSender().getUsername() == "")
	{
		cmd.getSender().setUsername(cmd.getArgs()[1]);
		cmd.getSender().setHostname(cmd.getArgs()[3]);
		cmd.getSender().setRealname(cmd.getArgs()[4]);
	}
    cmd.getSender().setConnected(true);
}

void OperCommand(Command cmd) {


    
}