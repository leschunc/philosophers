NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
OBJS	= $(SRCS:.c=.o)
SRCS    = $(addprefix ft_, $(addsuffix .c, $(FILES)))
FILES   = strchr strdup striteri strjoin strlcat strlcpy	\
		  strncmp strnstr strrchr strtrim substr strmapi	\
		  memchr memcmp memcpy memmove memset bzero calloc	\
		  putchar_fd putendl_fd putnbr_fd putstr_fd strlen	\
		  isalnum isalpha isascii isdigit isprint			\
		  tolower toupper atoi itoa split					\
		  printf disp gdahex putchar putu					\
		  puthex putnbr putptr putstr 						\

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 