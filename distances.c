// Implementation of various distance functions.
#include <stdlib.h>
#include "./matrix/vector_ops.h"
#include "./matrix/matrix_ops.h"

/*double euclidean(double* x, double* y, size_t n) {
    double* z = calloc(n, sizeof(double));
    sub(x, y, z, n);
    power(z, 2, n);
    double res = sum(z, n);
    free(z);
    return res;
}

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