NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
	push_swap.c \
	push_swap_utils_1.c \
	push_swap_utils_2.c \
	bench.c \
	bench_print.c \
	parse.c \
	error.c \
	disorder.c \
	stack_utils.c \
	rotate_to_top_a_b.c \
	rotate.c \
	reverse_rotate.c \
	stack.c \
	push.c \
	swap.c \
	ft_adaptive_sort.c \
	ft_simple_sort.c \
	ft_radix_sort.c \
	ft_chunk_sort.c \
	ft_chunk_utils.c \
	ft_float.c \

SRCS += \
	libft_42/ft_atoi.c \
	libft_42/ft_bzero.c \
	libft_42/ft_calloc.c \
	libft_42/ft_isalnum.c \
	libft_42/ft_isalpha.c \
	libft_42/ft_isascii.c \
	libft_42/ft_isdigit.c \
	libft_42/ft_isprint.c \
	libft_42/ft_itoa.c \
	libft_42/ft_lstadd_back.c \
	libft_42/ft_lstadd_front.c \
	libft_42/ft_lstdelone.c \
	libft_42/ft_lstiter.c \
	libft_42/ft_lstlast.c \
	libft_42/ft_lstmap.c \
	libft_42/ft_lstnew.c \
	libft_42/ft_lstsize.c \
	libft_42/ft_lstclear.c \
	libft_42/ft_memchr.c \
	libft_42/ft_memcmp.c \
	libft_42/ft_memcpy.c \
	libft_42/ft_memmove.c \
	libft_42/ft_memset.c \
	libft_42/ft_putchar_fd.c \
	libft_42/ft_putendl_fd.c \
	libft_42/ft_putnbr_fd.c \
	libft_42/ft_putstr_fd.c \
	libft_42/ft_split.c \
	libft_42/ft_strchr.c \
	libft_42/ft_strdup.c \
	libft_42/ft_striteri.c \
	libft_42/ft_strjoin.c \
	libft_42/ft_strlcat.c \
	libft_42/ft_strlcpy.c \
	libft_42/ft_strmapi.c \
	libft_42/ft_strnstr.c \
	libft_42/ft_strrchr.c \
	libft_42/ft_strtrim.c \
	libft_42/ft_substr.c \
	libft_42/ft_tolower.c \
	libft_42/ft_toupper.c \
	libft_42/ft_strlen.c \
	libft_42/ft_strncmp.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
