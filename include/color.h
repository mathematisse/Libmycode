/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Macros for color codes
*/

#ifndef COLOR_H
    #define COLOR_H
    
    #define START        "\x1b["
    #define END          "m"

    #define NOSTYLE          "0;"
    #define BOLD             "1;"
    #define DIM              "2;"
    #define ITALIC           "3;"
    #define UNDERLINE        "4;"
    #define BLINK            "5;"
    #define REVERSE          "7;"
    #define HIDDEN           "8;"
    #define CROSSED          "9;"
    #define UUNDERLINE       "21;"

    #define NOCOLOR          "39"
    #define BLACK            "30"
    #define RED              "31"
    #define GREEN            "32"
    #define YELLOW           "33"
    #define BLUE             "34"
    #define MAGENTA          "35"
    #define CYAN             "36"
    #define WHITE            "37"
    #define BRBLACK          "90"
    #define BRRED            "91"
    #define BRGREEN          "92"
    #define BRYELLOW         "93"
    #define BRBLUE           "94"
    #define BRMAGENTA        "95"
    #define BRCYAN           "96"
    #define BRWHITE          "97"

    #define BG_BLACK         "40"
    #define BG_RED           "41"
    #define BG_GREEN         "42"
    #define BG_YELLOW        "43"
    #define BG_BLUE          "44"
    #define BG_MAGENTA       "45"
    #define BG_CYAN          "46"
    #define BG_WHITE         "47"
    #define BG_DEFAULT       "49"
    #define BG_BRBLACK       "100"
    #define BG_BRRED         "101"
    #define BG_BRGREEN       "102"
    #define BG_BRYELLOW      "103"
    #define BG_BRBLUE        "104"
    #define BG_BRMAGENTA     "105"
    #define BG_BRCYAN        "106"
    #define BG_BRWHITE       "107"

#endif /* !COLOR_H */
