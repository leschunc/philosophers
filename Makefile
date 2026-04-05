NAME		= philo
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
VFLAG		= --tool=helgrind 

OBJ_DIR		= obj/
SRC_DIR		= src/

SRC_FILES	= main.c
SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
    
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

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