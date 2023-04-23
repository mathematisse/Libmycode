/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for type allocation
*/

#include <criterion/criterion.h>
#include "read.h"

Test(read_tests, stoui_tests)
{
    cr_assert_eq(stoui("123"), 123, "stoui(\"123\") != 123, stoui(\"123\") = %d", stoui("123"));
    cr_assert_eq(stoui("0"), 0, "stoui(\"0\") != 0, stoui(\"0\") = %d", stoui("0"));
    cr_assert_eq(stoui("98765"), 98765, "stoui(\"98765\") != 98765, stoui(\"98765\") = %d", stoui("98765"));
    cr_assert_eq(stoui("-1"), 0, "stoui(\"-1\") != 0, stoui(\"-1\") = %d", stoui("-1"));
    cr_assert_eq(stoui("a"), 0, "stoui(\"a\") != 0, stoui(\"a\") = %d", stoui("a"));
}

Test(read_tests, stoi_tests)
{
    cr_assert_eq(stoi("123"), 123, "stoi(\"123\") != 123, stoi(\"123\") = %d", stoi("123"));
    cr_assert_eq(stoi("0"), 0, "stoi(\"0\") != 0, stoi(\"0\") = %d", stoi("0"));
    cr_assert_eq(stoi("98765"), 98765, "stoi(\"98765\") != 98765, stoi(\"98765\") = %d", stoi("98765"));
    cr_assert_eq(stoi("-1"), -1, "stoi(\"-1\") != -1, stoi(\"-1\") = %d", stoi("-1"));
    cr_assert_eq(stoi("a"), 0, "stoi(\"a\") != 0, stoi(\"a\") = %d", stoi("a"));
}

Test(read_tests, stof_tests)
{
    cr_assert_eq(stof("-1.23"), -1.23f, "expected %f, got %f, the delta is %f", -1.23, stof("-1.23"), -1.23 - stof("-1.23"));
    cr_assert_eq(stof("0"), 0.0f, "stof(\"0\") != 0, stof(\"0\") = %f", stof("0"));
    cr_assert_eq(stof("98.765"), 98.765f, "stof(\"98765\") != 98.765, stof(\"98765\") = %f", stof("98765"));
    cr_assert_eq(stof("-1"), -1.0f, "stof(\"-1\") != -1, stof(\"-1\") = %f", stof("-1"));
    cr_assert_eq(stof("a"), 0.0f, "stof(\"a\") != 0, stof(\"a\") = %f", stof("a"));
}

Test(read_tests, stod_tests)
{
    cr_assert_eq(stod("-1.23"), -1.23, "stod(\"-1.23\") != -1.23, stod(\"-1.23\") = %f", stod("-1.23"));
    cr_assert_eq(stod("0"), 0.0, "stod(\"0\") != 0, stod(\"0\") = %f", stod("0"));
    cr_assert_eq(stod("98.765"), 98.765, "stod(\"98765\") != 98.765, stod(\"98765\") = %f", stod("98765"));
    cr_assert_eq(stod("-1"), -1.0, "stod(\"-1\") != -1, stod(\"-1\") = %f", stod("-1"));
    cr_assert_eq(stod("a"), 0.0, "stod(\"a\") != 0, stod(\"a\") = %f", stod("a"));
    cr_assert_eq(stod("0.05"), 0.05, "stod(\"0.05\") != 0.05, stod(\"0.05\") = %f", stod("0.05"));
}
