/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for pretty log printing
*/

#include <stdarg.h>
#include <stddef.h>
#include "log.h"
#include "str.h"
#include "len.h"
#include "pf.h"

void pbox_eline(void)
{
    char *line = NULL;

    line = snew(OWIDTH, ' ');
    line[0] = CCONTOUR;
    line[OWIDTH - 1] = CCONTOUR;
    opf(CONTOUR_STYLE "%s\n" RESET, line);
    sfree(&line);
}

void pbox_cline(void)
{
    char *line = NULL;

    line = snew(OWIDTH, CCONTOUR);
    opf(CONTOUR_STYLE "%s\n" RESET, line); 
    sfree(&line);
}

void pbox_mline(const char *str, const char *style)
{
    size_t len = slen(str);
    size_t space_len = 0;
    char *space = NULL;
    char *space2 = NULL;

    if (OWIDTH - 2 < len) {
        opf(CONTOUR_STYLE "%c%s%s%s%c\n" RESET, CCONTOUR, style, str, style, CCONTOUR);
        return;
    }
    if (len % 2 == 0) {
        space_len = (OWIDTH -len - 2) / 2;
        space = snew(space_len, ' ');
        space2 = snew(space_len, ' ');
    } else {
        space_len = (OWIDTH -len - 2) / 2;
        space = snew(space_len, ' ');
        space2 = snew(space_len + 1, ' ');
    }
    opf(CONTOUR_STYLE "%c%s%s%s" CONTOUR_STYLE "%s%c\n" RESET, CCONTOUR, space2, style, str, space, CCONTOUR);
    sfree(&space);
    sfree(&space2);
}

void pbox_lline(const char *str, const char *style)
{
    size_t len = slen(str);
    size_t space_len = 0;
    char *space = NULL;

    if (OWIDTH - 2 < len) {
        opf(CONTOUR_STYLE "%c%s%s%s%c\n" RESET, CCONTOUR, style, str, style, CCONTOUR);
        return;
    }
    space_len = OWIDTH - len - 3;
    space = snew(space_len, ' ');
    opf(CONTOUR_STYLE "%c %s%s" CONTOUR_STYLE "%s%c\n" RESET, CCONTOUR, style, str, space, CCONTOUR);
    sfree(&space);
}

void pbox_listline(const char *str, const char *style)
{
    size_t len = slen(str);
    size_t space_len = 0;
    char *space = NULL;

    if (OWIDTH - 6 < len) {
        opf(CONTOUR_STYLE "%c" "    %s%s%s" CONTOUR_STYLE"%s%c\n" RESET, CCONTOUR, style, str, RESET, style, CCONTOUR);
        return;
    }
    space_len = OWIDTH - len - 7;
    space = snew(space_len, ' ');
    opf(CONTOUR_STYLE "%c     %s%s" CONTOUR_STYLE "%s%c\n" RESET, CCONTOUR, style, str, space, CCONTOUR);
    sfree(&space);
}

void pbox_rline(const char *str, const char *style)
{
    size_t len = slen(str);
    size_t space_len = 0;
    char *space = NULL;

    if (OWIDTH - 2 < len) {
        opf(CONTOUR_STYLE "%c%s%s%s%c\n" RESET, CCONTOUR, style, str, style, CCONTOUR);
        return;
    }
    space_len = OWIDTH - len - 3;
    space = snew(space_len, ' ');
    opf(CONTOUR_STYLE "%c%s%s%s " CONTOUR_STYLE "%c\n" RESET, CCONTOUR, space, style, str, CCONTOUR);
    sfree(&space);
}

void pbox(const char *str, const char *style)
{
    size_t len = slen(str);
    char *line = NULL;
    char *space = NULL;

    if (OWIDTH - 2 < len) {
        opf(CONTOUR_STYLE "%c%s%s%s%c\n" RESET, CCONTOUR, style, str, style, CCONTOUR);
        return;
    }
    line = snew(OWIDTH, CCONTOUR);
    space = snew((OWIDTH -len - 2) / 2, ' ');
    opf(CONTOUR_STYLE "%s\n%c%s%s%s" CONTOUR_STYLE "%s%c\n%s\n" RESET,
        line, CCONTOUR, space, style, str, space, CCONTOUR, line);
    sfree(&line);
    sfree(&space);
}

void vpboxf_list(const char *style, const char *sep, size_t n, va_list ap)
{
    size_t i = 0;
    char *tmp = NULL;

    while (i < n) {
        i++;
        tmp = quicks("%i%s%s", i, sep, va_arg(ap, char *));
        pbox_listline(tmp, style);
        sfree(&tmp);
    }
}

void plist(const char *style, const char *sep, size_t n, ...)
{
    va_list ap;
    size_t i = 0;

    va_start(ap, n);
    opf(style);
    while (i < n) {
        i++;
        opf("    %i%s%s\n", i, sep, va_arg(ap, char *));
    }
    opf(RESET);
    va_end(ap);
}

static size_t pboxf_flags(const char *format, va_list ap)
{
    switch (*format) {
        case ' ': pbox_eline(); break;
        case CCONTOUR: pbox_cline(); break;
        case '0': pbox_mline(va_arg(ap, char *), TITLE_STYLE); break;
        case '1': pbox_mline(va_arg(ap, char *), TITLE2_STYLE); break;
        case '2': pbox_lline(va_arg(ap, char *), TITLE3_STYLE); break;
        case 'n': pbox_rline(va_arg(ap, char *), NOTE_STYLE); break;
        case 'e': pbox_lline(va_arg(ap, char *), ERROR_STYLE); break;
        case 'w': pbox_lline(va_arg(ap, char *), WARNING_STYLE); break;
        case 's': pbox_lline(va_arg(ap, char *), SUCCESS_STYLE); break;
        case 't': pbox_lline(va_arg(ap, char *), TEXT_STYLE); break;
        case 'L': vpboxf_list(LIST_STYLE, " - ", va_arg(ap, size_t), ap); break;
        default: return 0;
    }
    return 1;
}

void vpboxf(const char *format, va_list ap)
{
    while (pboxf_flags(format, ap)) {
        format++;
    }
}

void pboxf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    vpboxf(format, ap);
    va_end(ap);
}
