/*
** EPITECH PROJECT, 2019
** include
** File description:
** exemple
*/

#ifndef MY_H_
#define MY_H_

#include "lib.h"
#include "define.h"
#include "struct.h"
#include "get_next_line.h"

int my_str_isnum(char const *);
void my_putchar(char);
int my_put_nbr(int);
void my_putstr(char const *);
int my_strlen(char const *);
char *my_strdup(char *);
char *my_strcpy(char *, char *);
char *get_next_line(int);
int *ai_play(param_game_t *);
int *player_play(param_game_t *);
int *print_map(char *, char *, int, param_game_t *);
void print_line(int, param_game_t);
int check_play(char *, char *, param_game_t);
int check_sticks(int, int, param_game_t);
int str_to_int(char *);
char *int_to_str(int);
char *my_revstr(char *);
int matchstick(param_game_t);
int make_human_and_ai_play_a_round(param_game_t);
int end_game(param_game_t);
int nbr_base(int, char const *);
char int_to_char(int);
int char_to_int(char);
int get_last_line(param_game_t);
int *one_line(param_game_t *);
int get_bigger_line_on_two(param_game_t);
int other_line_not_one(param_game_t);
int *two_lines(param_game_t *);
int get_line_was_more(param_game_t);
int *two_egals_more_one(param_game_t *);
int two_are_egals(param_game_t);
char *put_zero_begin(char *, int);
char **get_bin_all_lines(param_game_t, int);
char *get_res_all_lines(param_game_t, char **, int);
int *random_ai(param_game_t *);
int *remove_one_ramdom(param_game_t *);
int remaining_lines(param_game_t);
int puissance(int, int);
int get_nb_matches(int, param_game_t, int);
int all_line_one_but_one_no(param_game_t);
int get_bigger_line(param_game_t);
int one_stick_on_line_is_par(param_game_t );
int *remove_entire_line_or_keep_one(param_game_t *);

#endif /* !MY_H_ */
