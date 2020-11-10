/*
** EPITECH PROJECT, 2019
** ai one line
** File description:
** matchsticks
*/

#include "../include/my.h"

int get_last_line(param_game_t param_game)
{
    for (int i = 0; i < param_game.size; i++)
        if (param_game.sticks[i] != 0)
            return (i + 1);
    return (0);
}

int *one_line(param_game_t *param_game)
{
    int max = param_game->nbr_turn;
    int sticks;
    char *sticks_c;
    char *line_c;
    char *max_c = my_strdup(int_to_str(max));
    char *nb_matches;

    sticks = param_game->sticks[get_last_line(*param_game) - 1];
    sticks_c = my_strdup(int_to_str(sticks));
    nb_matches = sticks > max ? my_strdup(max_c) : my_strdup(sticks_c);
    if (param_game->sticks[get_last_line(*param_game) - 1] > 1)
        nb_matches = my_strdup(int_to_str(str_to_int(nb_matches) - 1));
    line_c = my_strdup(int_to_str(get_last_line(*param_game)));
    param_game->sticks = print_map(line_c, nb_matches, 2, param_game);
    return (param_game->sticks);
}
