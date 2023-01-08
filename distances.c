// Implementation of various distance functions.
#include <stdlib.h>
#include <math.h>
#include "matrix_vector_ops.h"
#include "<./matrix/matrix_ops.h"

matrix* euclidean(matrix* m, vector* x) {
    matrix* tmp = sub_rows(m, x);
    tmp = power(tmp, 2);
    tmp = sum_rows(tmp);
    tmp = apply(tmp, sqrt);
    return tmp;
}

/*
double manhattan(double* x, double* y, size_t n) {
    double *z = calloc(n, sizeof(double));
    sub(x, y, z, n);
    abs_vec(z, n);
    double res = sum(z, n);
    free(z);
    return res;
}

double chess(double* x, double* y, size_t n) {
    double *z = calloc(n, sizeof(double));
    sub(x, y, z, n);
    abs(z, n);
    double res = max_vec(z, n);
    free(z);
    return res;
}*/