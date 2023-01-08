#include <stdio.h>
#include "matrix_vector_ops.h"

int check_dimensions_rows(matrix* m, vector* v) {
    if(m->rows == v->dim) return 1;
    return 0;
}

int check_dimensions_cols(matrix* m, vector* v) {
    if(m->cols == v->dim) return 1;
    return 0;
}

matrix* add_rows(matrix* m, vector* v) {
    if(check_dimensions_cols(m, v)) {
        matrix* n = new_matrix(m->rows, m->cols);
        for(unsigned int i = 0; i < m->rows; i++) {
            for(unsigned int j = 0; j < m->cols; j++) {
                n->mat[i][j] = v->vec[j] + m->mat[i][j];
            }
        }
        return n;
    } else {
        exit(1);
    }
}

matrix* add_cols(matrix* m, vector* v) {
    if(check_dimensions_rows(m, v)) {
        matrix* n = new_matrix(m->rows, m->cols);
        for(unsigned int i = 0; i < m->cols; i++) {
            for(unsigned int j = 0; j < m->rows; j++) {
                n->mat[j][i] = v->vec[j] + m->mat[j][i];
            }
        }
        return n;
    } else {
        exit(1);
    }
}


matrix* sub_rows(matrix* m, vector* v) {
    if(check_dimensions_cols(m, v)) {
        matrix* n = new_matrix(m->rows, m->cols);
        for(unsigned int i = 0; i < m->rows; i++) {
            for(unsigned int j = 0; j < m->cols; j++) {
                n->mat[i][j] = v->vec[j] - m->mat[i][j];
            }
        }
        return n;
    } else {
        exit(1);
    }
}

matrix* sub_cols(matrix* m, vector* v) {
    if(check_dimensions_rows(m, v)) {
        matrix* n = new_matrix(m->rows, m->cols);
        for(unsigned int i = 0; i < m->rows; i++) {
            for(unsigned int j = 0; j < m->cols; j++) {
                n->mat[i][j] = v->vec[j] - m->mat[i][j];
            }
        }
        return n;
    } else {
        exit(1);
    }
}

vector* dot_mv(matrix* m, vector* v) {
    if(check_dimensions_cols(m, v)) {
        vector* n = new_vector(m->rows);
        for(unsigned int i = 0; i < m->rows; i++) {
            double tmp = 0.0;
            for(unsigned int j = 0; j < m->cols; j++) {
                tmp += m->mat[i][j] * v->vec[j];
            }
            n->vec[i] = tmp;
        }
        return n;
    } else {
        exit(1);
    }
}

matrix* dot_vm(vector* v, matrix* m) {
    if(check_dimensions_rows(m, v)) {
        vector* n = new_vector(m->cols);
        for(unsigned int i = 0; i < m->cols; i++) {
            double tmp = 0.0;
            for(unsigned int j = 0; j < m->rows; j++) {
                tmp += v->vec[j] * m->mat[j][i];
            }
            n->vec[i] = tmp;
        }
        return n;
    } else {
        exit(1);
    }
}