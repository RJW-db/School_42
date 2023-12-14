NAME =		libft.a

CFLAGS =	-Wall -Wextra -Werror
RM =		rm -f
MKDIR_P =	mkdir -p

MISC =		*.out \
			.DS_Store \
			*.dSYM/

SRC =		ft_strlen.c \
			ft_memmove.c \
			ft_memcpy.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_memset.c \
			ft_bzero.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

BSRC =		ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJ_DIR =	objects
OBJ =		$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BOBJ =		$(addprefix $(OBJ_DIR)/, $(BSRC:.c=.o))

all:	objects_mkdir $(NAME)

$(OBJ_DIR)/%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

bonus:	objects_mkdir $(NAME) $(OBJ) $(BOBJ)
	@ranlib $(NAME)

clean:
	$(RM) -r $(OBJ_DIR) $(MISC)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

objects_mkdir:
	@$(MKDIR_P) $(OBJ_DIR)

xlibft:	all clean

.PHONY:	all bonus clean fclean re objects_mkdir xlibft
