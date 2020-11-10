/*
** EPITECH PROJECT, 2019
** part 2 step 1
** File description:
** bootstrap matchstick
*/

#include "../include/my.h"

int end_game(param_game_t param_game)
{
    if (param_game.total_sticks == param_game.sticks_removed)
        return (1);
    else
        return (0);
}

int make_human_and_ai_play_a_round(param_game_t param_game)
{
    while (end_game(param_game) == 0) {
        my_putstr("Your turn:\n");
        param_game.sticks = player_play(&param_game);
        if (end_game(param_game) == 1) {
            my_putstr("You lost, too bad...\n");
            return (LOST_EXIT);
        } else if (param_game.sticks[0] == EXIT_ERROR)
            return (EXIT_ERROR);
        param_game.sticks = ai_play(&param_game);
        if (end_game(param_game) == 1) {
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return (WIN_EXIT);
        }
        if (param_game.sticks[0] == EXIT_ERROR)
            return (EXIT_ERROR);
    }
}
