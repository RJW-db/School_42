NAME =		get_next_line.a

CFLAGS =	-Wall -Werror -Wextra
RM =		rm -f

MISC =		*.out \
			.DS_Store \
			*.dSYM/

SRC =		get_next_line.c \
			get_next_line_utils.c

BSRC =		get_next_line_bonus.c \
			get_next_line_utils_bonus.c

OBJ_DIR =	objects
OBJ =		$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BOBJ =		$(addprefix $(OBJ_DIR)/, $(BSRC:.c=.o))

MKDIR_P =	mkdir -p

all:	objects_mkdir $(NAME)

$(OBJ_DIR)/%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

bonus:	objects_mkdir $(BOBJ)
	@ar rcs $(NAME) $(BOBJ)

clean:
	$(RM) -r $(OBJ_DIR) $(MISC)

fclean:	clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

objects_mkdir:
	@$(MKDIR_P) $(OBJ_DIR)

xget:	all clean

.PHONY:	all bonus clean fclean re objects_mkdir xget
