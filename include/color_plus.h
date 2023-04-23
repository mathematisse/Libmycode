/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base Color macros
*/

#ifndef COLOR_PLUS_H
    #define COLOR_PLUS_H

    #define STARTP         "\x1b["
    #define TCOLOR      "38;5;"
    #define BCOLOR      "48;5;"
    #define ENDP         "m"
    #define RESETP          STARTP "0" ENDP

    #define RGB_WHITE (int[3]) {5, 5, 5}
    #define RGB_BLACK (int[3]){0, 0, 0}
    #define RGB_RED (int[3]){5, 0, 0}
    #define RGB_GREEN (int[3]){0, 5, 0}
    #define RGB_BLUE (int[3]){0, 0, 5}
    #define RGB_YELLOW (int[3]){5, 5, 0}
    #define RGB_MAGENTA (int[3]){5, 0, 5}
    #define RGB_CYAN (int[3]){0, 5, 5}
    #define RGB_GRAY (int[3]){2, 2, 2}
    #define RGB_NORMAL (int[3]){4, 4, 4}

int rgb_to_ansi(int r, int g, int b);
int gray_scale_to_ansi(int gray);
void get_lerp(int res[6], const int start[3], const int end[3]);
void coloropf(const char *str, const char *style, int color);
#endif /* !COLOR_PLUS_H */
