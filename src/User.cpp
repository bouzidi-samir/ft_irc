#include "../inc/User.hpp"

User::User() {}

User::User(int fd, std::string pass, Server *serv)
: _socket(fd)
{
	_pass = pass;
	_serv = serv;
	_connected = false;
	_registred = false;
	_authentified = false;
	this->nickname = "";
	this->username = "";
	this->realname = "";
	this->hostname = "";
}

User	*User::clone() const
{
	return (new User(_socket, _pass, _serv));
}

User &User::operator=(User const &ref) {

	this->nickname = ref.nickname;
	this->_socket = ref._socket;
	this->_channel = ref._channel;

	return *this;
}

int User::getSocket() const {return this->_socket;}

std::string User::getHostname() const {return this->hostname;}

std::string User::getRealname() const {return this->realname;}

std::string User::getUsername() const {return this->username;}

std::string User::getNickname() const {return this->nickname;}

std::string User::getPass() const {return this->_pass;}

Server *User::getServ() const {return this->_serv;}

Channel *User::getChannel() const {return this->_channel;};

void User::setNickname(std::string nick) {this->nickname= nick;}

void User::setUsername(std::string nick) {this->username= nick;}

void User::setHostname(std::string nick) {this->hostname= nick;}

void User::setRealname(std::string nick) {this->realname= nick;}

void User::setConnected(bool statue) {this->_connected = statue;}

void User::setRegistred(bool statue) {this->_registred = statue;}

void User::setChannel(Channel *channel) {this->_channel = channel;}

void User::setAuthentified(bool statue) {this->_authentified = statue;}

bool	User::isConnected() const  {return this->_connected;}

bool	User::isAuthentified() const  {return this->_authentified;}

bool	User::isRegistred() const  {return this->_registred;}