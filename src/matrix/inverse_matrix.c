#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (A->matrix == NULL || A->columns <= 0 || A->rows <= 0) {
    flag = INCORRECT_MATRIX;
    return flag;
  }
  if (A->columns == A->rows) {
    double det = 0;
    s21_determinant(A, &det);
    if (det != 0) {
      matrix_t matrix1 = {0};
      if (A->columns != 1) {
        s21_calc_complements(A, &matrix1);
        s21_transpose(&matrix1, result);
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] *= (1.0 / det);
          }
        }
        s21_remove_matrix(&matrix1);
      } else {
        s21_create_matrix(1, 1, result);
        result->matrix[0][0] = 1.0 / det;
      }

    } else {
      flag = CALCULATION_ERROR;
    }
  } else {
    flag = CALCULATION_ERROR;
  }
  return flag;
}
