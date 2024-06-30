#include "../s21_matrix.h"

void s21_new_matrix(matrix_t *mat, matrix_t *A, int n, int ki, int kj) {
  int d1 = 0;
  int d2 = 0;
  for (int i = 0; i < n - 1; i++) {
    if (i == ki) d1 = 1;
    for (int j = 0; j < n - 1; j++) {
      if (j == kj) d2 = 1;
      mat->matrix[i][j] = A->matrix[i + d1][j + d2];
    }
    d2 = 0;
  }
}

double s21_det(matrix_t *A, int n) {
  double det = 0;
  if (n == 1)
    det = A->matrix[0][0];
  else if (n == 2)
    det = A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  else {
    matrix_t mat = {0};
    s21_create_matrix(n, n, &mat);
    double k = 1;
    int m = n - 1;
    for (int i = 0; i < n; i++) {
      s21_new_matrix(&mat, A, n, 0, i);
      det += k * A->matrix[0][i] * s21_det(&mat, m);
      k *= -1;
    }
    s21_remove_matrix(&mat);
  }
  return det;
}

int s21_determinant(matrix_t *A, double *result) {
  int flag = OK;
  if (A->matrix == NULL || A->columns <= 0 || A->rows <= 0) {
    flag = INCORRECT_MATRIX;
    return flag;
  }
  if (A->rows == A->columns) {
    *result = s21_det(A, A->rows);
  } else {
    flag = CALCULATION_ERROR;
  }
  return flag;
}