
#include "../inc/Command.hpp"

Command::Command(std::string cmd, std::map<size_t, std::string> args, User *usr){
	
	_command = cmd;
	_args = args;
	_sender = usr;
	
	_commandList["PASS"] = &PassCommand;
	_commandList["NICK"] = &NickCommand;
	_commandList["USER"] = &UserCommand;
	_commandList["PING"] = &PingCommand;
	_commandList["MODE"] = &ModeCommand;
	_commandList["OPER"] = &OperCommand;
	_commandList["JOIN"] = &JoinCommand;

	_replies[1] = &RPL_WELCOME;
	_replies[2]	= &RPL_HOST;
	_replies[221] = &RPL_UMODEIS;
	_replies[40] = &NICKCHANGED;
	_replies[376] = &RPL_ENDOFMOTD;
	_replies[381] = &RPL_YOUREOPER;
	_replies[431] = &ERR_NONICKNAMEGIVEN;
	_replies[432] = &ERR_ERRONEUSNICKNAME;
	_replies[433] = &ERR_NICKNAMEINUSE;
	_replies[461] = &ERR_NEEDMOREPARAMS;
	_replies[462] = &ERR_ALREADYREGISTRED;
	_replies[464] =  &ERR_PASSWDMISMATCH;
	_replies[501] = &ERR_UMODEUNKNOWNFLAG;
	_replies[502] = &ERR_USERSDONTMATCH;
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

void Command::freenode (Command cmd) {

    std::string irssi1 = PREFIX " NOTICE * :*** Looking up your ident...\r\n";
    std::string irssi2 = PREFIX " NOTICE * :*** Looking up your hostname...\r\n";
    std::string irssi3 = PREFIX " NOTICE * :*** Found your hostname (177.10.22.109.rev.sfr.net)\r\n";
    std::string irssi4 = PREFIX " CAP * LS :account-notify account-tag away-notify\r\n";
    //send(cmd.getSender()->getSocket(), irssi1.c_str(), irssi2.length(), 0);
   // send(cmd.getSender()->getSocket(), irssi2.c_str(), irssi2.length(), 0);
   // send(cmd.getSender()->getSocket(), irssi3.c_str(), irssi2.length(), 0);
    send(cmd.getSender()->getSocket(), irssi4.c_str(), irssi2.length(), 0);
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
	this->getReplies().at(376)(*this);
	std::cout << blue << usr->getNickname() << " is connected with the realname: " << usr->getRealname() 
	<< " and the hostname " << usr->getHostname() << "." << white << std::endl;
	
	return true;
}