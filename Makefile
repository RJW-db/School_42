NAME =		archive.a
LIBFT =		libft/objects/*.o
GNL =		get_next_line/objects/*.o
LIBEXT =	libext/objects/*.o
LIB = 		library

RM =		rm -f
CFLAGS =	-Wall -Wextra -Werror
MKDIR_P =	mkdir -p

MISC =		*.out \
			*.h \
			main.c \
			.DS_Store \
			*.dSYM/

all: $(NAME)

$(NAME): libft_make gnl_make libext_make
	ar rcs $(NAME) $(LIBFT) $(GNL) $(LIBEXT)
	cc $(CFLAGS) ./libext/create_header.c archive.a
	./a.out libft.h get_next_line.h libext.h
	$(RM) a.out
	cp ./main/main.c .

libft_make:
	$(MAKE) -C libft bonus
	cp ./libft/libft.h .

gnl_make:
	$(MAKE) -C get_next_line bonus
	cp ./get_next_line/get_next_line.h .

libext_make:
	$(MAKE) -C libext
	cp ./libext/libext.h .

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C get_next_line clean
	$(MAKE) -C libext clean
	$(RM) -r $(MISC)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C get_next_line fclean
	$(MAKE) -C libext fclean
	$(RM) -r $(NAME) $(LIB)

re: fclean all

objects_mkdir:
	@$(MKDIR_P) $(LIB)

o:	all objects_mkdir
	mv *.h archive.a main.c $(LIB)

.PHONY: all libft_make gnl_make clean fclean re