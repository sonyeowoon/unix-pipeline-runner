NAME = pipex

SRCS = pipex.c \
	   libft/ft_putstr_fd.c \
	   libft/ft_strlen.c \
	   libft/ft_strjoin.c \
	   libft/ft_strncmp.c \
	   libft/ft_split.c \
	   pipex_error.c \
	   pipex_util.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
