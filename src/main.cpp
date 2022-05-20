#include "../inc/server.hpp"

void checkArguments(int ac, char **av) {

    std::string err_mess = "./ircserv <port> <password>";
    
    if (ac != 3)
    {
        throw	std::runtime_error(err_mess);
        return;
    }
    
    for (int i = 0; av[1][i]; i++) {
        if (std::isdigit(av[1][i]) == 0) 
        {
            throw	std::runtime_error(err_mess);
            return;
        }
    }
    
    if (std::strcmp(av[2], PASSWORD)) 
        throw	std::runtime_error(err_mess);
}



int main (int ac, char **av) {

    try { checkArguments(ac, av);}
    catch (std::exception & e) 
    {
        std::cout << e.what() << std::endl;
        return 0;
    }

    Server irc = Server(std::atoi(av[1]));
    irc.initServer();
    irc.launch();
    close(irc.getSocket());
    return (0);
} 