/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for lengths of primitive types
*/

#include <unistd.h>
#include <stdio.h>
#include "loop.h"
#include "log.h"
#include "pf.h"
#include "str.h"

void pprompt(const char *prompt)
{
    opf(PROMPT_FORMAT, prompt);
}

int gline(char **trgt, size_t *len, FILE *fp, const char *prompt)
{
    if (!trgt || !len) {
        return -1;
    }
    if (fp == stdin && isatty(0) && prompt) {
        pprompt(prompt);
    }
    return getline(trgt, len, fp);
}

int gline_loop(loop_func_t func, void *data, const char *prompt)
{
    char *line = NULL;
    size_t len = 0;

    while (gline(&line, &len, stdin, prompt) != -1) {
        switch (func(line, data)) {
            case LOOP_CONTINUE:
                break;
            case LOOP_BREAK:
                return 0;
            case LOOP_EXIT:
                return 1;
            case LOOP_ERROR:
                return 84;
        }
    }
    return 0;
}
