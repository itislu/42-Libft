NAME			=			libft.a
I				=			./
D				=			dep/
O				=			obj/

SRC				=			ft_atoi.c \
							ft_bzero.c \
							ft_calloc.c \
							ft_isalnum.c \
							ft_isalpha.c \
							ft_isascii.c \
							ft_isdigit.c \
							ft_isprint.c \
							ft_memchr.c \
							ft_memcmp.c \
							ft_memcpy.c \
							ft_memmove.c \
							ft_memset.c \
							ft_strchr.c \
							ft_strdup.c \
							ft_strlcat.c \
							ft_strlcpy.c \
							ft_strlen.c \
							ft_strncmp.c \
							ft_strnstr.c \
							ft_strrchr.c \
							ft_tolower.c \
							ft_toupper.c \
							\
							ft_itoa.c \
							ft_putchar_fd.c \
							ft_putendl_fd.c \
							ft_putnbr_fd.c \
							ft_putstr_fd.c \
							ft_split.c \
							ft_striteri.c \
							ft_strjoin.c \
							ft_strmapi.c \
							ft_strtrim.c \
							ft_substr.c

SRCBONUS		=			ft_lstadd_back.c \
							ft_lstadd_front.c \
							ft_lstclear.c \
							ft_lstdelone.c \
							ft_lstiter.c \
							ft_lstlast.c \
							ft_lstmap.c \
							ft_lstnew.c \
							ft_lstsize.c

CC				=			cc
CFLAGS			=			-Wall -Wextra -Werror $(foreach X,$I,-I$(X))
ARFLAGS			=			rcs

DEP				=			$(SRC:%.c=$D%.d)
OBJ				=			$(SRC:%.c=$O%.o)
OBJBONUS		=			$(SRCBONUS:%.c=$O%.o)

.PHONY:						all bonus clean fclean re

all:						$(NAME)

$(NAME):					$(OBJ)
							ar $(ARFLAGS) $(NAME) $^

bonus:						$(OBJ) $(OBJBONUS)
							ar $(ARFLAGS) $(NAME) $^

$(OBJ) $(OBJBONUS): $O%.o:	%.c | $O
							$(CC) $(CFLAGS) -c $< -o $@

$(DEP): $D%.d:				%.c | $D
							$(CC) $(CFLAGS) -MM -MP -MF $@ -MT "$O$*.o $@" $<

$O $D:
							mkdir -p $@

cleandep:
							rm -f $(wildcard $(DEP))

cleandepdir:				cleandep
							rmdir $D

cleanobj:
							rm -f $(wildcard $(OBJ)) $(wildcard $(OBJBONUS))

cleanobjdir:				cleanobj
							rmdir $O

clean:						cleandepdir cleanobjdir

fclean:						clean
							rm -f $(NAME)

re:							fclean all

-include 					$(DEP)
