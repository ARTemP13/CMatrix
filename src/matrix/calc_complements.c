#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (A->matrix == NULL || A->columns <= 0 || A->rows <= 0) {
    flag = INCORRECT_MATRIX;
    return flag;
  }
  if (A->rows == A->columns) {
    flag = s21_create_matrix(A->rows, A->columns, result);

    if (flag == 0) {
      if (A->rows == 1) {
        result->matrix[0][0] = A->matrix[0][0];
      } else {
        double k = -1;
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            matrix_t mat = {0};
            s21_create_matrix(A->rows, A->rows, &mat);
            double det = 0;
            s21_new_matrix(&mat, A, A->rows, i, j);
            mat.columns -= 1;
            mat.rows -= 1;
            s21_determinant(&mat, &det);
            k = pow(-1, i + j);
            result->matrix[i][j] = k * det;
            mat.columns += 1;
            mat.rows += 1;
            s21_remove_matrix(&mat);
          }
        }
      }
    }
  } else {
    flag = CALCULATION_ERROR;
  }
  return flag;
}