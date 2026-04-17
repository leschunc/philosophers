NAME		= philo
CC			= cc
MAKE		+= --no-print-directory
CFLAGS		= -Wall -Werror -Wextra -Iinc
CFLAGS		+= -fsanitize=thread
# sanitize fix, run with setarch so memory is not randomized
# make re && setarch -R ./philo 1 1 1 1

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= $(addprefix $(SRC_DIR)/, main.c parse.c philos.c monitor.c clock.c utils.c utils2.c)
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME):  $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# .gitignore
#############
# philo/philo
# *.o
# log
# file
# test
