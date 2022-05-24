# include "../inc/Replies.hpp"

void	rpl_welcome(User const & user)
{
	std::string msg = ":" + user.getHostname() + " 001 " + user.getNickname()
		+ " :Welcome to the Internet Relay Network " + user.getNickname()
		+ "!" + user.getUsername() + "@" + user.getHostname() + "\r\n";
	send(user.getSocket(), msg.c_str(), msg.length() + 1, 0);
}
