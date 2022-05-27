#include "../inc/Channel.hpp"

Channel::Channel(std::string name)
{
    _name = name;
 }

void Channel::addMember(User *usr) {
    
    _memberlist.push_back(usr);
}

std::string Channel::getName() const {return _name;};
            
std::string Channel::getTopic() const {return _topic;};
            
std::vector<User*> Channel::getMemberlist() const {return _memberlist;};
