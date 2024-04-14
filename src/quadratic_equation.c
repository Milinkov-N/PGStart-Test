#include "quadratic_equation.h"

#include <math.h>
#include <stddef.h>

#define QE_EPS 0.0000001f

static int iszerof(double x) { return fabs(x) < QE_EPS; }

static double discriminant(double a, double b, double c) {
    return pow(b, 2) - 4 * a * c;
}

int solve_equation(double a, double b, double c, solution_t* result) {
    double d = 0.0f;
    if (iszerof(a) || result == NULL) return QE_ERROR;
    if ((d = discriminant(a, b, c)) < 0.0f) return QE_NO_SOLUTION;
    result->x1 = (-b + sqrt(d)) / (2 * a);
    result->x2 = (-b - sqrt(d)) / (2 * a);
    return QE_OK;
}
