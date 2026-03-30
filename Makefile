NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c parsing/error.c parsing/parse.c \
       utils/disorder.c stack_utils.c \
       operations/push.c operations/swap.c \
       operations/rotate.c operations/reverse_rotate.c \
       algorithms/adaptive_sort.c algorithms/simple_sort.c \
       algorithms/radix_sort.c algorithms/chunk_sort.c \
       utils/libft_42/ft_split.c utils/libft_42/ft_atoi.c \
       utils/libft_42/ft_putstr_fd.c utils/libft_42/ft_isdigit.c \
       utils/libft_42/ft_strlen.c utils/libft_42/ft_lstnew.c \
       utils/libft_42/ft_lstadd_back.c utils/libft_42/ft_lstlast.c \
       utils/libft_42/ft_lstsize.c utils/libft_42/ft_lstclear.c \
       utils/libft_42/ft_calloc.c utils/libft_42/ft_bzero.c \
       utils/libft_42/ft_strdup.c utils/libft_42/ft_strlcpy.c \
       utils/libft_42/ft_substr.c utils/libft_42/ft_lstdelone.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
