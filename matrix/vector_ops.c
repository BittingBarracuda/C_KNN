#include <stdlib.h>
#include <float.h>
#include "vector_ops.h"

int check_dimensions(vector* v1, vector* v2) {
    if(v1->dim == v2->dim) return 1;
    return 0;
}

double sum(vector* v) {
    double sum = 0.0;
    for(unsigned int i = 0; i < v->dim; i++) {
        sum += v->vec[i];
    }
    return sum;
}

double prod(vector* v) {
    double prod = 1.0;
    for(unsigned int i = 0; i < v->dim; i++) {
        prod *= v->vec[i];
    }
    return prod;
}

double max_vec(vector* v) {
    if(v->dim > 0) {
        double max = v->vec[0];
        for(unsigned int i = 0; i < v->dim; i++) {
            if(v->vec[i] > max) max = v->vec[i];
        }
        return max;
    } else {
        return DBL_MIN;
    }
}

int max_vec_index(vector* v) {
    if(v->dim > 0) {
        double max = v->vec[0];
        unsigned int max_ind = 0;
        for(unsigned int i = 0; i < v->dim; i++) {
            if(v->vec[i] > max)  {
                max = v->vec[i];
                max_ind = i;
            }
        }
        return max_ind;
    } else {
        return -1;
    }
}

double min_vec(vector* v) {
    if(v->dim > 0) {
        double min = v->vec[0];
        for(unsigned int i = 0; i < v->dim; i++) {
            if(v->vec[i] < min) min = v->vec[i];
        }
        return min;
    } else {
        return DBL_MAX;
    }
}

int min_vec_index(vector* v) {
    if(v->dim > 0) {
        double min = v->vec[0];
        unsigned int min_ind = 0;
        for(unsigned int i = 0; i < v->dim; i++) {
            if(v->vec[i] < min)  {
                min = v->vec[i];
                min_ind = i;
            }
        }
        return min_ind;
    } else {
        return -1;
    }
}

vector* abs_vec(vector* v) {
    vector* u = new_vector(v->dim);
    for(unsigned int i = 0; i < v->dim; i++) {
        v->vec[i] = abs(v->vec[i]);
    }
    return u;
}

vector* add(vector* v1, vector* v2) {
    if(check_dimensions(v1, v2)) {
        vector* v3 = new_vector(v1->dim);
        for(unsigned int i = 0; i < v1->dim; i++) {
            v3->vec[i] = v1->vec[i] + v2->vec[i];
        }
        return v3;
    } else {
        printf("Vector dimensions should be equal!\n");
        exit(1);
    }
}

vector* sub(vector* v1, vector* v2) {
    if(check_dimensions(v1, v2)) {
        vector* v3 = new_vector(v1->dim);
        for(unsigned int i = 0; i < v1->dim; i++) {
            v3->vec[i] = v1->vec[i] - v2->vec[i];
        }
        return v3;
    } else {
        printf("Vector dimensions should be equal!\n");
        exit(1);
    }
}

vector* mult(vector* v1, vector* v2) {
    if(check_dimensions(v1, v2)) {
        vector* v3 = new_vector(v1->dim);
        for(unsigned int i = 0; i < v1->dim; i++) {
            v3->vec[i] = v1->vec[i] * v2->vec[i];
        }
        return v3;
    } else {
        printf("Vector dimensions should be equal!\n");
        exit(1);
    }
}

vector* div(vector* v1, vector* v2) {
    if(check_dimensions(v1, v2)) {
        vector* v3 = new_vector(v1->dim);
        for(unsigned int i = 0; i < v1->dim; i++) {
            v3->vec[i] = v1->vec[i] / v2->vec[i];
        }
        return v3;
    } else {
        printf("Vector dimensions should be equal!\n");
        exit(1);
    }
}

vector* power(vector* v1, int p) {
    vector* v2 = new_vector(v1->dim);
    for(unsigned int i = 0; i < v1->dim; i++) {
        v2->vec[i] = pow(v1->vec[i], p);
    }
    return v2;
}

vector* delete_element(vector* v, int pos) {
    if(v->dim <= pos) {
        vector* u = new_vector(v->dim - 1);
        unsigned int j = 0;
        for(unsigned int i = 0; i < v->dim; i++) {
            if(i != pos) { 
                u->vec[i] = v->vec[j];
                j++;
            }
        }
        return u;
    } else {
        printf("Index %d not valid for vector of %d diemensions", pos, v->dim);
        exit(1);
    }
}

vector* apply(vector* v, double (*f)(double)) {
    vector* u = new_vector(v->dim);
    for(unsigned int i = 0; i < v->dim; i++) {
        u->vec[i] = f(v->vec[i]);
    }
    return u;
}

double dot(vector* v1, vector* v2) {
    if(check_dimensions(v1, v2)) {
        vector* v3 = new_vector(v1->dim);
        double total = 0.0;
        for(unsigned int i = 0; i < v1->dim; i++) {
            total += v1->vec[i] * v2->vec[i];
        }
        return total;
    } else {
        printf("Vector dimensios must be equal!\n");
        exit(1);
    }
}

vector* scale(vector* v, double scalar) {
    vector* u = new_vector(v->dim);
    for(unsigned int i = 0; i < v->dim; i++) {
        u->vec[i] = scalar * v->vec[i];
    }
    return u;
}

vector* add_scalar(vector* v, double scalar) {
    vector* u = new_vector(v->dim);
    for(unsigned int i = 0; i < v->dim; i++) {
        u->vec[i] = scalar + v->vec[i];
    }
    return u;
}