/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:57:13 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/06/13 11:33:08 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#define PASSWORD "poutine"
#define MAX_FD 1000
#define BUF_SIZE	1024
#define DATE_SIZE	26
#define NICK_SIZE	9
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <exception>
#include <vector>
#include <netdb.h>
#include <arpa/inet.h>

#include "User.hpp"
#include "Utils.hpp"
#include "Command.hpp"
#include "Channel.hpp"

class Channel;
class Command;
class User;

class Server {

    private:
        int port;
        std::string _password;
        std::string _operpass;
        int _sockfd;
        struct sockaddr_in	_address; 
        socklen_t _cslen;
        fd_set  _fd_read;
        int _max;
        int _maxfd;
        bool _nc;
        int deleteList[300];
        std::vector<User*> _users;
        std::map<std::string, void (*)(Command) > _commandList;
        std::map<std::string, Channel*> _channelList;

    public:
        Server(int port, std::string password);
        void initServer();
        void launch();
        void  addUser();
        int     getSocket() const;
        void    commandManager(User *user, std::vector<std::string> cmd);
        User	*getUserBysock(int cs);
        User	*getUserByname(std::string name);
        std::string getOperpass() const;
        std::vector<User*> getUserlist() const;
        std::map<std::string, Channel*> getChannelist() const;
        void    fdDelete();
        void    deleteChannel(std::string name);
        void    readClient(int cs);
        void    bufferParse(std::vector<std::string> list, int cs);
        bool    isCommand(std::string cmd);
        void    freeServer();
        typedef std::vector<User *>::iterator   u_iterator;
};



#endif