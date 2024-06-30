#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = OK;
  if (rows >= 1 && columns >= 1) {
    result->columns = columns;
    result->rows = rows;
    result->matrix = (double **)malloc(rows * sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows; i++) {
        (result->matrix)[i] = (double *)malloc(columns * sizeof(double));
      }
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = 0;
        }
      }
    } else {
      flag = INCORRECT_MATRIX;
    }
  } else {
    flag = INCORRECT_MATRIX;
  }
  return flag;
}