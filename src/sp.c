/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for write
*/

#include <unistd.h>
#include "len.h"
#include "rules.h"

/// @brief Write a char to a string
/// @param trgt String to write to
/// @param c Char to write
/// @return Number of char written
size_t spchar(char *trgt, char c)
{
    if (!trgt) {
        return 1;
    }
    trgt[0] = c;
    trgt[1] = '\0';
    return 1;
}

/// @brief Write a string to a string
/// @param trgt String to write to
/// @param str String to write
/// @return Number of char written
size_t spstr(char *trgt, const char *str)
{
    size_t i = 0;

    if (!str) {
        return 0;
    }
    if (!trgt) {
        return slen(str);
    }
    while (str[i]) {
        trgt[i] = str[i];
        i++;
    }
    return i;
}

/// @brief Write an unsigned int to a string
/// @param trgt String to write to
/// @param nb Unsigned Int to write
/// @return Number of char written
size_t spuint(char *trgt, unsigned int nb)
{
    size_t len = 0;
    size_t i = 0;

    len = uilen(nb);
    if (!trgt) {
        return len;
    }
    len--;
    if (nb == 0) {
        trgt[0] = '0';
        return 1;
    }
    while (nb) {
        trgt[len] = nb % 10 + '0';
        nb /= 10;
        len--;
        i++;
    }
    return i;
}

/// @brief Write an int to a string
/// @param trgt String to write to
/// @param nb Int to write
/// @return Number of char written
size_t spint(char *trgt, int nb)
{
    if (!trgt) {
        return ilen(nb);
    }
    if (nb < 0) {
        trgt[0] = '-';
        return spuint(trgt + 1, -nb) + 1;
    }
    return spuint(trgt, nb);
}

/// @brief Write a "unsigned" float to a string
/// @param trgt String to write to
/// @param nb Float to write
/// @return Number of char written
size_t spufloat(char *trgt, float nb)
{
    size_t int_len = 0;
    size_t dec_len = 0;

    if (!trgt) {
        return uilen((unsigned int) nb) + DEC_DIG + 1;
    }
    int_len = spuint(trgt, (unsigned int) nb);
    trgt[int_len] = '.';
    nb = (nb - (int) nb) * MAX_DEC;
    if (nb - (int) nb > RND_LIM) {
        nb++;
    }
    dec_len = uilen((unsigned int) nb);
    while (dec_len++ < DEC_DIG) {
        trgt[int_len + 1] = '0';
        trgt++;
    }
    int_len += spuint(trgt + int_len + 1, (unsigned int) nb);
    return int_len + 1;
}

/// @brief Write a float to a string
/// @param trgt String to write to
/// @param nb float to write
/// @return Number of char written
size_t spfloat(char *trgt, float nb)
{
    if (!trgt) {
        return ilen((int) nb) + DEC_DIG + 1;
    }
    if (nb < 0) {
        trgt[0] = '-';
        return spufloat(trgt + 1, -nb) + 1;
    }
    return spufloat(trgt, nb);
}

/// @brief Write a null double to a string
/// @param trgt String to write to
/// @return Number of char written
size_t spzdouble(char *trgt)
{
    size_t i = 0;

    if (!trgt) {
        return DEC_DIG + 2;
    }
    trgt[0] = '0';
    trgt[1] = '.';
    for (; i < DEC_DIG; i++) {
        trgt[i + 2] = '0';
    }
    return DEC_DIG + 2;
}

/// @brief Write a "unsigned" double to a string
/// @param trgt String to write to
/// @param nb Double to write
/// @return Number of char written
size_t spudouble(char *trgt, double nb)
{
    size_t len = 0;
    //size_t int_len = 0;
    size_t dec_len = 0;

    if (!trgt) {
        return uilen((unsigned int) nb) + DEC_DIG + 1;
    }
    len = spuint(trgt, (unsigned int) nb);
    trgt[len] = '.';
    nb = (nb - (int) nb) * MAX_DEC;
    if (nb - (int) nb > RND_LIM) {
        nb++;
    }
    dec_len = uilen((unsigned int) nb);
    while (dec_len++ < DEC_DIG) {
        trgt[len + 1] = '0';
        trgt++;
    }
    len += spuint(trgt + len + 1, (unsigned int) nb);
    return len + 1;
}

/// @brief Write a double to a string
/// @param trgt String to write to
/// @param nb Double to write
/// @return Number of char written
size_t spdouble(char *trgt, double nb)
{
    if (!trgt) {
        return dlen(nb);
    }
    if (nb == 0) {
        return spzdouble(trgt);
    }
    if (nb < 0) {
        trgt[0] = '-';
        return spudouble(trgt + 1, -nb) + 1;
    }
    return spudouble(trgt, nb);
}
