/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModeCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:43:00 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/28 17:59:29 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList.hpp"

bool ModeForUser(Command cmd) {

  User *user_target = NULL;
  std::string options = "aiwro";
  int clear = 0;

	if (cmd.getArgs()[0] == cmd.getSender()->getNickname())
		user_target = cmd.getSender();
	else
	{
		if (cmd.getSender()->getMode().find("o") == std::string::npos)
		{
      cmd.getReplies().at(461)(cmd);
      return false;
    }
    user_target = cmd.getSender()->getServ()->getUserByname(cmd.getArgs()[0]);
		if (!user_target)
			return false;
	}
  if (cmd.getArgs().size() == 1)
    return false;
  for (size_t i = 0; i != cmd.getArgs().size(); ++i)
  {
    if (options.find(cmd.getArgs()[1][i]) == '-')
				clear = 1;
		else if (options.find(cmd.getArgs()[1][i]) == '+')
				clear = 0;
    if (options.find(cmd.getArgs()[1][i]) == std::string::npos)
		{
        cmd.getReplies().at(501)(cmd);
        return false;
    }
    else
    {

    }

  }
  
  cmd.getReplies().at(221)(cmd);
  return true;
}

void ModeCommand(Command cmd) {

	if (cmd.getArgs().size() == 0)
    {
		cmd.getReplies().at(461)(cmd);
        return;
    }
    //if (command->cmd->getArgs()[0].find("#") != std::string::npos)
    //else
	  if (!ModeForUser(cmd))
      return;
}