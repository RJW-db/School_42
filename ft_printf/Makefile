NAME =			libftprintf.a
LIBFT =			libft/objects/*.o

CFLAGS =		-Wall -Werror -Wextra -g
MKDIR_P =		mkdir -p
RM =			rm -f

MISC =			*.out \
				libft.h \
				.DS_Store \
				*.dSYM/

SRC			=	ft_printf.c \
				ft_printf_count.c \
				ft_printf_utils.c \
				ft_bonus_flags.c \
				ft_bonus_sort_spec.c \
				ft_bonus_char.c \
				ft_bonus_str.c \
				ft_bonus_str_count.c \
				ft_bonus_int.c \
				ft_bonus_unsigned.c

OBJ_DIR =	objects
OBJ =		$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all:	objects_mkdir $(NAME)

$(OBJ_DIR)/%.o: %.c
	@cc $(CFLAGS) -c $< -o $@
	# @cc -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	$(RM) -r $(OBJ_DIR) $(LIBFT) $(MISC)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus:	all

objects_mkdir:
	@$(MKDIR_P) $(OBJ_DIR)

.PHONY: all, clean, fclean, re, bonus, objects_mkdir