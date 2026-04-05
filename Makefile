NAME        = philo
CC          = cc
CFLAGS      = -Wall -Werror -Wextra -Iinc -Ilibft
LDFLAGS     = -Llibft -lft
VFLAGS      = --tool=helgrind 

SRC_DIR     = src
OBJ_DIR     = obj
SRCS        = $(SRC_DIR)/main.c
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

r:
	$(MAKE)
	./philo

v:
	$(MAKE)
	./valgrind $(VFLAG) ./philo

.PHONY: all clean fclean re