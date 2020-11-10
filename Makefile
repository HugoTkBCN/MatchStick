##
## EPITECH PROJECT, 2018
## makefile
## File description:
## .o 
##

SRC	=	utils/my_putchar.c	\
		utils/my_putstr.c	\
		utils/my_put_nbr.c	\
		utils/my_strlen.c	\
		utils/my_strdup.c	\
		utils/my_strcpy.c	\
		utils/get_next_line.c	\
		utils/convert.c	\
		utils/my_str_isnum.c	\
		utils/nbr_base.c	\
		src/ai_play.c	\
		src/check_plays.c	\
		src/run_game.c	\
		src/ai_one_all.c	\
		src/print.c	\
		src/random_ai.c	\
		src/ai_one_line.c	\
		src/ai_two_lines.c	\
		src/utils_ai.c	\
		src/ai_two_lines_more_one.c	\
		src/get_binaire.c	\
		src/player.c	\
		utils/my_revstr.c	\
		my_matchstick.c

NAME	=	matchstick

OBJ	=	$(SRC:.c=.o)

FLAGS =	-Wall -Werror

LIB =

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) main.c $(OBJ) $(LIB) $(FALGS)

clean:
	rm -rf $(OBJ)
fclean:		clean
	rm -rf $(NAME)

re:	fclean all
