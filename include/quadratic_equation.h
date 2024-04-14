/**
 * @file quadratic_equation.h
 * @author Milinkov Nikita (milinkov.nik@gmail.com)
 * @version 0.1.0
 * @date 2024-04-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef QUADRATIC_EQUATION_H_
#define QUADRATIC_EQUATION_H_

/** @brief Status code that `solve_equation()` function returns when
 * discriminant is less than zero.
 */
#define QE_NO_SOLUTION -1

/** @brief Status code that `solve_equation()` function returns when `a` param
 * is equal to zero or pointer to `solution` struct is invalid (null).
 */
#define QE_ERROR 0

/** @brief Status code that `solve_equation()` function returns when calculation
 * is successful.
 */
#define QE_OK 1

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Result structure of `solve_equation()` function. Contains roots
 * (`x1`, `x2`) of the quadratic equation solution.
 */
typedef struct solution {
    /** @brief First possible root. */
    double x1;

    /** @brief Second possible root. */
    double x2;
} solution_t;

/**
 * @brief Calculates quadratic equation `ax^2 + bx + c = 0`
 * @example basic_example.c
 * @param[in] a first coefficient, should not be equal zero
 * @param[in] b second coefficient
 * @param[in] c free member
 * @param[out] result pointer to solution struct for calculated roots
 * @return `QE_OK`, `QE_ERROR`, `QE_NO_SOLUTION`
 */
int solve_equation(double a, double b, double c, solution_t* result);

#ifdef __cplusplus
}
#endif

#endif  // QUADRATIC_EQUATION_H_
