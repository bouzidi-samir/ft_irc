/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:47:31 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/20 15:07:51 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.hpp"

Server::Server(int port) {
	
	this->port = port;
	_commandList["NICK"] = &NickCommand;
	_commandList["USER"] = &UserCommand;
	_commandList["OPER"] = &OperCommand;
}

int 	Server::getSocket() const {return _sockfd;}

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

void Server::initServer()
{
	struct rlimit	rlp;
	struct protoent		*proto;
	struct sockaddr_in address;
	int addrlen = sizeof(address);

	if (getrlimit(RLIMIT_NOFILE, &rlp) < 0)
		Utils::error("getrlimit: failed", true);
	_maxfd = rlp.rlim_cur;
	proto = getprotobyname("tcp");
	if (!proto)
		Utils::error("getprotobyname error", true);
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_family = AF_INET;
	address.sin_port = htons(this->port);
	
	_sockfd = socket(PF_INET, SOCK_STREAM, proto->p_proto);
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

void Server::bufferParse(char *buffer, int cs) {

	std::string cmd;
	std::string buf;
	std::string temp;
	std::map<size_t, std::string> args;
	size_t      start;
	size_t      end;

	buf = buffer;
	start = std::string(buffer).find_first_not_of(' ');
	end = std::string(buffer).find_first_of(" \r\n", start);
	cmd = std::string(buf).substr(start, end - start);
	start = std::string(buffer).find_first_of(" ", start);
	end = std::string(buffer).find_first_of("\r\n", start);
	temp = std::string(buffer).substr(start + 1, end - start);
	args = Utils::map_split(temp, ' ');
	if (isCommand(cmd) == true)
	{
		Command ret(cmd, args, cs);
		ret.runCommand();
	}
	else
		std::cout << cmd << std::endl;
}

void	Server::readClient(int cs)
{
	char	buffer[BUF_SIZE];

	if ((recv(cs, buffer, BUF_SIZE, 0)) <= 0)
	{	
		std::memset(buffer, 0, BUF_SIZE + 1);
		std::cout << "Client " << cs << " is deconnected" << std::endl; 
		deleteList[cs] = 1;			
	}
	else
	{
		if (Utils::buff_is_onsize(buffer, cs) == false)
			return;
		//std::cout << buffer << std::endl;
		bufferParse(buffer, cs);
		std::memset(buffer, 0, BUF_SIZE + 1);
	}
	std::memset(buffer, 0, BUF_SIZE + 1);
}

void					Server::addUser()
{
	std::string	message;

	int cs = accept(_sockfd, (struct sockaddr *)&_address, &_cslen);
	fcntl(cs, F_SETFL, O_NONBLOCK);
	User temp(cs);
	_users.push_back(temp.clone());
	printf("New client #%d from %s:%d\n", cs, inet_ntoa(_address.sin_addr), ntohs(_address.sin_port));
	message = this->getUserBysock(cs)->getNickname() + "\n";
	//send(cs, message.c_str(), NICK_SIZE, 0);
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
	for (int i = 0; i < 30; i++)
		deleteList[i] = 0;
}

