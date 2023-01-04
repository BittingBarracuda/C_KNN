#include <stdlib.h>
#include "vector.h"

vector* new_vector(int dim) {
    vector *v = malloc(sizeof(vector));
    v->dim = dim;
    v->vec = calloc(dim, sizeof(double));
    return v;
}

void fill_vector(vector* v, double* entries) {
    for(unsigned int i = 0; i < v->dim; i++) {
        v->vec[i] = entries[i];
    }
}

void free_vector(vector* v) {
    free(v->vec);
    free(v);
    v = NULL;
}

void print(vector* v) {
    for(unsigned int i = 0; i < v->dim; i++) {
        printf("%f ", v->vec[i]);
    }
}

vector* copy_vector(vector* v) {
    vector* dst = new_vector(v->dim);
    for(unsigned int i = 0; i < v->dim; i++) {
        dst->vec[i] = v->vec[i];
    }
    return dst;
}