/*
** EPITECH PROJECT, 2019
** ai two lines
** File description:
** matchsticks
*/

#include "../include/my.h"

int get_bigger_line_on_two(param_game_t param_game)
{
    int first = 0;
    int line_1 = 0;
    int line_2 = 0;

    for (int i = 0; i < param_game.size; i++) {
        if (param_game.sticks[i] != 0 && first == 0) {
            line_1 = i;
            first = 1;
        } else if (param_game.sticks[i] != 0)
            line_2 = i;
    }
    if (param_game.sticks[line_1] > param_game.sticks[line_2])
        return (line_1 + 1);
    else
        return (line_2 + 1);
}

int other_line_not_one(param_game_t param_game)
{
    int first = 0;
    int line_1 = 0;
    int line_2 = 0;

    for (int i = 0; i < param_game.size; i++) {
        if (param_game.sticks[i] != 0 && first == 0) {
            line_1 = i;
            first = 1;
        } else if (param_game.sticks[i] != 0)
            line_2 = i;
    }
    if (param_game.sticks[line_1] == 1 || param_game.sticks[line_2] == 1)
        return (0);
    else
        return (1);
}

int *two_lines(param_game_t *param_game)
{
    int max = param_game->nbr_turn;
    int sticks;
    char *sticks_c;
    char *line_c;
    char *max_c = my_strdup(int_to_str(max));
    char *nb_matches;

    sticks = param_game->sticks[get_bigger_line_on_two(*param_game) - 1];
    sticks_c = my_strdup(int_to_str(sticks));
    nb_matches = sticks > max ? my_strdup(max_c) : my_strdup(sticks_c);
    if (param_game->sticks[get_bigger_line_on_two(*param_game) - 1] >= 4 &&
        other_line_not_one(*param_game) == 1)
        nb_matches = my_strdup(int_to_str(str_to_int(nb_matches) - 2));
    else if (other_line_not_one(*param_game) == 1)
        nb_matches = my_strdup(int_to_str(1));
    line_c = my_strdup(int_to_str(get_bigger_line_on_two(*param_game)));
    param_game->sticks = print_map(line_c, nb_matches, 2, param_game);
    return (param_game->sticks);
}
