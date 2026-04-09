NAME		= philo
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -Iinc -Ilibft
LDFLAGS		= -Llibft -lft
MAKE		+= --no-print-directory

# Directories
SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Files
SRCS		= $(addprefix $(SRC_DIR)/, main.c parse.c init.c philos.c monitor.c clock.c utils.c)
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

# 1. Compile libft by calling its own Makefile
# 2. Link the objects with libft.a
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

# Ensure libft is built
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
# 	@rm $(LIBFT)
	@rm -rf $(OBJ_DIR)

fclean: clean
# 	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

# Helpers
ARGS		= 200 1 100 100 10
VFLAGS		= --tool=helgrind -s
# CFLAGS		+= -fsanitize=thread
# VFLAGS		+= --free-is-write=yes --track-lockorders=no --history-level=approx
# VFLAGS		+=--check-stack-refs=yes --delta-stacktrace=yes
r: all
	@./$(NAME) $(ARGS)

# LOG			= > log 2> errlog

v: all
	@valgrind $(VFLAGS) ./$(NAME) $(ARGS) $(LOG)

.PHONY: all clean fclean re r v