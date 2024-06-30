#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (A->matrix == NULL || B->matrix == NULL || A->columns <= 0 ||
      A->rows <= 0 || B->columns <= 0 || B->rows <= 0) {
    flag = INCORRECT_MATRIX;
    return flag;
  }
  if (A->columns == B->columns && A->rows == B->rows) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) flag = FAILURE;
      }
    }
  } else {
    flag = FAILURE;
  }
  return flag;
}