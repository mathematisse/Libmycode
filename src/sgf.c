/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for Str Print Format function
*/

#include <stdlib.h>
#include "gf.h"
#include "str.h"

static void sgf_flags(void **trgt, const char *format, const char *data)
{
    size_t slen = 0;

    switch (*format) {
        case 'c': *trgt = sgf_char(data); break;
        case 'i': *trgt = sgf_int(data); break;
        case 'd': *trgt = sgf_double(data); break;
        case 's':
            while (data[slen] && data[slen] != *(format + 1)) {
                slen++;
            }
            *trgt = sdupn(data, slen);
            break;
        default: *trgt = NULL; break;
    }
}

static void sgf_loop(void **args, const char *format, const char *data)
{
    size_t fptr = 0;
    size_t dptr = 0;
    size_t aptr = 0;

    while (format[fptr]) {
        if (format[fptr] == '%') {
            fptr++;
            sgf_flags(args + aptr, format + fptr, data + dptr);
            fptr++;
            aptr++;
            data += dptr + sfindc(data + dptr, *(format + fptr));
            dptr = 0;
        } else {
            dptr++;
        }
        fptr++;
    }
    args[aptr] = NULL;
}

/// @brief Create an array of void * from a format string and a data string
/// @param format Format string
/// @param data Data string
/// @return Array of void * containing the data parsed from the data string
void **sgf(const char *format, const char *data)
{
    void **args = NULL;

    if (!format || !data) {
        return NULL;
    }
    args = malloc(sizeof(void *) * (scount(format, "%") + 1));
    if (!args) {
        return NULL;
    }
    sgf_loop(args, format, data);
    return args;
}
