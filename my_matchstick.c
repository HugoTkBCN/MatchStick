/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

#include "include/my.h"

int matchstick(param_game_t param_game)
{
    int ret;

    param_game.sticks = malloc(param_game.size * sizeof(int));
    param_game.total_sticks = 0;
    param_game.sticks_removed = 0;
    for (int i = 0; i < param_game.size; i++) {
        param_game.sticks[i] = 1 + (i * 2);
        param_game.total_sticks += param_game.sticks[i];
    }
    print_map("1", "0", 3, &param_game);
    ret = make_human_and_ai_play_a_round(param_game);
    return (ret);
}
