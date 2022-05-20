#ifndef SERVER_HPP
#define SERVER_HPP

#define PASSWORD "poutine"
#define BUF_SIZE	1024
#define DATE_SIZE	26
#define NICK_SIZE	9
#define FD_FREE	0
#define FD_SERV	1
#define FD_CLIENT	2
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

//#include "Channel.hpp"
#include "User.hpp"
#include "Utils.hpp"
#include "Command.hpp"
//#include "CommandList.hpp"

class Command;
class User;

class Server {

    private:
        int port;
        int _sockfd;
        struct sockaddr_in	_address; 
        socklen_t _cslen;
        fd_set  _fd_read;
        int _max;
        int _maxfd;
        int deleteList[30];
        std::vector<User*> _users;
        std::map<std::string, void (*)(Command) > _commandList;
     
    public:
        Server(int port);
        void initServer();
        void launch();
        void  addUser();
        int     getSocket() const;
        void    commandManager(User *user, std::vector<std::string> cmd);
        User	*getUserBysock(int cs);
        void    fdDelete();
        void    readClient(int cs);
        void    bufferParse(char *buffer, int cs);
        bool    isCommand(std::string cmd);
        typedef std::vector<User *>::iterator   u_iterator;
};



#endif