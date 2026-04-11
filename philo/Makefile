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

CFLAGS		+= -fsanitize=thread
# VFLAG		= --tool=helgrind -s
# VFLAG		= --tool=drd
# VFLAG		+= --free-is-write=yes --track-lockorders=no --history-level=approx
# VFLAG		+=--check-stack-refs=yes --delta-stacktrace=yes

# Test 
# Test 
# Test 

A	= 1 800 200 200 # The philosopher should not eat and should die.
B	= 3 601 200 1 # No philosopher should die.
C	= 5 800 200 200 7 # No philosopher should die 
#	and the simulation should stop when every philosopher
#	has eaten at least 7 times.
D	= 4 410 200 200 # No philosopher should die.
E	= 4 310 200 100 # One philosopher should die.
# F	= 5 800 200 200
MAX = 4000 1000 1 1
MAX1 = 3999 1000 1 1

TEST	= 200 1000 1 1 2
INPUT	= $(TEST)

r: all
	@./$(NAME) $(INPUT)
# 	@./$(NAME) $(B)

s:
	setarch -R make r

# LOG			= > log 2> errlog

v: all
	valgrind $(VFLAG) ./$(NAME) $(INPUT) $(LOG)

.PHONY: all clean fclean re r v
