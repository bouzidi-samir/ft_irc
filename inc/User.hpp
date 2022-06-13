/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:57:26 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/06/13 15:24:45 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>
#include <vector>

#include "./server.hpp"
#include "./Channel.hpp"

class Server;

class Channel;

class User {

    private:
        Server *_serv;
        bool _registred;
        bool _authentified;
        bool _accepted;
        bool _connected;
        int _socket;
        std::string nickname;
        std::string username;
        std::string realname;
        std::string hostname;
        std::string _pass;
        std::string _mode;
        Channel *_channel;

    public:
        User();
        User(int sock, std::string pass, Server *serv);
        User *clone() const;
        User &operator=(User const &ref);
        int getSocket() const;
        int getType() const;
        bool    isConnected() const;
        bool    isAuthentified() const;
        bool    isRegistred() const;
        bool    isAccepted() const;
        std::string getNickname() const;
        std::string getUsername() const;
        std::string getRealname() const;
        std::string getHostname() const;
        std::string const &getMode() const;
        std::string getPass() const;
        Channel *getChannel() const;
        Server *getServ() const;
        void setNickname(std::string nick);
        void setUsername(std::string nick);
        void setRealname(std::string nick);
        void setHostname(std::string nick);
        void setRegistred(bool statue);
        void setConnected(bool statue);
        void setAuthentified(bool statue);
        void setAccepted(bool statue);
        void setChannel(Channel *channel);
        void setMode(std::string mode);
};

