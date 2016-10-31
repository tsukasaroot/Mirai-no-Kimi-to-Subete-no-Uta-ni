##
## Makefile for  in /home/jordan.roucom/CPool_rush3
## 
## Made by Jordan Rouco miguez
## Login   <jordan.roucom@epitech.net>
## 
## Started on  Sat Oct 29 23:20:36 2016 Jordan Rouco miguez
## Last update Mon Oct 31 09:38:32 2016 Jordan Rouco miguez
##

SRC	=	../lib/my/my_find_prime_sup.c		\
		../lib/my/my_put_nbr.c			\
		../lib/my/my_square_root.c		\
		../lib/my/my_str_isnum.c		\
		../lib/my/my_strncpy.c			\
		../lib/my/my_getnbr.c			\
		../lib/my/my_putstr.c			\
		../lib/my/my_strcapitalize.c		\
		../lib/my/my_str_isprintable.c		\
		../lib/my/my_strstr.c			\
		../lib/my/my_isneg.c			\
		../lib/my/my_revstr.c			\
		../lib/my/my_strcmp.c			\
		../lib/my/my_str_isupper.c		\
		../lib/my/my_strupcase.c		\
		../lib/my/my_is_prime.c			\
		../lib/my/my_showmem.c			\
		../lib/my/my_strcpy.c			\
		../lib/my/my_strlen.c			\
		../lib/my/my_swap.c			\
		../lib/my/my_power_rec.c		\
		../lib/my/my_showstr.c			\
		../lib/my/my_str_isalpha.c		\
		../lib/my/my_strlowcase.c		\
		../lib/my/my_putchar.c			\
		../lib/my/my_sort_int_tab.c		\
		../lib/my/my_str_islower.c		\
		../lib/my/my_strncmp.c			\
		../lib/my/my_put_error.c

RM	=	rm -f

LIB	=	../lib/my/

OBJS	=	$(SRC:.c=.o)

NAME	=	$(LIB)libmy.a

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
