NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -lm

OBJ_DIR = obj

LIBFT_PATH = Libft/
PRINTF_PATH = Libft/ft_printf/
GNL_PATH = Libft/Get_next_line/
MLX_PATH = minilibx-linux/
BONUS_DIR = bonus/

#---- Headers----
HEADER_CLASSIC = so_long.h
HEADER_BONUS = $(BONUS_DIR)so_long_bonus.h

# --- SOURCES ---

SRC_BONUS_FILES = main_bonus.c check_map_bonus.c free_error_bonus.c \
                  import_map_bonus.c path_check_bonus.c print_map_bonus.c \
                  events_bonus.c utils_bonus.c animations_bonus.c \

SRC_SO_LONG = main.c check_map.c free_error.c import_map.c path_check.c print_map.c events.c \
			utils.c \

SRC_LIBFT_FILES = ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_strlen.c \
            ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
            ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
            ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
            ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
            ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c ft_putnbr_fd.c ft_lstnew.c \
            ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
            ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC_PRINTF_FILES = ft_printf.c ft_puthexa_lower.c ft_puthexa_upper.c \
             ft_put_adress.c ft_putnbr_count.c ft_putstr_count.c \
             ft_putchar_count.c ft_put_unsigned.c

SRC_GNL_FILES = get_next_line.c get_next_line_utils.c

# --- OBJETS ---
# On crée la liste des objets en gardant uniquement le nom du fichier sans le chemin

COMMON_OBJS =	$(addprefix $(OBJ_DIR)/, $(SRC_LIBFT_FILES:.c=.o)) \
				$(addprefix $(OBJ_DIR)/, $(SRC_PRINTF_FILES:.c=.o)) \
				$(addprefix $(OBJ_DIR)/, $(SRC_GNL_FILES:.c=.o)) 

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_SO_LONG:.c=.o)) $(COMMON_OBJS) 
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS_FILES:.c=.o)) $(COMMON_OBJS) 

# --- INCLUDES (Attention à la casse : Libft != libft) ---
INCLUDES = -I. -I$(LIBFT_PATH) -I$(PRINTF_PATH) -I$(GNL_PATH) -I$(MLX_PATH)
INCLUDES_BONUS  = -I$(BONUS_DIR) -I$(LIBFT_PATH) -I$(PRINTF_PATH) -I$(GNL_PATH) -I$(MLX_PATH)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# --- RÈGLES DE COMPILATION PRÉCISES ---

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@echo "Linking $(NAME_BONUS)..."
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX_FLAGS) -o $(NAME_BONUS)

# Fichiers à la racine
$(OBJ_DIR)/%.o: %.c $(HEADER_CLASSIC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation des fichiers du dossier bonus
$(OBJ_DIR)/%.o: $(BONUS_DIR)%.c $(HEADER_BONUS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Fichiers dans ft_printf
$(OBJ_DIR)/%.o: $(PRINTF_PATH)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Fichiers dans Get_next_line
$(OBJ_DIR)/%.o: $(GNL_PATH)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Fichiers dans Libft (parent)
$(OBJ_DIR)/%.o: $(LIBFT_PATH)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus