##
## makefile for make in /home/jordan.roucom/CPool_rush3
##
## Made by Jordan Rouco miguez
## Login   <jordan.roucom@epitech.net>
##
## Last update Mon Nov 14 13:39:13 2016 Jordan Rouco miguez
##

CC	=	gcc

SRCS	=	src/clean_buffer.c		\
		src/cleaner_string.c		\
		src/delay.c			\
		src/cleaner_char.c		\
		src/clewrite.c			\
		src/main.c			\
		src/readchar.c

RM	=	rm -f

OBJS	=	$(SRCS:.c=.o)

NAME	=	Clewrite

CFLAGS	=	-Wall -Wextra ##-Werror
	##-Iinclude

OPT	=	cd bonus && make

all:	$(NAME)

$(NAME): $(OBJS)
	$(OPT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) lib/my/libmy.a -Ll -O3

clean:
	$(RM) $(OBJS)
	$(OPT) clean

nclean:
	$(RM) $(OBJS)

fclean: nclean
	$(RM) $(NAME)
	$(OPT) fclean

re: fclean all

.PHONY: all clean fclean re nclean
