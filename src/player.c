/*
** EPITECH PROJECT, 2019
** player play
** File description:
** matchstick
*/

#include "../include/my.h"

char *get_player_line(void)
{
    size_t len = 0;
    int read;
    char *line;

    my_putstr("Line: ");
    if (getline(&line, &len, stdin) == EOF)
        return (NULL);
    line[my_strlen(line) - 1] = '\0';
    return (line);
}

char *get_player_matches(void)
{
    size_t len = 0;
    int read;
    char *nb_matches;

    my_putstr("Matches: ");
    if (getline(&nb_matches, &len, stdin) == EOF)
        return (NULL);
    nb_matches[my_strlen(nb_matches) - 1] = '\0';
    return (nb_matches);
}

int *player_play(param_game_t *param_game)
{
    int ret = 0;
    char *nb_matches;
    char *line;

    if ((line = get_player_line()) == NULL) {
        param_game->sticks[0] = 84;
        return (param_game->sticks);
    } else if ((ret = check_play(line, "1", *param_game)) == EXIT_ERROR)
        param_game->sticks = player_play(param_game);
    else {
        if ((nb_matches = get_player_matches()) == NULL) {
            param_game->sticks[0] = 84;
            return (param_game->sticks);
        } else if ((ret = check_play(line, nb_matches, *param_game)) == 84)
            param_game->sticks = player_play(param_game);
    }
    ret = ret;
    if (ret != EXIT_ERROR)
        param_game->sticks = print_map(line, nb_matches, 1, param_game);
    return (param_game->sticks);
}
