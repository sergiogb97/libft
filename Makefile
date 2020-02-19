CC	= gcc

NAME	= libft.a

FLAGS	= -Wall -Wextra -Werror

DIR_S	= srcs

DIR_O	= objs

HEADER	= includes/libft.h

SOURCES	= ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memccpy.c \
					ft_memmove.c  \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strlen.c \
					ft_strlcpy.c \
					ft_strlcat.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strnstr.c \
					ft_strncmp.c \
					ft_atoi.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_calloc.c \
					ft_strdup.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_split.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_strrev.c \
					ft_nbrlen.c \
					ft_utoa.c \
					ft_xtoa.c \
					get_next_line.c \
					ft_printf.c \
					process_string.c \
					parse_modifiers.c \
					print_char.c \
					print_string.c \
					print_pointer.c \
					print_integer.c \
					print_unsigned_integer.c \
					print_hexadecimal.c

SRCS	= $(addprefix $(DIR_S)/,$(SOURCES))

OBJS	= $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all:	$(NAME)

$(NAME):	$(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o:	$(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	rm -rf $(DIR_O)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
