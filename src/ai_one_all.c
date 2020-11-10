/*
** EPITECH PROJECT, 2019
** all one
** File description:
** matchstick
*/

#include "../include/my.h"

int all_line_one_but_one_no(param_game_t param_game)
{
    int longer = 0;

    for (int i = 0; i < param_game.size; i++)
        if (param_game.sticks[i] != 1 && param_game.sticks[i] != 0)
            longer++;
    if (longer != 1)
        return (0);
    else
        return (1);
}

int get_bigger_line(param_game_t param_game)
{
    for (int i = 0; i < param_game.size; i++)
        if (param_game.sticks[i] != 1 && param_game.sticks[i] != 0)
            return (i + 1);
}

int one_stick_on_line_is_par(param_game_t param_game)
{
    int lines_one = 0;

    for (int i = 0; i < param_game.size; i++)
        if (param_game.sticks[i] == 1)
            lines_one++;
    if (lines_one % 2 == 0)
        return (1);
    else
        return (0);
}

int *remove_entire_line_or_keep_one(param_game_t *param_game)
{
    int max = param_game->nbr_turn;
    int sticks;
    char *sticks_c;
    char *line_c;
    char *max_c = my_strdup(int_to_str(max));
    char *nb_matches;

    sticks = param_game->sticks[get_bigger_line(*param_game) - 1];
    sticks_c = my_strdup(int_to_str(sticks));
    nb_matches = sticks > max ? my_strdup(max_c) : my_strdup(sticks_c);
    if (one_stick_on_line_is_par(*param_game) == 1)
        nb_matches = my_strdup(int_to_str(str_to_int(nb_matches) - 1));
    line_c = my_strdup(int_to_str(get_bigger_line(*param_game)));
    param_game->sticks = print_map(line_c, nb_matches, 2, param_game);
    return (param_game->sticks);
}
