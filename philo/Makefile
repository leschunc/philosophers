NAME		= philo
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -Iinc
MAKE		+= --no-print-directory

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= $(addprefix $(SRC_DIR)/, main.c parse.c philos.c monitor.c clock.c utils.c utils2.c)
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

# CFLAGS		+= -fsanitize=thread

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

# sanitize fix
############
# setarch -R

# ignore
#############
# philo/philo
# *.o
# log
# file
# test

.PHONY: all clean fclean re