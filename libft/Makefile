NAME      = libft.a
CC        = cc
CFLAGS    = -Wall -Wextra -Werror
AR        = ar rcs
RM        = rm -rf

# Directories
OBJ_DIR   = obj

# Files
FILES     = strchr strdup striteri strjoin strlcat strlcpy    \
            strncmp strnstr strrchr strtrim substr strmapi    \
            memchr memcmp memcpy memmove memset bzero calloc  \
            putchar_fd putendl_fd putnbr_fd putstr_fd strlen  \
            isalnum isalpha isascii isdigit isprint           \
            tolower toupper atoi itoa split                   \
            printf disp gdahex putchar putu                   \
            puthex putnbr putptr putstr

SRCS      = $(addprefix ft_, $(addsuffix .c, $(FILES)))
# This transforms 'ft_atoi.c' into 'obj/ft_atoi.o'
OBJS      = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Rule to compile .c files into the obj directory
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re