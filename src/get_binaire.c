/*
** EPITECH PROJECT, 2019
** get binairy name
** File description:
** matchsticks
*/

#include "../include/my.h"

char *put_zero_begin(char *str, int len)
{
    int y = 0;
    char *tmp = malloc(sizeof(char) * len);
    int i = 0;

    for (i = 0; i < len; i++) {
        if (i < len - my_strlen(str))
            tmp[i] = '0';
        else
            tmp[i] = str[y++];
    }
    tmp[i] = '\0';
    return (tmp);
}

char **get_bin_all_lines(param_game_t param_game, int len_res)
{
    char **bin_c = malloc(sizeof(char *) * param_game.size);

    for (int i = 0; i < param_game.size; i++) {
        bin_c[i] = my_strdup(int_to_str(nbr_base(param_game.sticks[i], "01")));
        if (my_strlen(bin_c[i]) < len_res)
            bin_c[i] = put_zero_begin(bin_c[i], len_res);
    }
    return (bin_c);
}

char *get_res_all_lines(param_game_t param_game, char **bin_c, int len_res)
{
    char *res = malloc(sizeof(char) * len_res);
    int res_i;
    int bin;

    for (int i = 0; i < len_res; i++)
        res[i] = '0';
    for (int y = len_res - 1; y >= 0; y--)
        for (int i = 0; i < param_game.size; i++) {
            res_i = char_to_int(res[y]);
            bin = char_to_int(bin_c[i][y]);
            res[y] = int_to_char(res_i + bin);
        }
    if (my_strlen(res) < len_res)
        res = put_zero_begin(res, len_res);
    return (res);
}
