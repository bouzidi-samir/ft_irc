
#include "../inc/Command.hpp"

Command::Command(std::string cmd, std::map<size_t, std::string> args, User *usr){
	
	_command = cmd;
	_args = args;
	_sender = usr;
	_commandList["PASS"] = &PassCommand;
	_commandList["NICK"] = &NickCommand;
	_commandList["USER"] = &UserCommand;
	_commandList["JOIN"] = &JoinCommand;
}

std::string Command::getCommand() const {return _command;}

User *Command::getSender() const {return _sender;}

std::map<size_t, std::string> Command::getArgs() const {return _args;}

void Command::runCommand() {

	std::map<std::string, void (*)(Command) > ::iterator it = _commandList.begin();
	std::map<std::string, void (*)(Command) > ::iterator it_e = _commandList.end();
	for (; it != it_e; it++) 
	{
		if((*it).first == _command)
		{
			Utils::printMessage(_sender, "Command Received: " + _command + " " + _args[0]);
			(*it).second(*this);
		}
	}
}

