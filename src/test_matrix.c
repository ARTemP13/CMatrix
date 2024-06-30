#include <check.h>

#include "s21_matrix.h"

START_TEST(test_create1) {
  matrix_t matrix = {0};
  int flag = s21_create_matrix(3, 3, &matrix);
  ck_assert_int_eq(flag, OK);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create2) {
  matrix_t matrix = {0};
  int flag = s21_create_matrix(100, 100, &matrix);
  ck_assert_int_eq(flag, OK);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create3) {
  matrix_t matrix = {0};
  int flag = s21_create_matrix(0, 0, &matrix);
  ck_assert_int_eq(flag, INCORRECT_MATRIX);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create4) {
  matrix_t matrix = {0};
  int flag = s21_create_matrix(-5, 3, &matrix);
  ck_assert_int_eq(flag, INCORRECT_MATRIX);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create5) {
  matrix_t matrix = {0};
  int flag = s21_create_matrix(0, 3, &matrix);
  ck_assert_int_eq(flag, INCORRECT_MATRIX);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_remove1) {
  matrix_t matrix = {0};
  s21_create_matrix(3, 3, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_int_eq(matrix.columns, 0);
  ck_assert_int_eq(matrix.rows, 0);
}
END_TEST

START_TEST(test_remove2) {
  matrix_t matrix = {0};
  s21_create_matrix(100, 99, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_int_eq(matrix.columns, 0);
  ck_assert_int_eq(matrix.rows, 0);
}
END_TEST

//
// Comparison
//
START_TEST(test_comparison1) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(1, 1, &matrix2);
  matrix1.matrix[0][0] = 5;
  matrix2.matrix[0][0] = 5;
  int flag = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(flag, SUCCESS);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_comparison2) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;
  matrix1.matrix[0][2] = 7;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 3;
  matrix1.matrix[1][2] = 4;

  matrix1.matrix[2][0] = 5;
  matrix1.matrix[2][1] = -2;
  matrix1.matrix[2][2] = -3;

  matrix2.matrix[0][0] = 2;
  matrix2.matrix[0][1] = 5;
  matrix2.matrix[0][2] = 7;

  matrix2.matrix[1][0] = 6;
  matrix2.matrix[1][1] = 3;
  matrix2.matrix[1][2] = 4;

  matrix2.matrix[2][0] = 5;
  matrix2.matrix[2][1] = -2;
  matrix2.matrix[2][2] = -3;
  int flag = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(flag, SUCCESS);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_comparison3) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(1, 1, &matrix2);
  matrix1.matrix[0][0] = 5;
  matrix1.matrix[0][0] = 8;
  int flag = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(flag, FAILURE);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_comparison4) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 5;

  matrix2.matrix[0][0] = 2;
  matrix2.matrix[0][1] = 5;

  matrix2.matrix[1][0] = 6;
  matrix2.matrix[1][1] = 5;
  int flag = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(flag, SUCCESS);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_comparison5) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 5;

  matrix2.matrix[0][0] = 2;
  matrix2.matrix[0][1] = 5;

  matrix2.matrix[1][0] = 6;
  matrix2.matrix[1][1] = 8;
  int flag = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(flag, FAILURE);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_comparison6) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(1, 1, &matrix2);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 5;

  matrix2.matrix[0][0] = 2;
  int flag = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(flag, FAILURE);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

//
// Sum
//
START_TEST(test_sum1) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  matrix_t res = {0};
  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(1, 1, &matrix2);
  matrix1.matrix[0][0] = 2;
  matrix2.matrix[0][0] = 5;
  s21_sum_matrix(&matrix1, &matrix2, &res);
  ck_assert_double_eq(res.matrix[0][0], 7);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sum2) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 5;

  matrix2.matrix[0][0] = 0;
  matrix2.matrix[0][1] = 8;

  matrix2.matrix[1][0] = 9;
  matrix2.matrix[1][1] = 1.5;
  s21_sum_matrix(&matrix1, &matrix2, &res);
  ck_assert_double_eq(res.matrix[0][0], 2);
  ck_assert_double_eq(res.matrix[0][1], 13);
  ck_assert_double_eq(res.matrix[1][0], 15);
  ck_assert_double_eq(res.matrix[1][1], 6.5);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sum3) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;
  matrix1.matrix[0][2] = 7;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 3;
  matrix1.matrix[1][2] = 4;

  matrix1.matrix[2][0] = 5;
  matrix1.matrix[2][1] = -2;
  matrix1.matrix[2][2] = -3;

  matrix2.matrix[0][0] = 6;
  matrix2.matrix[0][1] = 2.54;
  matrix2.matrix[0][2] = 1;

  matrix2.matrix[1][0] = -5;
  matrix2.matrix[1][1] = 7;
  matrix2.matrix[1][2] = 9;

  matrix2.matrix[2][0] = 4;
  matrix2.matrix[2][1] = 9;
  matrix2.matrix[2][2] = 9;
  s21_sum_matrix(&matrix1, &matrix2, &res);
  ck_assert_double_eq(res.matrix[0][0], 8);
  ck_assert_double_eq(res.matrix[0][1], 7.54);
  ck_assert_double_eq(res.matrix[0][2], 8);
  ck_assert_double_eq(res.matrix[1][0], 1);
  ck_assert_double_eq(res.matrix[1][1], 10);
  ck_assert_double_eq(res.matrix[1][2], 13);
  ck_assert_double_eq(res.matrix[2][0], 9);
  ck_assert_double_eq(res.matrix[2][1], 7);
  ck_assert_double_eq(res.matrix[2][2], 6);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sum4) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  matrix_t res = {0};
  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  matrix1.matrix[0][0] = 2;
  matrix2.matrix[0][1] = 5;
  int flag = s21_sum_matrix(&matrix1, &matrix2, &res);
  ck_assert_int_eq(flag, CALCULATION_ERROR);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sum5) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  matrix_t res = {0};
  s21_create_matrix(1, 1, &matrix1);
  matrix1.matrix[0][0] = 2;
  int flag = s21_sum_matrix(&matrix1, &matrix2, &res);
  ck_assert_int_eq(flag, INCORRECT_MATRIX);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

//
// Sub
//

START_TEST(test_sub1) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  matrix_t res = {0};
  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(1, 1, &matrix2);
  matrix1.matrix[0][0] = 8;
  matrix2.matrix[0][0] = 5;
  s21_sub_matrix(&matrix1, &matrix2, &res);
  ck_assert_double_eq(res.matrix[0][0], 3);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sub2) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 5;

  matrix2.matrix[0][0] = 0;
  matrix2.matrix[0][1] = 8;

  matrix2.matrix[1][0] = 9;
  matrix2.matrix[1][1] = 1.5;
  s21_sub_matrix(&matrix1, &matrix2, &res);
  ck_assert_double_eq(res.matrix[0][0], 2);
  ck_assert_double_eq(res.matrix[0][1], -3);
  ck_assert_double_eq(res.matrix[1][0], -3);
  ck_assert_double_eq(res.matrix[1][1], 3.5);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sub3) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;
  matrix1.matrix[0][2] = 7;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 3;
  matrix1.matrix[1][2] = 4;

  matrix1.matrix[2][0] = 5;
  matrix1.matrix[2][1] = -2;
  matrix1.matrix[2][2] = -3;

  matrix2.matrix[0][0] = 6;
  matrix2.matrix[0][1] = 2.54;
  matrix2.matrix[0][2] = 1;

  matrix2.matrix[1][0] = -5;
  matrix2.matrix[1][1] = 7;
  matrix2.matrix[1][2] = 9;

  matrix2.matrix[2][0] = 4;
  matrix2.matrix[2][1] = 9;
  matrix2.matrix[2][2] = 9;
  s21_sub_matrix(&matrix1, &matrix2, &res);
  ck_assert_double_eq(res.matrix[0][0], -4);
  ck_assert_double_eq(res.matrix[0][1], 2.46);
  ck_assert_double_eq(res.matrix[0][2], 6);
  ck_assert_double_eq(res.matrix[1][0], 11);
  ck_assert_double_eq(res.matrix[1][1], -4);
  ck_assert_double_eq(res.matrix[1][2], -5);
  ck_assert_double_eq(res.matrix[2][0], 1);
  ck_assert_double_eq(res.matrix[2][1], -11);
  ck_assert_double_eq(res.matrix[2][2], -12);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sub4) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  matrix_t res = {0};
  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  matrix1.matrix[0][0] = 2;
  matrix2.matrix[0][1] = 5;
  int flag = s21_sub_matrix(&matrix1, &matrix2, &res);
  ck_assert_int_eq(flag, CALCULATION_ERROR);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sub5) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  matrix_t res = {0};
  s21_create_matrix(1, 1, &matrix1);
  matrix1.matrix[0][0] = 2;
  int flag = s21_sub_matrix(&matrix1, &matrix2, &res);
  ck_assert_int_eq(flag, INCORRECT_MATRIX);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

//
// mult_number
//

START_TEST(test_mult_number1) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  s21_create_matrix(1, 1, &matrix1);
  matrix1.matrix[0][0] = 8;
  double d = 5;
  s21_mult_number(&matrix1, d, &res);
  ck_assert_double_eq(res.matrix[0][0], 40);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult_number2) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &matrix1);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 5;

  int d = 2;
  s21_mult_number(&matrix1, d, &res);
  ck_assert_double_eq(res.matrix[0][0], 4);
  ck_assert_double_eq(res.matrix[0][1], 10);
  ck_assert_double_eq(res.matrix[1][0], 12);
  ck_assert_double_eq(res.matrix[1][1], 10);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult_number3) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &matrix1);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;
  matrix1.matrix[0][2] = 7;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 3;
  matrix1.matrix[1][2] = 4;

  matrix1.matrix[2][0] = 5;
  matrix1.matrix[2][1] = -2;
  matrix1.matrix[2][2] = -3;

  int d = 10;
  s21_mult_number(&matrix1, d, &res);
  ck_assert_double_eq(res.matrix[0][0], 20);
  ck_assert_double_eq(res.matrix[0][1], 50);
  ck_assert_double_eq(res.matrix[0][2], 70);
  ck_assert_double_eq(res.matrix[1][0], 60);
  ck_assert_double_eq(res.matrix[1][1], 30);
  ck_assert_double_eq(res.matrix[1][2], 40);
  ck_assert_double_eq(res.matrix[2][0], 50);
  ck_assert_double_eq(res.matrix[2][1], -20);
  ck_assert_double_eq(res.matrix[2][2], -30);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult_number4) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  s21_create_matrix(1, 1, &matrix1);
  matrix1.matrix[0][0] = 5.2345;
  int d = 10000;
  s21_mult_number(&matrix1, d, &res);
  ck_assert_int_eq(res.matrix[0][0], 52345);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult_number5) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  int d = 0;
  int flag = s21_mult_number(&matrix1, d, &res);
  ck_assert_int_eq(flag, INCORRECT_MATRIX);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

//
// mult_matrix
//

START_TEST(test_mult1) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  matrix_t res = {0};
  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(1, 1, &matrix2);
  matrix1.matrix[0][0] = 8;
  matrix2.matrix[0][0] = 5;
  s21_mult_matrix(&matrix1, &matrix2, &res);
  ck_assert_double_eq(res.matrix[0][0], 40);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult2) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 5;

  matrix2.matrix[0][0] = 0;
  matrix2.matrix[0][1] = 8;

  matrix2.matrix[1][0] = 9;
  matrix2.matrix[1][1] = 1.5;
  s21_mult_matrix(&matrix1, &matrix2, &res);
  ck_assert_double_eq(res.matrix[0][0], 45);
  ck_assert_double_eq(res.matrix[0][1], 23.5);
  ck_assert_double_eq(res.matrix[1][0], 45);
  ck_assert_double_eq(res.matrix[1][1], 55.5);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult3) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;
  matrix1.matrix[0][2] = 7;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 3;
  matrix1.matrix[1][2] = 4;

  matrix1.matrix[2][0] = 5;
  matrix1.matrix[2][1] = -2;
  matrix1.matrix[2][2] = -3;

  matrix2.matrix[0][0] = 6;
  matrix2.matrix[0][1] = 2.5;
  matrix2.matrix[0][2] = 1;

  matrix2.matrix[1][0] = -5;
  matrix2.matrix[1][1] = 7;
  matrix2.matrix[1][2] = 9;

  matrix2.matrix[2][0] = 4;
  matrix2.matrix[2][1] = 9;
  matrix2.matrix[2][2] = 9;
  s21_mult_matrix(&matrix1, &matrix2, &res);
  ck_assert_double_eq(res.matrix[0][0], 15);
  ck_assert_double_eq(res.matrix[0][1], 103);
  ck_assert_double_eq(res.matrix[0][2], 110);
  ck_assert_double_eq(res.matrix[1][0], 37);
  ck_assert_double_eq(res.matrix[1][1], 72);
  ck_assert_double_eq(res.matrix[1][2], 69);
  ck_assert_double_eq(res.matrix[2][0], 28);
  ck_assert_double_eq(res.matrix[2][1], -28.5);
  ck_assert_double_eq(res.matrix[2][2], -40);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult4) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  matrix_t res = {0};
  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  matrix1.matrix[0][0] = 2;
  matrix2.matrix[0][1] = 5;
  int flag = s21_mult_matrix(&matrix1, &matrix2, &res);
  ck_assert_int_eq(flag, CALCULATION_ERROR);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult5) {
  matrix_t matrix1 = {0};
  matrix_t matrix2 = {0};
  matrix_t res = {0};
  s21_create_matrix(1, 1, &matrix1);
  matrix1.matrix[0][0] = 2;
  int flag = s21_mult_matrix(&matrix1, &matrix2, &res);
  ck_assert_int_eq(flag, INCORRECT_MATRIX);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

//
// Transpose
//

START_TEST(test_transpose1) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  s21_create_matrix(1, 1, &matrix1);
  matrix1.matrix[0][0] = 8;
  s21_transpose(&matrix1, &res);
  ck_assert_double_eq(res.matrix[0][0], 8);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_transpose2) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  s21_create_matrix(1, 2, &matrix1);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;
  s21_transpose(&matrix1, &res);
  ck_assert_double_eq(res.matrix[0][0], 2);
  ck_assert_double_eq(res.matrix[1][0], 5);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_transpose3) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 3, &matrix1);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;
  matrix1.matrix[0][2] = 7;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 3;
  matrix1.matrix[1][2] = 4;
  s21_transpose(&matrix1, &res);
  ck_assert_double_eq(res.matrix[0][0], 2);
  ck_assert_double_eq(res.matrix[0][1], 6);
  ck_assert_double_eq(res.matrix[1][0], 5);
  ck_assert_double_eq(res.matrix[1][1], 3);
  ck_assert_double_eq(res.matrix[2][0], 7);
  ck_assert_double_eq(res.matrix[2][1], 4);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_transpose6) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &matrix1);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;
  matrix1.matrix[0][2] = 7;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 3;
  matrix1.matrix[1][2] = 4;

  matrix1.matrix[2][0] = -5;
  matrix1.matrix[2][1] = 34;
  matrix1.matrix[2][2] = 4.5;
  s21_transpose(&matrix1, &res);
  ck_assert_double_eq(res.matrix[0][0], 2);
  ck_assert_double_eq(res.matrix[0][1], 6);
  ck_assert_double_eq(res.matrix[0][2], -5);
  ck_assert_double_eq(res.matrix[1][0], 5);
  ck_assert_double_eq(res.matrix[1][1], 3);
  ck_assert_double_eq(res.matrix[1][2], 34);
  ck_assert_double_eq(res.matrix[2][0], 7);
  ck_assert_double_eq(res.matrix[2][1], 4);
  ck_assert_double_eq(res.matrix[2][2], 4.5);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_transpose4) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  int flag = s21_transpose(&matrix1, &res);
  ck_assert_int_eq(flag, INCORRECT_MATRIX);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_transpose5) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 1, &matrix1);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[1][0] = 5;
  matrix1.matrix[2][0] = 7;
  s21_transpose(&matrix1, &res);
  ck_assert_double_eq(res.matrix[0][0], 2);
  ck_assert_double_eq(res.matrix[0][1], 5);
  ck_assert_double_eq(res.matrix[0][2], 7);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

//
// determinant
//
START_TEST(test_determinant1) {
  matrix_t matrix1 = {0};
  s21_create_matrix(1, 1, &matrix1);
  matrix1.matrix[0][0] = 8;
  double res = 0;
  s21_determinant(&matrix1, &res);
  ck_assert_double_eq(res, 8);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(test_determinant2) {
  matrix_t matrix1 = {0};
  s21_create_matrix(2, 2, &matrix1);
  matrix1.matrix[0][0] = 4;
  matrix1.matrix[0][1] = 7;
  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 3;
  double res = 0;
  s21_determinant(&matrix1, &res);
  ck_assert_double_eq(res, -30);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(test_determinant3) {
  matrix_t matrix1 = {0};
  s21_create_matrix(3, 3, &matrix1);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 3;
  matrix1.matrix[0][2] = -4;

  matrix1.matrix[1][0] = 1;
  matrix1.matrix[1][1] = 2;
  matrix1.matrix[1][2] = 0;

  matrix1.matrix[2][0] = 3;
  matrix1.matrix[2][1] = 4;
  matrix1.matrix[2][2] = 1;
  double res = 0;
  s21_determinant(&matrix1, &res);
  ck_assert_double_eq(res, 9.0);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(test_determinant6) {
  matrix_t matrix1 = {0};
  s21_create_matrix(4, 4, &matrix1);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;
  matrix1.matrix[0][2] = 1;
  matrix1.matrix[0][3] = 3;

  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 1;
  matrix1.matrix[1][2] = 7;
  matrix1.matrix[1][3] = 9;

  matrix1.matrix[2][0] = 6;
  matrix1.matrix[2][1] = 8;
  matrix1.matrix[2][2] = 3;
  matrix1.matrix[2][3] = 2;

  matrix1.matrix[3][0] = 7;
  matrix1.matrix[3][1] = 8;
  matrix1.matrix[3][2] = 1;
  matrix1.matrix[3][3] = 4;
  double res = 0;
  s21_determinant(&matrix1, &res);
  ck_assert_double_eq(res, 630);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(test_determinant4) {
  matrix_t matrix1 = {0};
  double res = 0;
  int flag = s21_determinant(&matrix1, &res);
  ck_assert_int_eq(flag, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_determinant5) {
  matrix_t matrix1 = {0};
  s21_create_matrix(3, 1, &matrix1);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[1][0] = 5;
  matrix1.matrix[2][0] = 7;
  double res = 0;
  int flag = s21_determinant(&matrix1, &res);
  ck_assert_double_eq(flag, CALCULATION_ERROR);
  s21_remove_matrix(&matrix1);
}
END_TEST

//
// inverse_matrix
//

START_TEST(test_inverse_matrix1) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  s21_create_matrix(1, 1, &matrix1);
  matrix1.matrix[0][0] = 8;
  s21_inverse_matrix(&matrix1, &res);
  ck_assert_double_eq(res.matrix[0][0], 0.125);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_inverse_matrix2) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &matrix1);
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[1][0] = 3;
  matrix1.matrix[1][1] = 4;
  s21_inverse_matrix(&matrix1, &res);
  ck_assert_double_eq(res.matrix[0][0], -2);
  ck_assert_double_eq(res.matrix[0][1], 1);
  ck_assert_double_eq(res.matrix[1][0], 1.5);
  ck_assert_double_eq(res.matrix[1][1], -0.5);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_inverse_matrix3) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &matrix1);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;
  matrix1.matrix[0][2] = 7;

  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 3;
  matrix1.matrix[1][2] = 4;

  matrix1.matrix[2][0] = 5;
  matrix1.matrix[2][1] = -2;
  matrix1.matrix[2][2] = -3;
  s21_inverse_matrix(&matrix1, &res);
  ck_assert_double_eq(res.matrix[0][0], 1);
  ck_assert_double_eq(res.matrix[0][1], -1);
  ck_assert_double_eq(res.matrix[0][2], 1);
  ck_assert_double_eq(res.matrix[1][0], -38);
  ck_assert_double_eq(res.matrix[1][1], 41);
  ck_assert_double_eq(res.matrix[1][2], -34);
  ck_assert_double_eq(res.matrix[2][0], 27);
  ck_assert_double_eq(res.matrix[2][1], -29);
  ck_assert_double_eq(res.matrix[2][2], 24);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_inverse_matrix6) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  s21_create_matrix(4, 4, &matrix1);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 1;
  matrix1.matrix[0][2] = 0;
  matrix1.matrix[0][3] = 0;

  matrix1.matrix[1][0] = 3;
  matrix1.matrix[1][1] = 2;
  matrix1.matrix[1][2] = 0;
  matrix1.matrix[1][3] = 0;

  matrix1.matrix[2][0] = 1;
  matrix1.matrix[2][1] = 1;
  matrix1.matrix[2][2] = 3;
  matrix1.matrix[2][3] = 4;

  matrix1.matrix[3][0] = 2;
  matrix1.matrix[3][1] = -1;
  matrix1.matrix[3][2] = 2;
  matrix1.matrix[3][3] = 3;
  s21_inverse_matrix(&matrix1, &res);
  ck_assert_int_eq(res.matrix[0][0], 2);
  ck_assert_int_eq(res.matrix[0][1], -1);
  ck_assert_int_eq(res.matrix[0][2], 0);
  ck_assert_int_eq(res.matrix[0][3], 0);
  ck_assert_int_eq(res.matrix[1][0], -3);
  ck_assert_int_eq(res.matrix[1][1], 2);
  ck_assert_int_eq(res.matrix[1][2], 0);
  ck_assert_int_eq(res.matrix[1][3], 0);

  ck_assert_int_eq(res.matrix[2][0], 31);
  ck_assert_int_eq(res.matrix[2][1], -19);
  ck_assert_int_eq(res.matrix[2][2], 3);
  ck_assert_int_eq(res.matrix[2][3], -4);
  ck_assert_int_eq(res.matrix[3][0], -23);
  ck_assert_int_eq(res.matrix[3][1], 14);
  ck_assert_int_eq(res.matrix[3][2], -2);
  ck_assert_int_eq(res.matrix[3][3], 3);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_inverse_matrix4) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  int flag = s21_inverse_matrix(&matrix1, &res);
  ck_assert_int_eq(flag, INCORRECT_MATRIX);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_inverse_matrix5) {
  matrix_t matrix1 = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &matrix1);
  matrix1.matrix[0][0] = 3;
  matrix1.matrix[0][1] = 1;
  matrix1.matrix[1][0] = 3;
  matrix1.matrix[1][1] = 1;
  int flag = s21_inverse_matrix(&matrix1, &res);
  ck_assert_double_eq(flag, CALCULATION_ERROR);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

//
// calc
//

START_TEST(test_calc_complements_1) {
  int check_error = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  A.matrix[1][2] = 2.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 2.0;
  A.matrix[2][2] = 1.0;

  s21_calc_complements(&A, &Z);

  s21_create_matrix(3, 3, &X);

  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 10.0;
  X.matrix[0][2] = -20.0;
  X.matrix[1][0] = 4.0;
  X.matrix[1][1] = -14.0;
  X.matrix[1][2] = 8.0;
  X.matrix[2][0] = -8.0;
  X.matrix[2][1] = -2.0;
  X.matrix[2][2] = 4.0;

  check_error = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(check_error, SUCCESS);
}
END_TEST

START_TEST(test_calc_complements_2) {
  int check_error = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 112.0;
  A.matrix[0][1] = 243.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = -8.0;
  A.matrix[1][0] = 47.0;
  A.matrix[1][1] = 51.0;
  A.matrix[1][2] = -66.0;
  A.matrix[1][3] = 99.0;
  A.matrix[2][0] = -74.0;
  A.matrix[2][1] = 85.0;
  A.matrix[2][2] = 97.0;
  A.matrix[2][3] = 63.0;
  A.matrix[3][0] = -13.0;
  A.matrix[3][1] = 79.0;
  A.matrix[3][2] = -99.0;
  A.matrix[3][3] = -121.0;

  s21_calc_complements(&A, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = -2879514.0;
  X.matrix[0][1] = -1236631.0;
  X.matrix[0][2] = -1685096.0;
  X.matrix[0][3] = 880697.0;
  X.matrix[1][0] = 1162090.0;
  X.matrix[1][1] = -714015.0;
  X.matrix[1][2] = 4046255.0;
  X.matrix[1][3] = -3901600.0;
  X.matrix[2][0] = 4362897.0;
  X.matrix[2][1] = -2049432.0;
  X.matrix[2][2] = -532912.0;
  X.matrix[2][3] = -1370781.0;
  X.matrix[3][0] = 3412773.0;
  X.matrix[3][1] = -1569493.0;
  X.matrix[3][2] = 3144517.0;
  X.matrix[3][3] = 1284666.0;

  check_error = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(check_error, SUCCESS);
}
END_TEST

START_TEST(test_calc_complements_3) {
  int check_error = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5.0;

  s21_calc_complements(&A, &Z);

  s21_create_matrix(1, 1, &X);

  X.matrix[0][0] = 5.0;

  check_error = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(check_error, SUCCESS);
}
END_TEST

START_TEST(test_calc_complements_4) {
  int check_error = 0;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(4, 4, &A);
  s21_remove_matrix(&A);

  check_error = s21_calc_complements(&A, &Z);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(check_error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_calc_complements_5) {
  int check_error = 0;
  matrix_t A;
  matrix_t Z = {0};

  A.matrix = NULL;

  check_error = s21_calc_complements(&A, &Z);

  s21_remove_matrix(&Z);

  ck_assert_int_eq(check_error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_calc_complements_6) {
  int check_error = 0;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(4, 4, &A);
  A.columns = 0;

  check_error = s21_calc_complements(&A, &Z);

  A.columns = 4;
  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(check_error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_calc_complements_7) {
  int check_error = 0;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(1, 1, &A);
  A.rows = -5;

  check_error = s21_calc_complements(&A, &Z);
  A.rows = 1;
  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(check_error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_calc_complements_8) {
  int check_error = 0;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(1, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;

  check_error = s21_calc_complements(&A, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(check_error, CALCULATION_ERROR);
}
END_TEST

Suite* my_tests_suite() {
  Suite* suite;
  TCase* tc_core;

  suite = suite_create("Matrix Tests");

  tc_core = tcase_create("TESTS");

  tcase_add_test(tc_core, test_create1);
  tcase_add_test(tc_core, test_create2);
  tcase_add_test(tc_core, test_create3);
  tcase_add_test(tc_core, test_create4);
  tcase_add_test(tc_core, test_create5);

  tcase_add_test(tc_core, test_remove1);
  tcase_add_test(tc_core, test_remove2);

  tcase_add_test(tc_core, test_comparison1);
  tcase_add_test(tc_core, test_comparison2);
  tcase_add_test(tc_core, test_comparison3);
  tcase_add_test(tc_core, test_comparison4);
  tcase_add_test(tc_core, test_comparison5);
  tcase_add_test(tc_core, test_comparison6);

  tcase_add_test(tc_core, test_sum1);
  tcase_add_test(tc_core, test_sum2);
  tcase_add_test(tc_core, test_sum3);
  tcase_add_test(tc_core, test_sum4);
  tcase_add_test(tc_core, test_sum5);

  tcase_add_test(tc_core, test_sub1);
  tcase_add_test(tc_core, test_sub2);
  tcase_add_test(tc_core, test_sub3);
  tcase_add_test(tc_core, test_sub4);
  tcase_add_test(tc_core, test_sub5);

  tcase_add_test(tc_core, test_mult_number1);
  tcase_add_test(tc_core, test_mult_number2);
  tcase_add_test(tc_core, test_mult_number3);
  tcase_add_test(tc_core, test_mult_number4);
  tcase_add_test(tc_core, test_mult_number5);

  tcase_add_test(tc_core, test_mult1);
  tcase_add_test(tc_core, test_mult2);
  tcase_add_test(tc_core, test_mult3);
  tcase_add_test(tc_core, test_mult4);
  tcase_add_test(tc_core, test_mult5);

  tcase_add_test(tc_core, test_transpose1);
  tcase_add_test(tc_core, test_transpose2);
  tcase_add_test(tc_core, test_transpose3);
  tcase_add_test(tc_core, test_transpose4);
  tcase_add_test(tc_core, test_transpose5);
  tcase_add_test(tc_core, test_transpose6);

  tcase_add_test(tc_core, test_determinant1);
  tcase_add_test(tc_core, test_determinant2);
  tcase_add_test(tc_core, test_determinant3);
  tcase_add_test(tc_core, test_determinant4);
  tcase_add_test(tc_core, test_determinant5);
  tcase_add_test(tc_core, test_determinant6);

  tcase_add_test(tc_core, test_inverse_matrix1);
  tcase_add_test(tc_core, test_inverse_matrix2);
  tcase_add_test(tc_core, test_inverse_matrix3);
  tcase_add_test(tc_core, test_inverse_matrix4);
  tcase_add_test(tc_core, test_inverse_matrix5);
  tcase_add_test(tc_core, test_inverse_matrix6);

  tcase_add_test(tc_core, test_calc_complements_1);
  tcase_add_test(tc_core, test_calc_complements_2);
  tcase_add_test(tc_core, test_calc_complements_3);
  tcase_add_test(tc_core, test_calc_complements_4);
  tcase_add_test(tc_core, test_calc_complements_5);
  tcase_add_test(tc_core, test_calc_complements_6);
  tcase_add_test(tc_core, test_calc_complements_7);
  tcase_add_test(tc_core, test_calc_complements_8);

  suite_add_tcase(suite, tc_core);

  return suite;
}
int main() {
  int number_failed = 0;
  Suite* suite;
  SRunner* srunner;

  suite = my_tests_suite();
  srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_NORMAL);
  number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
