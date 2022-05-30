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
            
std::string Channel::getMode() const {return _mode;};

std::vector<User*> Channel::getMemberlist() const {return _memberlist;};

void Channel::sendTomembers(std::string message) {

    std::vector< User *>::iterator it = _memberlist.begin();
    std::vector< User *>::iterator ite = _memberlist.end();

    for ( ; it != ite; it++) {

        send((*it)->getSocket(), message.c_str(), message.length(), 0);
    }

}
