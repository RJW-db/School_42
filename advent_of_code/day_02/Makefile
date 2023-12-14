NAME =		Day_2_Cube_Conundrum.out
LIBRARY =	../library
ARCHIVE =	../library/archive.a

MISC =		*.out \
			.DS_Store \
			*.dSYM/

SRC =		day_02_p1.c

CFLAGS =	-Wall -Werror -Wextra -g
RM =		rm -rf

all:	make_archive create

create: $(SRC) $(ARCHIVE)
	cc $(CFLAGS) $(SRC) $(ARCHIVE) -o $(NAME)
	./$(NAME) subject/text.txt
	
clean:
	$(RM) $(LIBRARY) $(MISC)

fclean:	clean
	$(MAKE) -C ../.. fclean

re:	fclean all

make_archive:
	$(MAKE) -C ../.. o
	cp -r ../$(LIBRARY) ../

run: $(SRC) $(ARCHIVE)
	cc $(CFLAGS) $(SRC) $(ARCHIVE)
	./a.out subject/text.txt

cc_zshrc_alias: make_archive $(SRC) $(ARCHIVE)
	cc $(CFLAGS) $(SRC) $(ARCHIVE)

xday:	all clean

.PHONY:	all create clean fclean re make_archive run cc_zshrc_alias xday
