/*
** EPITECH PROJECT, 2019
** two lines egals more one
** File description:
** matchsticks
*/

#include "../include/my.h"

int get_line_was_more(param_game_t param_game)
{
    int lines[3] = {0, 0, 0};

    for (int i = 0; i < param_game.size; i++) {
        if (param_game.sticks[i] != 0 && lines[0] == 0)
            lines[0] = i;
        else if (param_game.sticks[i] != 0 && lines[1] == 0)
            lines[1] = i;
        else
            lines[2] = param_game.sticks[i] != 0 ? i : lines[2];
    }
    if (param_game.sticks[lines[0]] == param_game.sticks[lines[1]])
        return (lines[2] + 1);
    else if (param_game.sticks[lines[0]] == param_game.sticks[lines[2]])
        return (lines[1] + 1);
    else
        return (lines[0] + 1);
}

int *two_egals_more_one(param_game_t *param_game)
{
    int max = param_game->nbr_turn;
    int sticks;
    char *sticks_c;
    char *line_c;
    char *max_c = my_strdup(int_to_str(max));
    char *nb_matches;

    sticks = param_game->sticks[get_line_was_more(*param_game) - 1];
    sticks_c = my_strdup(int_to_str(sticks));
    nb_matches = sticks > max ? my_strdup(max_c) : my_strdup(sticks_c);
    line_c = my_strdup(int_to_str(get_line_was_more(*param_game)));
    param_game->sticks = print_map(line_c, nb_matches, 2, param_game);
    return (param_game->sticks);
}

int two_are_egals(param_game_t param_game)
{
    int loop = 0;

    for (int i = 0; i < param_game.size && loop == 0; i++)
        for (int y = i + 1; y < param_game.size && loop == 0; y++)
            loop = param_game.sticks[i] == param_game.sticks[y] ? 1 : loop;
    return (loop);
}
