/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** exemple
*/

#include "include/my.h"

void print_help(void)
{
    my_putstr("./matchstick arg1 arg2\n");
    my_putstr("arg1 : size of the map, size should be between 1 and 100\n");
    my_putstr("arg2 : number of sticks that you can remove per turn ");
    my_putstr("(more that 0)\n");
    my_putstr("Good Luck\n");
}

int get_size_map(char *size)
{
    int sizei;

    if (my_str_isnum(size) == 0)
        return (MY_ERROR_RETURN);
    else
        sizei = str_to_int(size);
    sizei = sizei <= MIN_SIZE || sizei >= MAX_SIZE ? MY_ERROR_RETURN : sizei;
    return (sizei);
}

int get_nbr_turn(char *nbr)
{
    int nbr_turn;

    if (my_str_isnum(nbr) == 0)
        return (-1);
    else
        nbr_turn = str_to_int(nbr);
    return (nbr_turn);
}

int main(int ac, char **av)
{
    param_game_t param_game;
    int win;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_help();
        return (0);
    } else if (ac != 3) {
        my_putstr("Give 2 arguments.\nOr ./matchstick -h.\n");
        return (EXIT_ERROR);
    }
    param_game.size = get_size_map(av[1]);
    param_game.nbr_turn = get_nbr_turn(av[2]);
    if (param_game.size == MY_ERROR_RETURN || param_game.nbr_turn <= 0) {
        my_putstr("Give a numerique arguments. The size of the map should");
        my_putstr("be superior to 1 and inferior to 100. And the number of");
        my_putstr("sticks removed should be superior to 0.\n");
        return (EXIT_ERROR);
    }
    win = matchstick(param_game);
    return (win = win == EXIT_ERROR ? 0 : win);
}
