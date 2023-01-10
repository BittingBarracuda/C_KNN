// Implementation of various distance functions.
#include <stdlib.h>
#include <math.h>
#include "distances.h"
#include "./matrix/matrix_ops.h"

vector* euclidean(matrix* m, vector* x) {
    matrix* tmp1 = sub_rows(m, x);
    power_inplace(tmp1, 2);
    matrix* tmp2 = sum_rows(tmp1);
    apply_inplace(tmp2, sqrt);
    vector* vec = vector_from_matrix(tmp2);
    free_matrix(tmp1); free_matrix(tmp2);
    return vec;
}

vector* manhattan(matrix* m, vector* x) {
    matrix* tmp1 = sub_rows(m, x);
    abs_mat_inplace(tmp1);
    matrix* tmp2 = sum_rows(tmp1);
    vector* vec = vector_from_matrix(tmp2);
    free_matrix(tmp1); free_matrix(tmp2);
    return vec;
}