
#include "../inc/Command.hpp"

Command::Command(std::string cmd, std::map<size_t, std::string> args, int cs){
	
	_command = cmd;
	_args = args;
	_sender = cs;
	_commandList["NICK"] = &NickCommand;
	_commandList["USER"] = &UserCommand;
	_commandList["OPER"] = &OperCommand;
}

std::string Command::getCommand() const {return _command;}

User Command::getSender() const {return _sender;}

std::map<size_t, std::string> Command::getArgs() const {return _args;}

void Command::runCommand() {

	std::map<std::string, void (*)(Command) > ::iterator it = _commandList.begin();
	std::map<std::string, void (*)(Command) > ::iterator it_e = _commandList.end();

	for (; it != it_e; it++) 
	{
		if((*it).first == _command)
			(*it).second(*this);
	} 
}

