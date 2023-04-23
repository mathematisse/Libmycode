/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base loop functions
*/

#ifndef LOOP_H
    #define LOOP_H

enum loop_status_e {
    LOOP_CONTINUE,
    LOOP_BREAK,
    LOOP_EXIT,
    LOOP_ERROR
};

typedef enum loop_status_e loop_status_t;
typedef loop_status_t (*loop_func_t)(const char *line, void *data);

int gline_loop(loop_func_t func, void *data, const char *prompt);
loop_status_t yn_query(const char *line, void *data);
loop_status_t choice_query(const char *line, void *data);
loop_status_t int_query(const char *line, void *data);
loop_status_t double_query(const char *line, void *data);
loop_status_t char_query(const char *line, void *data);
loop_status_t str_query(const char *line, void *data);
#endif /* !LOOP_H */
