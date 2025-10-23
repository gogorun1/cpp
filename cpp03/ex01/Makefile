NAME = scavtrap

CC = c++
CFLAGS = -Wall -Werror -Wextra -MMD -MP -std=c++98
RM = rm -f

SRCS = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp 
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

COLOR_GREEN = \033[0;32m
COLOR_BLUE = \033[0;34m
COLOR_BOLD = \033[1m
COLOR_RESET = \033[0m

.PHONY: all clean fclean re

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(COLOR_GREEN)$(COLOR_BOLD)$(NAME) is created $(COLOR_RESET)"

clean:
	@$(RM) -rf $(OBJS) $(DEPS)
	@echo "$(COLOR_BLUE)$(COLOR_BOLD)objects removed$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOR_BLUE)$(COLOR_BOLD)all clear$(COLOR_RESET)"

re: fclean all

-include $(DEPS)