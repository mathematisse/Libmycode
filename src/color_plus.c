/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for lengths of primitive types
*/

#include <stddef.h>
#include <stdarg.h>
#include "color_plus.h"
#include "pf.h"

void coloropf(const char *str, const char *style, int color)
{
    opf("%s" STARTP TCOLOR "%i" ENDP "%s" RESETP, style, color, str);  
}

int rgb_to_ansi(int r, int g, int b)
{
    if (r < 0 || r > 5 || g < 0 || g > 5 || b < 0 || b > 5) {
        return 0;
    }
    return 16 + (r * 36) + (g * 6) + b;
}

int gray_scale_to_ansi(int gray)
{
    if (gray < 0 || gray > 23) {
        return 0;
    }
    return 232 + gray;
}

int mix_rgb(const int rgb1[3], const int rgb2[3], double ratio)
{
    int r = 0;
    int g = 0;
    int b = 0;

    r = rgb1[0] + (rgb2[0] - rgb1[0]) * ratio;
    g = rgb1[1] + (rgb2[1] - rgb1[1]) * ratio;
    b = rgb1[2] + (rgb2[2] - rgb1[2]) * ratio;
    return rgb_to_ansi(r, g, b);
}

void get_lerp(int res[6], const int start[3], const int end[3])
{
    int i = 0;

    while (i < 6)
    {
        res[i] = mix_rgb(start, end, ((double) i) / 5.0);
        i++;
    }
}