#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (A->matrix == NULL || A->columns <= 0 || A->rows <= 0) {
    flag = INCORRECT_MATRIX;
    return flag;
  }
  if (B->matrix == NULL || B->columns <= 0 || B->rows <= 0) {
    flag = INCORRECT_MATRIX;
    return flag;
  }
  if (A->columns == B->columns && A->rows == B->rows) {
    flag = s21_create_matrix(A->rows, A->columns, result);
    if (flag == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  } else {
    flag = CALCULATION_ERROR;
  }
  return flag;
}