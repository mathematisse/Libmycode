/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base gline functions
*/

#ifndef GLINE_H
    #define GLINE_H
    #include <stdio.h>
    #include "loop.h"

void pprompt(const char *prompt);
int gline(char **trgt, size_t *len, FILE *fp, const char *prompt);
int gline_loop(loop_func_t func, void *data, const char *prompt);

#endif /* !GLINE_H */
