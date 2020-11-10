/*
** EPITECH PROJECT, 2019
** utils for ai
** File description:
** matchstick
*/

#include "../include/my.h"

int remaining_lines(param_game_t param_game)
{
    int line = 0;

    for (int i = 0; i < param_game.size; i++)
        if (param_game.sticks[i] != 0)
            line++;
    return (line);
}

int puissance(int nbr, int power)
{
    int pwd = 1;

    for (int i = 0; i < power; i++)
        pwd = pwd * nbr;
    return (pwd);
}

int get_nb_matches(int y, param_game_t param_game, int len_res)
{
    int nb_matches;

    nb_matches = puissance(2, ((len_res - 1) - y));
    return (nb_matches);
}
