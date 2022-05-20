#pragma once

#include <string>
#include <vector>
//#include "server.hpp"
#include "User.hpp"
#include "CommandList.hpp"

class User;

class Command{
    private:
        std::string _command;
        std::map<size_t, std::string> _args;
        std::map<std::string, void (*)(Command) > _commandList;
        User _sender;
    
    public:
        Command(std::string cmd, std::map<size_t, std::string> args, int cs);
        std::string getCommand() const;
        void runCommand();
        void nickError(std::vector<std::string> cmd, User *user);
        User getSender() const;
        std::map<size_t, std::string> getArgs() const;
};


