/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:56:40 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/31 15:17:24 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList.hpp"

//Commande USER: Premiere commande qui est censé etre envoiyée par le client.
//Avec cette commande le client m'envoit ses infos je les récupère et les stock.
//Si tous les formats de la commande sont respecté je lui renvoi un message de confirmation.
//AprÈs cela le client est officiellement connecté.

void UserCommand(Command cmd) {
    
    std::string messageA = ":Unauthorized\n";
    std::string messageB = ":Not enough parameters\n";
    bool isConnected = cmd.getSender()->isConnected();

    if (isConnected)
    {    
        cmd.getReplies().at(462)(cmd);
        return;
    }
    if (cmd.getArgs().size() != 4)
    {
        cmd.getReplies().at(461)(cmd);
        return;
    }
	if (cmd.getSender()->getUsername() == "")
	{
        cmd.getSender()->setUsername(cmd.getArgs()[0]);
		cmd.getSender()->setHostname(cmd.getArgs()[2]);
		cmd.getSender()->setRealname(cmd.getArgs()[3]);
	}
    cmd.checkconnection(cmd.getSender());
}

