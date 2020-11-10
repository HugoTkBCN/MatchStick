/*
** EPITECH PROJECT, 2018
** get next line
** File description:
** elementary
*/

#include "../include/my.h"

char *my_strncpy(char *dest, char *src, int n)
{
    int i;

    for (i = 0; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    if (n < i)
        dest[i] = '\0';
    return (dest);
}

char *empty_line(char *str_line, int loop, char *buff, int *nbr_calls)
{
    int len = str_line ? my_strlen(str_line) : 0;
    char *new_str = malloc((len + loop + 1) * sizeof(char));

    if (new_str == NULL)
        return (NULL);
    else if (str_line)
        my_strncpy(new_str, str_line, len);
    else
        my_strncpy(new_str, "", len);
    new_str[len + loop] = '\0';
    my_strncpy(new_str + len, buff + *nbr_calls, loop);
    if (str_line)
        free(str_line);
    *nbr_calls += (loop + 1);
    return (new_str);
}

char *get_next_line(int fd)
{
    static char buff[READ_SIZE];
    char *str_line = NULL;
    static int n_c_buff = 0;
    static int nbr_calls = 0;

    for (int loop = 0; 1; loop++) {
        if (n_c_buff <= nbr_calls && !(n_c_buff = read(fd, buff, READ_SIZE)))
                return (str_line);
        else if (n_c_buff <= nbr_calls && n_c_buff == -1)
                return (NULL);
        loop = n_c_buff <= nbr_calls ? 0 : loop;
        nbr_calls = n_c_buff <= nbr_calls ? 0 : nbr_calls;
        if (buff[nbr_calls + loop] == '\n' || n_c_buff == 0)
            return (str_line = empty_line(str_line, loop, buff, &nbr_calls));
        else if (nbr_calls + loop == n_c_buff - 1)
            str_line = empty_line(str_line, loop + 1, buff, &nbr_calls);
        n_c_buff = n_c_buff;
        if (nbr_calls + loop == n_c_buff - 1 && str_line == NULL)
            return (NULL);
    }
}
