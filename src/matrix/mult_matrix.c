#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (A->matrix == NULL || A->columns <= 0 || A->rows <= 0) {
    flag = INCORRECT_MATRIX;
    return flag;
  }
  if (B->matrix == NULL || B->columns <= 0 || B->rows <= 0) {
    flag = INCORRECT_MATRIX;
    return flag;
  }
  if (A->columns == B->rows && A->rows == B->columns) {
    flag = s21_create_matrix(A->rows, B->columns, result);
    if (flag == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          int counter = 0;
          double sum = 0;
          while (counter < A->columns) {
            sum += A->matrix[i][counter] * B->matrix[counter][j];
            counter++;
          }
          result->matrix[i][j] = sum;
        }
      }
    }

  } else {
    flag = CALCULATION_ERROR;
  }
  return flag;
}