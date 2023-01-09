// Implementation of various distance functions.
#include <stdlib.h>
#include <math.h>
#include "distances.h"

vector* euclidean(matrix* m, vector* x) {
    matrix* tmp = sub_rows(m, x);
    tmp = power(tmp, 2);
    tmp = sum_rows(tmp);
    tmp = apply(tmp, sqrt);
    vector* vec = vector_from_matrix(tmp);
    free_matrix(tmp);
    return vec;
}

vector* manhattan(matrix* m, vector* x) {
    matrix* tmp = sub_rows(m, x);
    tmp = abs_mat(tmp);
    tmp = sum_rows(tmp);
    vector* vec = vector_from_matrix(tmp);
    free_matrix(tmp);
    return vec;
}