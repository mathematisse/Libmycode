/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Main function for compiled binary demo
*/

#include <stdlib.h>
#include <stdio.h>
#include "pf.h"
#include "gf.h"
#include "str.h"
#include "log.h"
#include "color_plus.h"
#include "gline.h"

#define FORMAT "%s! [%i;%i] %c is a letter, like %c. The %s has %d and %d stuff. Big number : %i. That was %s!\n"
#define ARGS "Hello", 1, 2, 'a', 'b', "World", 42.42, -69.69, 987654321, "Difficult"
#define DARGS (char *) data[0], *((int *) data[1]), *((int *) data[2]), *((char *) data[3]), *((char *) data[4]), (char *) data[5], *((double *) data[6]), *((double *) data[7]), *((int *) data[8]), (char *) data[9]

void title_box(const char *title, const char *note, const char *descr)
{
    pboxf("#s0 nst# ", "PROJECT:", title, note, "DESCRIPTION:", descr);
}

/// @brief Prints a list in a box
/// @param title the title of the list
/// @param text the text to print before the list
/// @param  ... is (size_t, ...) where size_t is the nb of elems in the list
void list_box(const char *title, const char *text, ...)
{
    va_list args;

    va_start(args, text);
    pboxf("2t", title, text);
    vpboxf("L ", args);
    va_end(args);
}

void text_box(const char *longtext)
{
    char *cpy = NULL;
    char **lines = NULL;
    size_t len = 0;

    cpy = sdup(longtext);
    lines = sslice(cpy, "\n");
    while (lines[len]) {
        pboxf("t", lines[len]);
        len++;
    }
    pboxf(" ");
    free(cpy);
    free(lines);
}


enum input_type_e {
    INPUT_TYPE_INT,
    INPUT_TYPE_DOUBLE,
    INPUT_TYPE_STRING,
    INPUT_TYPE_CHAR,
    INPUT_TYPE_YESNO,
    INPUT_TYPE_NONE,
    INPUT_TYPE_CHOICE
};

typedef enum input_type_e input_type_t;

int input_box(const char *query, input_type_t type, void *data)
{
    char *input = NULL;
    loop_func_t loop = NULL;

    pboxf("#");
    switch (type) {
        case INPUT_TYPE_INT: loop = int_query; break;
        case INPUT_TYPE_DOUBLE: loop = double_query; break;
        case INPUT_TYPE_STRING: loop = str_query; break;
        case INPUT_TYPE_CHAR: loop = char_query; break;
        case INPUT_TYPE_YESNO: loop = yn_query; break;
        case INPUT_TYPE_CHOICE: loop = choice_query; break;
        default: break;
    }
    return gline_loop(loop, data, query);
}


int main(void)
{
    xl_print("libmycode demo");
    title_box("Public_Library", "LIBRARY BEING BUILT", "This is a demo of the Public Library");
    text_box(
        "  This is intended to be a binary demo of the built Library.\n"
        "It will showcase some terminal logging print features, like\n"
        "right now. Then, it will start a csfml demo window, and\n"
        "will run a few showcases of the library's features.\n"
        "  The library is still being built, so some features are not\n"
        "implemented yet. The goal is to have a library that can be\n"
        "used in any project, and that can be easily extended.\n"
        "  The purpose of it is as much to use it as tool box, but\n"
        "also to use it as debugger.");
    list_box(" > List of Challenges", "This Library follows a few challenges:",
        3, "No for loops", "Increment ptr (ptr++, no [i]) when possible",
        "Reduced system calls to minimum");
    char *str = quicks(FORMAT, ARGS);
    opf("Quick format : %s", str);
    void **data = sgf(FORMAT, str);
    opf("SGF datas : " FORMAT, DARGS);
    switch (input_box("Enter an integer : ", INPUT_TYPE_INT, data[1])) {
        case 0: opf("You entered an integer\n"); break;
        case 1: opf("Exiting\n"); return 0;
        case 84: opf("Error\n"); return 84;
        default: opf("Unknown error\n"); return 84;
    }
    switch (input_box("Enter a double : ", INPUT_TYPE_DOUBLE, data[6])) {
        case 0: opf("You entered a double\n"); break;
        case 1: opf("Exiting\n"); return 0;
        case 84: opf("Error\n"); return 84;
        default: opf("Unknown error\n"); return 84;
    }
    switch (input_box("Enter a string : ", INPUT_TYPE_STRING, &data[5])) {
        case 0: opf("You entered a string\n"); break;
        case 1: opf("Exiting\n"); return 0;
        case 84: opf("Error\n"); return 84;
        default: opf("Unknown error\n"); return 84;
    }
    opf("SGF datas : " FORMAT, DARGS);
    return 0;
}
