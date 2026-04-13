NAME		= philo
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -Iinc -Ilibft
MAKE		+= --no-print-directory

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= $(addprefix $(SRC_DIR)/, main.c parse.c init.c philos.c monitor.c clock.c utils.c)
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

CFLAGS		+= -fsanitize=thread

$(NAME):  $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
# 	@rm 
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# VFLAG		= --tool=helgrind -s
# VFLAG		= --tool=drd
# VFLAG		+= --free-is-write=yes --track-lockorders=no --history-level=approx
# VFLAG		+=--check-stack-refs=yes --delta-stacktrace=yes

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

.PHONY: all clean fclean re