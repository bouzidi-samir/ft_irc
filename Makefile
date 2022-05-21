NAME = ircserv
SRCS = src/main.cpp src/server.cpp src/Utils.cpp src/User.cpp src/Command.cpp src/CommandList/CommandList.cpp src/Channel.cpp
CLFAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	c++ -o $@ -c $< $(CFLAGS)

all: $(NAME)

clean: $(OBJS)
	@rm -rf *.o
	rm -f $(OBJS)

fclean: clean
	@rm -rf *.o 
	rm -f $(OBJS)
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re
