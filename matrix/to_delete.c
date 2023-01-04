// Implementation of various real vector operations
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "vectors.h"

double sum(double* x, size_t n) {
    double sum = 0;
    for(unsigned int i = 0; i < n; i++) {
        sum += *(x + i);
    }
    return sum;
}

double prod(double* x, size_t n) {
    double prod = 1;
    for(unsigned int i = 0; i < n; i++) {
        prod *= *(x + i);
    }
    return prod;
}

double max_vec(double* x, size_t n) {
    if(n > 0) {
        double max = *(x);
        for(unsigned int i = 1; i < n; i++) {
            if(*(x + i) > max) max = *(x + i);
        }
        return max;
    } else {
        return DBL_MIN;
    }
}

unsigned int max_vec(double* x, size_t n) {
    if(n > 0) {
        double max = *(x), max_ind = 0;
        for(unsigned int i = 1; i < n; i++) {
            if(*(x + i) > max) { 
                max = *(x + i);
                max_ind = i;
            }
        }
        return max_ind;
    } else {
        return -1;
    }
}

double min_vec(double* x, size_t n) {
    if(n > 0) {
        double min = *(x);
        for(unsigned int i = 0; i < n; i++) {
            if(*(x + i) < min) min = *(x + i);
        }
        return min;
    } else {
        return DBL_MAX;
    }
}

unsigned int min_vec_ind(double* x, size_t n) {
    if(n > 0) {
        double min = *(x), min_ind = 0;
        for(unsigned int i = 1; i < n; i++) {
            if(*(x + i) < min) { 
                min = *(x + i);
                min_ind = i;
            }
        }
        return min_ind;
    } else {
        return -1;
    }
}

void abs_vec(double* x, size_t n) {
    for(unsigned int i = 0; i < n; i++) {
        *(x + i) = abs(*(x + i));
    }
}

void add(double* x, double* y, double* z, size_t n) {
    for(unsigned int i = 0; i < n; i++) {
        *(z + i) = *(x + i) + *(y + i);
    }
}

void sub(double* x, double* y, double* z, size_t n) {
    for(unsigned int i = 0; i < n; i++) {
        *(z + i) = *(x + i) - *(y + i);
    }
}

void mult(double* x, double* y, double* z, size_t n) {
    for(unsigned int i = 0; i < n; i++) {
        *(z + i) = *(x + i) * *(y + i);
    }
}

void div(double* x, double* y, double* z, size_t n) {
    for(unsigned int i = 0; i < n; i++) {
        *(z + i) = *(x + i) / *(y + i);
    }
}

void power(double* x, int p, size_t n) {
    for(unsigned int i = 0; i < n; i++) {
        *(x + i) = pow(*(x + i), p);
    }
}

void delete_element(double *x, unsigned int pos, size_t n) {
    if(pos <= n) {
        for(unsigned int i = pos; i < n; i++) {
            *(x + i) = *(x + i + 1);
        }
    }
}

double dot(double *x, double* y, size_t n) {
    double res = 0;
    for(unsigned int i = 0; i < n; i++) {
        res += *(x + i) * *(y + i);
    }
    return res;
}

void copy_vec(double* src, double* dst, size_t n) {
    for(unsigned int i = 0; i < n; i++) {
        *(dst + i) = *(src + i);
    }
}


