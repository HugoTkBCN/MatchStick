/*
** EPITECH PROJECT, 2019
** print map
** File description:
** matchstick
*/

#include "../include/my.h"

void print_line(int line, param_game_t param_game)
{
    int max;

    for (int i = 0; i <= (param_game.size * 2) - 2; i++) {
        max = ((param_game.size - 1) - line) + param_game.sticks[line - 1];
        if (i > ((param_game.size - 1) - line) && i <= max)
            my_putstr("|");
        else
            my_putstr(" ");
    }
    my_putstr("*\n*");
}

void print_turn(int player, char *line, char *nb_matches)
{
    if (player == 1) {
        my_putstr("Player removed ");
        my_putstr(nb_matches);
        my_putstr(" match(es) from line ");
        my_putstr(line);
        my_putstr("\n");
    } else if (player == 2) {
        my_putstr("AI's turn...\n");
        my_putstr("AI removed ");
        my_putstr(nb_matches);
        my_putstr(" match(es) from line ");
        my_putstr(line);
        my_putstr("\n");
    }
}

int *print_map(char *line, char* nb_matc, int player,
                param_game_t *param_game)
{
    char *styl;

    if ((param_game->sticks[str_to_int(line) - 1] - str_to_int(nb_matc)) < 0) {
        styl = my_strdup(int_to_str(param_game->sticks[str_to_int(line) - 1]));
        nb_matc = my_strdup(styl);
        free(styl);
    }
    param_game->sticks[str_to_int(line) - 1] -= str_to_int(nb_matc);
    param_game->sticks_removed += str_to_int(nb_matc);
    print_turn(player, line, nb_matc);
    for (int i = 0; i <= param_game->size * 2; i++)
        my_putchar('*');
    my_putstr("\n*");
    for (int i = 1; i <= param_game->size; i++)
        print_line(i , *param_game);
    for (int i = 0; i <= param_game->size * 2 - 1; i++)
        my_putchar('*');
    my_putstr("\n");
    end_game(*param_game) == 0 ? my_putchar('\n') : 0;
    return (param_game->sticks);
}
