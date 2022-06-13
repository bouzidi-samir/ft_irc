/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModeCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:43:00 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/06/13 16:07:47 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList.hpp"

bool ModeForUser(Command cmd) {

  User *user_target = NULL;
  std::string options = "+aiwro";
  int clear = 0;

	if (cmd.getArgs()[0] == cmd.getSender()->getNickname())
		user_target = cmd.getSender();
	else
	{
		if (cmd.getSender()->getMode().find("o") == std::string::npos)
		{
      cmd.getReplies().at(502)(cmd);
      return false;
    }
    user_target = cmd.getSender()->getServ()->getUserByname(cmd.getArgs()[0]);
		if (!user_target)
			return false;
	}
  if (cmd.getArgs().size() == 1)
    return false;
  
  std::string mode = cmd.getSender()->getMode();
  std::string mode1 = cmd.getSender()->getMode();
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
      if (clear && (&mode)->find(cmd.getArgs()[1][i]) != std::string::npos)
		    (&mode)->erase((&mode)->find(cmd.getArgs()[1][i]), 1);
	   else if (!clear && (&mode)->find(cmd.getArgs()[1][i]) == std::string::npos)
        {
            if (cmd.getArgs()[1][i] != '+')
            {
              cmd.getSender()->setMode(mode1 + cmd.getArgs()[1][i]);
            }
        }
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