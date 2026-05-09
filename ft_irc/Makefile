NAME    = ircserv

CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.

SRCS    = main.cpp \
          Server.cpp \
          Client.cpp \
          Channel.cpp \
          Parser.cpp \
          Reply.cpp \
          CommandDispatcher.cpp \
          Utils.cpp \
          commands/cmd_pass.cpp \
          commands/cmd_nick.cpp \
          commands/cmd_user.cpp \
          commands/cmd_quit.cpp \
          commands/cmd_ping.cpp \
          commands/cmd_cap.cpp \
          commands/cmd_privmsg.cpp \
          commands/cmd_join.cpp \
          commands/cmd_part.cpp \
          commands/cmd_topic.cpp \
          commands/cmd_kick.cpp \
          commands/cmd_invite.cpp \
          commands/cmd_mode.cpp

OBJS    = $(SRCS:.cpp=.o)
DEPS    = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
