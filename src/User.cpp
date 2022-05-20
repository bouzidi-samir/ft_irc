#include "../inc/User.hpp"

User::User() {}

User::User(int fd)
: _socket(fd)
{
	_connected = false;
	this->nickname = "Guest";
	this->username = "";
	this->realname = "";
	this->hostname = "";
	_channel = "General";
}

User	*User::clone() const
{
	return (new User(_socket));
}

User &User::operator=(User const &ref) {

	this->nickname = ref.nickname;
	this->_socket = ref._socket;
	this->_channel = ref._channel;

	return *this;
}

int const User::getSocket() const {return this->_socket;}

std::string User::getHostname() const {return this->hostname;}

std::string User::getRealname() const {return this->realname;}

std::string User::getUsername() const {return this->username;}

std::string User::getNickname() const {return this->nickname;}

void User::setNickname(std::string nick) {this->nickname= nick;}

void User::setUsername(std::string nick) {this->username= nick;}

void User::setHostname(std::string nick) {this->hostname= nick;}

void User::setRealname(std::string nick) {this->realname= nick;}

void User::setConnected(bool statue) {this->_connected = statue;}

bool	User::isConnected() const  {return this->_connected;}