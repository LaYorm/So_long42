NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = objs
PRINTF_SRC = ft_printf/ft_printf.c ft_printf/ft_puthexa_lower.c ft_printf/ft_puthexa_upper.c \
		ft_printf/ft_put_adress.c ft_printf/ft_putnbr_count.c ft_printf/ft_putstr_count.c \
		ft_printf/ft_putchar_count.c ft_printf/ft_put_unsigned.c \

GNL_SRC = Get_next_line/get_next_line.c Get_next_line/get_next_line_utils.c

SRC = ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c ft_putnbr_fd.c ft_lstnew.c \
		ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		$(PRINTF_SRC) $(GNL_SRC) \

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir ${SRC:.c=.o}))

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c libft.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: ft_printf/%.c ft_printf/ft_printf.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: Get_next_line/%.c Get_next_line/get_next_line.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
