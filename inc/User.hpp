#pragma once

#include <string>
#include <map>
#include <vector>

class User {

    private:
        bool _connected;
        bool _authentified;
        int _socket;
        std::string nickname;
        std::string username;
        std::string realname;
        std::string hostname;
        std::string _channel;
        std::string _pass;

    public:
        User();
        User(int sock, std::string pass);
        User *clone() const;
        User &operator=(User const &ref);
        int const getSocket() const;
        int const getType() const;
        bool    isConnected() const;
        bool    isAuthentified() const;
        std::string getNickname() const;
        std::string getUsername() const;
        std::string getRealname() const;
        std::string getHostname() const;
         std::string getPass() const;
        void setNickname(std::string nick);
        void setUsername(std::string nick);
        void setRealname(std::string nick);
        void setHostname(std::string nick);
        void setConnected(bool statue);
        void setAuthentified(bool statue);
};

