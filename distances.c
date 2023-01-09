// Implementation of various distance functions.
#include <stdlib.h>
#include <math.h>
#include "distances.h"

matrix* euclidean(matrix* m, vector* x) {
    matrix* tmp = sub_rows(m, x);
    tmp = power(tmp, 2);
    tmp = sum_rows(tmp);
    tmp = apply(tmp, sqrt);
    return tmp;
}

matrix* manhattan(matrix* m, vector* x) {
    matrix* tmp = sub_rows(m, x);
    tmp = abs_mat(tmp);
    tmp = sum_rows(tmp);
    return tmp;
}