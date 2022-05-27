
#include "../inc/Command.hpp"

Command::Command(std::string cmd, std::map<size_t, std::string> args, User *usr){
	
	_command = cmd;
	_args = args;
	_sender = usr;
	
	_commandList["PASS"] = &PassCommand;
	_commandList["NICK"] = &NickCommand;
	_commandList["USER"] = &UserCommand;
	_commandList["PING"] = &PingCommand;
	_commandList["JOIN"] = &JoinCommand;

	_replies[1] = &RPL_WELCOME;
	_replies[2]	= &RPL_HOST;
	_replies[431] = &ERR_NONICKNAMEGIVEN;
	_replies[432] = &ERR_ERRONEUSNICKNAME;
	_replies[433] = &ERR_NICKNAMEINUSE;
}

std::string Command::getCommand() const {return _command;}

std::map<int, void (*)(Command)> Command::getReplies() const {return _replies;}

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

bool Command::checkconnection(User *usr) {

	std::string blue = "\033[1;36m";
	std::string red = "\x1b[31m";
	std::string white = "\033[0m";
	
	if (!usr->isAuthentified() || !usr->isRegistred())
		return false;
	usr->setConnected(true);
	this->getReplies().at(1)(*this);
	this->getReplies().at(2)(*this);
	std::cout << blue << usr->getNickname() << " is connected with the realname: " << usr->getRealname() 
	<< " and the hostname " << usr->getHostname() << "." << white << std::endl;
	
	return true;
}