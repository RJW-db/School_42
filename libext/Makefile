NAME =		libext.a
LIBFT =		../libft/objects/*.o

CFLAGS =	-Wall -Werror -Wextra
MKDIR_P =	mkdir -p
RM =		rm -f

MISC =		*.out \
			libft.h \
			.DS_Store \
			*.dSYM/

SRC =		exe_time.c \
			markup.c \
			print_full_width.c \
			strlen_esc.c \
			strjoin_free.c \
			strjoin_va.c \
			writing.c \
			writing_fd.c

OBJ_DIR =	objects
OBJ =		$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all:	libft_make objects_mkdir $(NAME)

$(OBJ_DIR)/%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(LIBFT) $(OBJ)

clean:
	$(RM) -r $(OBJ_DIR) $(LIBFT) $(MISC)

fclean:	clean
	$(RM) $(NAME)

re:	fclean
	all

libft_make:
	$(MAKE) -C ../libft bonus
	cp ../libft/libft.h .

objects_mkdir:
	@$(MKDIR_P) $(OBJ_DIR)

xlibext:	all clean

.PHONY:	all clean fclean re libft_make objects_mkdir xlibext
