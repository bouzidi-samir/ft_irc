/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PongCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:59:06 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/06/13 14:54:56 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CommandList.hpp"

void PongCommand(Command cmd) {

    if (cmd.getArgs().size() == 0)
    {
    	cmd.getReplies().at(409)(cmd);
        return;
    } 
}