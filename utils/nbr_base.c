/*
** EPITECH PROJECT, 2018
** nbr base
** File description:
** 15
*/

#include "../include/my.h"

int nbr_base(int nbr, char const *base)
{
    int len_base = my_strlen(base);
    int res = 0;

    nbr = nbr < 0 ? -nbr : nbr;
    if (nbr == 0)
        return (0);
    else
        res = nbr_base(nbr / len_base, base);
    res = res * 10 + (base[nbr % len_base] - 48);
    return (res);
}
