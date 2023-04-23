/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for lengths of primitive types
*/

#include <unistd.h>
#include <stdio.h>
#include "loop.h"
#include "str.h"
#include "read.h"
#include "len.h"

loop_status_t yn_query(const char *line, void *data)
{
    int *res = (int *)data;

    if (sequal(line, "exit")) {
        return LOOP_EXIT;
    }
    if (line[0] == 'y' || line[0] == 'Y') {
        *res = 1;
        return LOOP_BREAK;
    } else if (line[0] == 'n' || line[0] == 'N') {
        *res = 0;
        return LOOP_EXIT;
    } else {
        return LOOP_CONTINUE;
    }
}

/// @brief func for gline loop to test against a list of choices
/// @param line To read from
/// @param data To test against, and to write to ([0] is the choosen)
/// @return LOOP_BREAK if found, LOOP_CONTINUE if not, LOOP_EXIT if "exit"
loop_status_t choice_query(const char *line, void *data)
{
    char **choices = (char **)data;
    int i = 1;

    while (choices[i]) {
        if (sequal(line, choices[i])) {
            choices[0] = choices[i];
            return LOOP_BREAK;
        }
        i++;
    }
    if (sequal(line, "exit")) {
        return LOOP_EXIT;
    }
    return LOOP_CONTINUE;
}

loop_status_t int_query(const char *line, void *data)
{
    int *nb = (int *)data;
    int res = 0;

    if (sequal(line, "exit")) {
        return LOOP_EXIT;
    }
    res = stoi(line);
    if (res == 0 && line[0] != '0') {
        return LOOP_CONTINUE;
    }
    *nb = res;
    return LOOP_BREAK;
}

loop_status_t double_query(const char *line, void *data)
{
    double *nb = (double *)data;
    double res = 0;

    if (sequal(line, "exit")) {
        return LOOP_EXIT;
    }
    res = stod(line);
    if (res == 0 && line[0] != '0') {
        return LOOP_CONTINUE;
    }
    *nb = res;
    return LOOP_BREAK;
}

loop_status_t char_query(const char *line, void *data)
{
    char *c = (char *)data;

    if (sequal(line, "exit")) {
        return LOOP_EXIT;
    }
    if (slen(line) != 2) {
        return LOOP_CONTINUE;
    }
    *c = line[0];
    return LOOP_BREAK;
}

loop_status_t str_query(const char *line, void *data)
{
    char **str = (char **)data;

    if (sequal(line, "exit")) {
        return LOOP_EXIT;
    }
    *str = sdupn(line, slen(line) - 1);
    return LOOP_BREAK;
}