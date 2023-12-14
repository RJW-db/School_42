NAME =		Day_1_Trebuchet.out
LIBRARY =	../library
ARCHIVE =	../library/archive.a

CFLAGS =	-Wall -Werror -Wextra
RM =		rm -rf

MISC =		*.out \
			.DS_Store \
			*.dSYM/

SRC =		day_one.c

all:	make_archive create

create: $(SRC) $(ARCHIVE)
	cc $(CFLAGS) $(SRC) $(ARCHIVE) -o $(NAME)
	./$(NAME) subject/text.txt
	
clean:
	$(RM) $(LIBRARY) $(MISC)

fclean:	clean
	$(MAKE) -C ../.. fclean

re:	fclean
	all

make_archive:
	$(MAKE) -C ../.. o
	cp -r ../$(LIBRARY) ../

run:
	cc $(CFLAGS) $(SRC) $(ARCHIVE) -o $(NAME)
	./$(NAME) subject/text.txt

cc_zshrc_alias: make_archive $(SRC) $(ARCHIVE)
	cc $(CFLAGS) $(SRC) $(ARCHIVE)

xday:	all clean

.PHONY:	all create clean fclean re make_archive run cc_zshrc_alias xday
