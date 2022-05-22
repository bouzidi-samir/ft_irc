/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:56:40 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/22 16:21:11 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList.hpp"

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

