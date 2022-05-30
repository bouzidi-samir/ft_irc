/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:47:31 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/30 16:46:21 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.hpp"

Server::Server(int port, std::string password) {
	
	this->port = port;
	this->_password = password;
	this->_operpass = "poutine";

	Channel *welcome = new Channel("welcome");
	
	_channelList["Welcome"] = welcome;
	
	_commandList["PASS"] = &PassCommand;
	_commandList["NICK"] = &NickCommand;
	_commandList["USER"] = &UserCommand;
	_commandList["PING"] = &PingCommand;
	_commandList["MODE"] = &ModeCommand;
	_commandList["OPER"] = &OperCommand;
	_commandList["JOIN"] = &JoinCommand;
}

int 	Server::getSocket() const {return _sockfd;}

std::vector<User*> Server::getUserlist() const {return _users;};

std::map<std::string, Channel*> Server::getChannelist() const {return _channelList;};

User					*Server::getUserBysock(int cs)
{
	std::vector<User*>::iterator it = _users.begin();
	std::vector<User*>::iterator ite = _users.end();

	for (; it != ite; it++)
	{
		if ((*it)->getSocket() == cs)
			return (*it);
	}
	return (nullptr);
}

User					*Server::getUserByname(std::string name)
{
	std::vector<User*>::iterator it = _users.begin();
	std::vector<User*>::iterator ite = _users.end();

	for (; it != ite; it++)
	{
		if ((*it)->getNickname() == name)
			return (*it);
	}
	return (nullptr);
}

std::string Server::getOperpass() const {return _operpass;}

void Server::initServer()
{
	struct rlimit	rlp;
	struct protoent		*proto;
	struct sockaddr_in address;
	
	if (getrlimit(RLIMIT_NOFILE, &rlp) < 0)
		Utils::error("getrlimit: failed", true);
	_maxfd = rlp.rlim_cur;
	proto = getprotobyname("tcp");
	if (!proto)
		Utils::error("getprotobyname error", true);
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_family = AF_INET;
	address.sin_port = htons(this->port);
	
	_sockfd = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	if (bind(_sockfd, (const struct sockaddr*)&address, sizeof(address)) < 0)
	 	Utils::error("bind error", true);
	if (listen(_sockfd, 42) == -1)
		Utils::error("listen failed", true);
}	


void Server::launch()
{
	_cslen = sizeof(_address);	
	int					clientSock;
	_address.sin_addr.s_addr = htonl(INADDR_ANY);
	_address.sin_family = PF_INET;
	_address.sin_port = htons(this->port);
	while (1)
	{
		std::string	message;
		FD_ZERO(&_fd_read);	
		FD_SET(_sockfd, &_fd_read);
		fdDelete();			
		for (std::vector<User*>::iterator it = _users.begin(); it != _users.end(); it++)
		{	
			clientSock = (*it)->getSocket();
			FD_SET(clientSock, &_fd_read);
		}
		if (select(_users.size() + _sockfd + 1, &_fd_read, NULL, NULL, NULL) < 0)
			Utils::error("Select error\n", true);
		if (FD_ISSET(_sockfd, &_fd_read))
			this->addUser();
		for (std::vector<User*>::iterator it = _users.begin(); it != _users.end(); it++)
		{		
			clientSock = (*it)->getSocket();
			if (FD_ISSET(clientSock, &_fd_read))
				this->readClient(clientSock);
		}		
	}
}

bool Server::isCommand(std::string cmd) {
	
	std::map<std::string, void (*)(Command) > ::iterator it = _commandList.begin();
	std::map<std::string, void (*)(Command) > ::iterator it_e = _commandList.end();

	for (; it != it_e; it++) 
	{
		if((*it).first == cmd)
			return true;
	} 
	return false;
}

void Server::bufferParse(std::vector<std::string> list, int cs) {

	std::vector<std::string>::iterator it = list.begin();
	std::vector<std::string>::iterator ite = list.end();
	for ( ; it != ite; it++) {
		std::string buffer = *it;
		std::string cmd;
		std::string buf;
		std::string temp;
		std::map<size_t, std::string> args;
		size_t      start = 0;
		size_t      end;
		buf = *it;
		end = buffer.find_first_of(" \r\n", start);
		cmd = buf.substr(0, end);
		start = std::string(buffer).find_first_of(" ", start);
		end = std::string(buffer).find_first_of("\r\n", start);
		temp = std::string(buffer).substr(start + 1, (end - start));	
		args = Utils::map_split(temp, ' ');
		//args[args.size() - 1] = args[args.size() - 1].substr(0, args[0].size() - 1);
		if (isCommand(cmd) == true)
		{
			Command ret(cmd, args, getUserBysock(cs));
			ret.runCommand();
		}	
	}
	list.clear();
}

void	Server::readClient(int cs)
{
	char	buffer[1024];

	if ((recv(cs, buffer, BUF_SIZE, 0)) <= 0)
	{	
		std::cout << "Client " << cs << " is deconnected" << std::endl; 
		deleteList[cs] = 1;			
	}
	else
	{
		if (Utils::buff_is_onsize(buffer, cs) == false)
			return;
		std::vector<std::string> list = Utils::split(std::string(buffer), "\r\n");
		bufferParse(list, cs);
	}
	std::memset(buffer, 0, BUF_SIZE + 1);
}

void					Server::addUser()
{
	std::string	message;

	int cs = accept(_sockfd, (struct sockaddr *)&_address, &_cslen);
	fcntl(cs, F_SETFL, O_NONBLOCK);
	User *temp = new User(cs, this->_password, this);
	temp->setChannel(_channelList["Welcome"]);
	_channelList["Welcome"]->addMember(temp);
	_users.push_back(temp);
}

void    Server::fdDelete() {
	
	std::vector<User*>::iterator it = _users.begin();
	std::vector<User*>::iterator ite = _users.end();

	for (; it != ite; it++)
	{
		if ( this->deleteList[(*it)->getSocket()] == 1 )
		{
			close((*it)->getSocket());
			delete (*it);
			_users.erase(it);
			deleteList[(*it)->getSocket()] = 0;
		}			
	}
	for (int i = 0; i < 300; i++)
		deleteList[i] = 0;
}

void Server::freeServer() {
	std::vector<User*>::iterator it = _users.begin();
	std::vector<User*>::iterator ite = _users.end();

	close(_sockfd);
	for (; it != ite; it++) {

		close((*it)->getSocket());
		delete (*it);
		_users.erase(it);
	}
	_users.clear();

	std::map<std::string, Channel*>::iterator it1 = _channelList.begin();
	std::map<std::string, Channel*>::iterator it1e = _channelList.end();

	for (; it1 != it1e; it1++) {

		delete (it1)->second;
		_channelList.erase(it1->first);
	}
	_channelList.clear();

}