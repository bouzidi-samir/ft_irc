#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <map>
#include <vector>
#include "./User.hpp"
#include "./CommandList.hpp"


class Channel {

    private:
            std::string _name;
            std::string _topic;
//            std::vector<User*> _members;

    public:
            Channel(std::string name, std::string topic);

};


#endif