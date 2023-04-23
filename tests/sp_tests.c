/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for string put functions
*/

#include <criterion/criterion.h>
#include "pf.h"
#include "str.h"

Test(sp_tests, spchar_tests)
{
    char *str = NULL;
    size_t len = 0;

    len = spchar(str, 'a');
    cr_assert_eq(len, 1, "spchar(NULL, 'a') != 1, got %zu", len);
    str = snew(len, ' ');
    (void) spchar(str, 'a');
    cr_assert_eq(str[0], 'a', "spchar(str, 'a')[0] != 'a'");
    free(str);
}

Test(sp_tests, spstr_tests)
{
    char *str = NULL;
    size_t len = 0;

    len = spstr(str, "Hello World!");
    cr_assert_eq(len, 12, "spstr(NULL, \"Hello World!\") != 12, got %zu", len);
    str = snew(len, ' ');
    (void) spstr(str, "Hello World!");
    cr_assert_str_eq(str, "Hello World!", "spstr(str, \"Hello World!\") != \"Hello World!\", got %s", str);
    free(str);
}

Test(sp_tests, spint_tests)
{
    char *str = NULL;
    size_t len = 0;

    len = spint(str, 42);
    cr_assert_eq(len, 2, "spint(NULL, 42) != 2, got %zu", len);
    str = snew(len, ' ');
    (void) spint(str, 42);
    cr_assert_str_eq(str, "42", "spint(str, 42) != \"42\", got \"%s\"", str);
    free(str);
}

Test(sp_tests, spfloat_tests)
{
    char *str = NULL;
    size_t len = 0;

    len = spfloat(str, 42.42000000f);
    cr_assert_eq(len, 7, "spfloat(NULL, 42.42) != 7, got %zu", len);
    str = snew(len, ' ');
    (void) spfloat(str, 42.4200000f);
    cr_assert_str_eq(str, "42.4200", "spfloat(str, 42.42) != \"42.4200\", got %s", str);
    free(str);
}

Test(sp_tests, spdouble_tests)
{
    char *str = NULL;
    size_t len = 0;

    len = spdouble(NULL, 42.42);
    cr_assert_eq(len, 7, "spdouble(NULL, 42.42) != 7, got %zu", len);
    str = snew(len, ' ');
    (void) spdouble(str, 42.42);
    cr_assert_str_eq(str, "42.4200", "spdouble(str, 42.42) != \"42.4200\", got %s", str);
    free(str);
    str = NULL;
    len = spdouble(NULL, -0.05);
    cr_assert_eq(len, 7, "spdouble(NULL, -0.05) != 6, got %zu", len);
    str = snew(len, ' ');
    (void) spdouble(str, -0.05);
    cr_assert_str_eq(str, "-0.0500", "spdouble(str, -0.05) != \"-0.0500\", got %s", str);
    free(str);
}