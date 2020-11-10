/*
** EPITECH PROJECT, 2019
** checks play
** File description:
** matchstick
*/

#include "../include/my.h"

int check_sticks(int line, int nb_matches, param_game_t param_game)
{
    if (param_game.sticks[line - 1] - nb_matches < 0)
        return (EXIT_ERROR);
    return (0);
}

int check_error(int line, int nb_matches, param_game_t param_game)
{
    if (nb_matches < 1 || nb_matches > param_game.nbr_turn) {
        if (nb_matches < 1)
            my_putstr("Error: you have to remove at least one match\n");
        else {
            my_putstr("Error: you cannot remove more than ");
            my_put_nbr(param_game.nbr_turn);
            my_putstr(" matches per turn\n");
        }
        return (EXIT_ERROR);
    } else if (line < 1 || line > param_game.size) {
        my_putstr("Error: this line is out of range\n");
        return (EXIT_ERROR);
    } else {
        if (check_sticks(line, nb_matches, param_game) == EXIT_ERROR) {
            my_putstr("Error: not enough matches on this line\n");
            return (EXIT_ERROR);
        }
    }
    return (0);
}

int check_play(char *line_c, char *nb_matches_c, param_game_t param_game)
{
    int ret;

    if (my_str_isnum(line_c) == 0 || my_str_isnum(nb_matches_c) == 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (EXIT_ERROR);
    }
    ret = check_error(str_to_int(line_c), str_to_int(nb_matches_c), param_game);
    if (ret == EXIT_ERROR)
        return (EXIT_ERROR);
    return (0);
}
