#include <stdlib.h>
#include "matrix.h"

matrix* new_matrix(int rows, int cols) {
    matrix* mat = malloc(sizeof(matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->mat = calloc(rows, sizeof(double*));
    for(unsigned int i = 0; i < rows; i++) {
        mat->mat[i] = calloc(cols, sizeof(double));
    }
    return mat;
}

void fill_matrix(matrix* m, double val) {
    for(unsigned int i = 0; i < m->rows; i++) {
        for(unsigned int j = 0; j < m->cols; j++) {
            m->mat[i][j] = val;
        }
    }
}

matrix* ones(int rows, int cols) {
    matrix* m = new_matrix(rows, cols);
    for(unsigned int i = 0; i < m->rows; i++) {
        for(unsigned int j = 0; j < m->cols; j++) {
            m->mat[i][j] = 1.0;
        }
    }
    return m;
}

matrix* zeros(int rows, int cols) {
    matrix* m = new_matrix(rows, cols);
    for(unsigned int i = 0; i < m->rows; i++) {
        for(unsigned int j = 0; j < m->cols; j++) {
            m->mat[i][j] = 0.0;
        }
    }
    return m;
}

matrix* ide(int n) {
    matrix* m = new_matrix(n, n);
    for(unsigned int i = 0; i < n; i++) {
        for(unsigned int j = 0; j < n; j++) {
            if(i == j) m->mat[i][j] = 1.0;
            else m->mat[i][j] = 0.0;
        }
    }
    return m;
}

void free_matrix(matrix* m) {
    for(unsigned int i = 0; i < m->rows; i++) {
        free(m->mat[i]);
    }
    free(m);
    m = NULL;
}

void print_matrix(matrix* m) {
    for(unsigned int i = 0; i < m->rows; i++) {
        for(unsigned int j = 0; j < m->cols; j++) {
            printf("%f", m->mat[i][j]);
        }
        printf("\n");
    }
}

matrix* copy_matrix(matrix* m) {
    matrix* n = new_matrix(m->rows, m->cols);
    for(unsigned int i = 0; i < m->rows; i++) {
        for(unsigned int j = 0; j < m->cols; j++) {
            n->mat[i][j] = m->mat[i][j];
        }
    }
    return n;
}