NAME = ft_printf_objects
CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_puthexa_lower.c ft_puthexa_upper.c ft_put_adress.c\
	ft_putnbr_count.c ft_putstr_count.c ft_putchar_count.c ft_put_unsigned.c \

OBJ = ${SRC:.c=.o}

all : $(OBJ)

$(NAME) : $(OBJ)
			@echo "ft_printf objects compiled in sub_folder."

%.o : %.c ft_printf.h
			$(CC) ${CFLAGS} -c $< -o $@

clean :
			rm -f $(OBJ)

fclean : clean

re : fclean all

.PHONY : all clean fclean re
