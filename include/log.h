/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Macros for color codes
*/

#ifndef LOG_H
    #define LOG_H
    #include <stddef.h>
    #include <stdarg.h>
    #include "color.h"

    #define CCONTOUR         '#'
    #define OWIDTH           80
    #define LSEP             " - "
    #define STYLE(x)         START x END
    #define RESET            STYLE(NOSTYLE)

    #define TITLE_COLOR      WHITE
    #define TITLE_STYLE      STYLE(BOLD UNDERLINE TITLE_COLOR)
    #define TITLE2_STYLE     STYLE(BOLD TITLE_COLOR)
    #define TITLE3_STYLE     STYLE(TITLE_COLOR)
    #define NOTE_STYLE       STYLE(ITALIC YELLOW)
    #define ERROR_STYLE      STYLE(BOLD RED)
    #define WARNING_STYLE    STYLE(BOLD YELLOW)
    #define SUCCESS_STYLE    STYLE(BOLD GREEN)
    #define TEXT_STYLE       STYLE(NOSTYLE NOCOLOR)
    #define CONTOUR_STYLE    STYLE(NOSTYLE BLUE)
    #define LIST_STYLE       STYLE(DIM BRWHITE)
    #define PROMPT_STYLE     STYLE(DIM ITALIC BRCYAN)
    #define PROMPT_CSTYLE    STYLE(BOLD BRWHITE)
    #define PROMPT_FORMAT    CONTOUR_STYLE "### " RESET PROMPT_CSTYLE "[" PROMPT_STYLE "%s" RESET PROMPT_CSTYLE "] -> " RESET

    #define PSTYLE(style, str) opf(style "%s" RESET "\n", str)

    #define PTITLE(x)        pbox(x, TITLE_STYLE, OWIDTH)
    #define PTITLE2(x)       PSTYLE("\n\t\t" TITLE2_STYLE, x)
    #define PTITLE3(x)       PSTYLE("\n\t" TITLE3_STYLE, x)
    #define PNOTE(x)         PSTYLE(NOTE_STYLE, x)
    #define PERROR(x)        PSTYLE(ERROR_STYLE, x)
    #define PWARNING(x)      PSTYLE(WARNING_STYLE, x)
    #define PSUCCESS(x)      PSTYLE(SUCCESS_STYLE, x)
    #define PTEXT(x)         PSTYLE(TEXT_STYLE, x)
    #define PCONTOUR(x)      PSTYLE(PCONTOUR_STYLE, x)

    #define PLIST(x)         plist(LIST_STYLE, LSEP, x)

void pbox_eline(void);
void pbox_cline(void);
void pbox_mline(const char *str, const char *style);
void pbox_lline(const char *str, const char *style);
void pbox_rline(const char *str, const char *style);
void pbox(const char *str, const char *style);
void vpboxf_list(const char *style, const char *sep, size_t n, va_list ap);
void plist(const char *style, const char *sep, size_t n, ...);
void vpboxf(const char *format, va_list ap);
void pboxf(const char *format, ...);

void xl_print(const char *str);
#endif /* !LOG_H */
