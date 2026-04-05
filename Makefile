NAME		= philo
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -Iinc/
VFLAGS		= --tool=helgrind 

O_DIR		= obj/
S_DIR		= src/
SRC_F		= main.c
SRCS		= $(addprefix $(S_DIR), $(SRC_F))
OBJS		= $(addprefix $(O_DIR), $(SRC_F:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
    
$(O_DIR)%.o: $(S_DIR)%.c
	@mkdir -p $(O_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(O_DIR)

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