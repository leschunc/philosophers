NAME		= philo
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -Iinc -Ilibft
# LDFLAGS		= -Llibft -lft
MAKE		+= --no-print-directory

SRC_DIR		= src
OBJ_DIR		= obj
# LIBFT_DIR	= libft
# LIBFT		= $(LIBFT_DIR)/libft.a

# Files
SRCS		= $(addprefix $(SRC_DIR)/, main.c parse.c init.c philos.c monitor.c clock.c utils.c)
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

# $(LIBFT):
# 	@$(MAKE) -C $(LIBFT_DIR)

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

CFLAGS		+= -fsanitize=thread
# VFLAG		= --tool=helgrind -s
# VFLAG		= --tool=drd
# VFLAG		+= --free-is-write=yes --track-lockorders=no --history-level=approx
# VFLAG		+=--check-stack-refs=yes --delta-stacktrace=yes

# Test 
# Test 
# Test 

# Test 1 800 200 200. The philosopher should not eat and should die.
# Test 5 800 200 200. No philosopher should die.
# Test 5 800 200 200 7. No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times.
# Test 4 410 200 200. No philosopher should die.
# Test 4 310 200 100. One philosopher should die.

CYC = 3
EAT = 200
RST = 200

A = 1 800 $(EAT) $(RST) $(CYC)
B = 5 800 $(EAT) $(RST) $(CYC)
C = 5 800 $(EAT) $(RST) $(CYC)
D = 4 410 $(EAT) $(RST) $(CYC)
E = 4 300 $(EAT) 100
F = 4000 4000 $(EAT) $(RST) $(CYC)
G = 3999 4000 $(EAT) $(RST) $(CYC)

TEST	= 1 400 200 200
INPUT	= $(TEST)

r: all
	@./$(NAME) $(TEST)

t: all
	@./$(NAME) $(B)
	@./$(NAME) $(C)
	@./$(NAME) $(D)
	@./$(NAME) $(E)
	@./$(NAME) $(F)
	@./$(NAME) $(G)
	@./$(NAME) $(A)

s:
	setarch -R make r

v: all
	valgrind $(VFLAG) ./$(NAME) $(INPUT) $(LOG)

.PHONY: all clean fclean re r v