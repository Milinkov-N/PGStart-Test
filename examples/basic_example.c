#include <quadratic_equation.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("USAGE: %s  <number> <number> <number>\n", argv[0]);
        return 0;
    }

    solution_t sln = {0};
    double a = 0.0f, b = 0.0f, c = 0.0f;
    int result = 0;

    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);

    result = solve_equation(a, b, c, &sln);

    switch (result) {
        case QE_ERROR:
            printf("Error calculating equation '%lfx^2 + %lfx + %lf = 0'\n", a,
                   b, c);
            break;

        case QE_NO_SOLUTION:
            printf(
                "Equation '%.2lfx^2 + %.2lfx + %.2lf = 0' doesn't have any "
                "solution\n",
                a, b, c);
            break;

        case QE_OK:
            printf(
                "Solution to equation '%lfx^2 + %lfx + %lf = 0' is:\n"
                "x1: %lf\nx2: %lf\n",
                a, b, c, sln.x1, sln.x2);
            break;
        default:
            printf("Unkonwn error occured\n");
            break;
    }

    return 0;
}
