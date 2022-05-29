/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:57:01 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/28 20:56:18 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <vector>
#include "User.hpp"
#include "Utils.hpp"
#include "./CommandList.hpp"
#include "./Replies.hpp"

class User;

class Command{
    private:
        std::string _command;
        std::map<size_t, std::string> _args;
        std::map<std::string, void (*)(Command) > _commandList;
        std::map<int, void (*)(Command)> _replies;
        User *_sender;
    
    public:
        Command(std::string cmd, std::map<size_t, std::string> args, User *usr);
        void freenode (Command cmd);
        std::string getCommand() const;
        void runCommand();
        void nickError(std::vector<std::string> cmd, User *user);
        User *getSender() const;
        std::map<int, void (*)(Command)> getReplies() const;
        std::map<size_t, std::string> getArgs() const;
        bool checkconnection(User *usr);
};


