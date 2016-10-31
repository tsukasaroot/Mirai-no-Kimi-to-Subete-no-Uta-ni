##
## makefile for make in /home/jordan.roucom/CPool_rush3
##
## Made by Jordan Rouco miguez
## Login   <jordan.roucom@epitech.net>
##
## Last update Mon Oct 31 15:04:19 2016 Jordan Rouco miguez
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
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) lib/my/libmy.a -Ll

clean:
	$(RM) $(OBJS)
	$(OPT) clean

fclean: clean
	$(RM) $(NAME)
	$(OPT) fclean

re: fclean all

.PHONY: all clean fclean re
