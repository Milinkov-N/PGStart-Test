#include <gtest/gtest.h>

#include "quadratic_equation.h"

TEST(SolveQuadraticEquation,
     GivenAEqualOneAndBEqualZeroAndCEqualThree_ReturnsNoSolution) {
    double a = 1.0f, b = 0.0f, c = 3.0f;
    int expected = QE_NO_SOLUTION;
    double expected_x = 0.0f;

    solution_t sln{};
    int result = solve_equation(a, b, c, &sln);

    EXPECT_EQ(expected, result);
    EXPECT_DOUBLE_EQ(expected_x, sln.x1);
    EXPECT_DOUBLE_EQ(expected_x, sln.x2);
}

TEST(SolveQuadraticEquation,
     GivenAEqualFiveAndBEqualZeroAndCIsNegative_ReturnsValidX1AndX2) {
    double a = 5.0f, b = 0.0f, c = -125.0f;
    int expected = QE_OK;
    double expected_x1 = 5.0f, expected_x2 = -5.0f;

    solution_t sln{};
    int result = solve_equation(a, b, c, &sln);

    EXPECT_EQ(expected, result);
    EXPECT_DOUBLE_EQ(expected_x1, sln.x1);
    EXPECT_DOUBLE_EQ(expected_x2, sln.x2);
}

TEST(SolveQuadraticEquation, GivenAEqualZero_ReturnsError) {
    double a = 0.0f, b = 0.0f, c = -125.0f;
    int expected = QE_ERROR;
    double expected_x1 = 0.0f, expected_x2 = 0.0f;

    solution_t sln{};
    int result = solve_equation(a, b, c, &sln);

    EXPECT_EQ(expected, result);
    EXPECT_DOUBLE_EQ(expected_x1, sln.x1);
    EXPECT_DOUBLE_EQ(expected_x2, sln.x2);
}

TEST(SolveQuadraticEquation, GivenOutParamNull_ReturnsError) {
    double a = 1.0f, b = 0.0f, c = -125.0f;
    int expected = QE_ERROR;
    double expected_x1 = 0.0f, expected_x2 = 0.0f;

    solution_t sln{};
    int result = solve_equation(a, b, c, NULL);

    EXPECT_EQ(expected, result);
    EXPECT_DOUBLE_EQ(expected_x1, sln.x1);
    EXPECT_DOUBLE_EQ(expected_x2, sln.x2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
