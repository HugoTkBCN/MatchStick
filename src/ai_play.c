/*
** EPITECH PROJECT, 2019
** ai tourn
** File description:
** matchsticks
*/

#include "../include/my.h"

int *particular_case(param_game_t *param_game)
{
    if (remaining_lines(*param_game) == 1) {
        param_game->sticks = one_line(param_game);
        return (param_game->sticks);
    } else if (all_line_one_but_one_no(*param_game) == 1) {
        param_game->sticks = remove_entire_line_or_keep_one(param_game);
        return (param_game->sticks);
    }
    param_game = param_game;
    if (remaining_lines(*param_game) == 2) {
        param_game->sticks = two_lines(param_game);
        return (param_game->sticks);
    } else {
        param_game->sticks = two_egals_more_one(param_game);
        return (param_game->sticks);
    }
}

int *if_loop(param_game_t *param_game, int i, int y, int *ret)
{
    int len = my_strlen(int_to_str(nbr_base((param_game->size * 2) - 1, "01")));
    char **binaire_c = get_bin_all_lines(*param_game, len);
    char *res = my_revstr(get_res_all_lines(*param_game, binaire_c, len));

    ret[0] = 0;
    ret[1] = 0;
    ret[2] = 0;
    if (binaire_c[i][y] == '1' && i + 1 < param_game->size && y + 1 < len) {
        if ((binaire_c[i][y - 1] == '1' || binaire_c[i + 1][y - 1] == '1') &&
            res[y + 1] % 2 != 0) {
            ret[0] = i + 2;
            ret[1] = get_nb_matches(y, *param_game, len);
            ret[2] = 1;
        }
    } else if (binaire_c[i][y] == '1') {
        ret[0] = i + 1;
        ret[1] = get_nb_matches(y, *param_game, len);
        ret[2] = 1;
    }
    return (ret);
}

int *normal_case(param_game_t *param_game)
{
    int len = my_strlen(int_to_str(nbr_base((param_game->size * 2) - 1, "01")));
    char **binaire_c = get_bin_all_lines(*param_game, len);
    char *res = my_revstr(get_res_all_lines(*param_game, binaire_c, len));
    int *ret = malloc(sizeof(int) * 3);

    ret[2] = 0;
    for (int y = 0; y < len && ret[2] == 0; y++)
        for (int i = 0; i < param_game->size
                && ret[2] == 0 &&
                char_to_int(res[y]) % 2 != 0; i++)
            ret = if_loop(param_game, i, y, ret);
    if (ret[2] == 0)
        param_game->sticks = remove_one_ramdom(param_game);
    else
        param_game->sticks = print_map(int_to_str(ret[0]),
                                        int_to_str(ret[1]), 2, param_game);
    free(binaire_c);
    free(res);
    return (param_game->sticks);
}

int *like_marienbad(param_game_t *param_game)
{
    if (remaining_lines(*param_game) == 1 ||
        all_line_one_but_one_no(*param_game) == 1 ||
        remaining_lines(*param_game) == 2 ||
        (remaining_lines(*param_game) == 3 && two_are_egals(*param_game) == 1))
        param_game->sticks = particular_case(param_game);
    else
        param_game->sticks = normal_case(param_game);
    return (param_game->sticks);
}

int *ai_play(param_game_t *param_game)
{
    if (param_game->size <= 4 && param_game->nbr_turn >= 7)
        param_game->sticks = like_marienbad(param_game);
    else
        param_game->sticks = random_ai(param_game);
    return (param_game->sticks);
}
