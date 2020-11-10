/*
** EPITECH PROJECT, 2019
** random ai
** File description:
** matchstick
*/

#include "../include/my.h"

int *remove_one_ramdom(param_game_t *param_game)
{
    char *line;
    char *nb_matches;

    for (int i = 0; i < param_game->size; i++) {
        if (param_game->sticks[i] != 0) {
            line = my_strdup(int_to_str(i + 1));
            nb_matches = my_strdup("1");
            param_game->sticks = print_map(line, nb_matches, 2, param_game);
            return (param_game->sticks);
        }
    }
}

int get_nb_match_random(param_game_t *param_game, int line)
{
    int loop = 1;
    int nb_matches = 0;

    srandom(0);
    for (int time = 0; loop == 1; time++) {
        param_game->sticks = time >= 10 ?
            remove_one_ramdom(param_game) : param_game->sticks;
        loop = time >= 10 ? -1 : 1;
        nb_matches = random() % ((param_game->size * 2) + 1);
        if (nb_matches > 0 && nb_matches <= param_game->nbr_turn)
            loop = nb_matches <= param_game->sticks[line - 1] ? 0 : loop;
    }
    return (nb_matches);
}

int *random_ai(param_game_t *param_game)
{
    int loop = 1;
    long int line;
    long int nb_matches;

    srandom(0);
    for (int time = 0; loop == 1; time++) {
        line = random() % param_game->size;
        param_game->sticks = time >= 10 ?
            remove_one_ramdom(param_game) : param_game->sticks;
        loop = time >= 10 ? -1 : 1;
        if (line < param_game->size && line > 0 && loop == 1) {
            nb_matches = param_game->sticks[line - 1] > 0 ?
                get_nb_match_random(param_game, line) : nb_matches;
            loop = param_game->sticks[line - 1] > 0 ? 0 : 1;
        }
    }
    if (loop == 0)
        param_game->sticks = print_map(int_to_str(line),
                                        int_to_str(nb_matches), 2, param_game);
    return (param_game->sticks);
}
