#pragma once

#include <string>
#include <map>
#include <vector>
//#include "server.hpp"

class User {

    private:
        bool _connected;
        int _socket;
        std::string nickname;
        std::string username;
        std::string realname;
        std::string hostname;
        std::string _channel;
    
    public:
        User();
        User(int sock);
        User *clone() const;
        User &operator=(User const &ref);
        int const getSocket() const;
        int const getType() const;
        bool    isConnected() const;
        std::string getNickname() const;
        std::string getUsername() const;
        std::string getRealname() const;
        std::string getHostname() const;
        void setNickname(std::string nick);
        void setUsername(std::string nick);
        void setRealname(std::string nick);
        void setHostname(std::string nick);
        void setConnected(bool statue);
};

