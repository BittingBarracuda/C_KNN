#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "matrix_ops.h"

int check_dimensions(matrix* m1, matrix* m2) {
    if(m1->rows == m2->rows && m1->cols == m2->cols) return 1;
    return 0;
}

int can_dot(matrix* m1, matrix* m2) {
    if(m1->cols == m2->rows) return 1;
    return 0;
}

double max_rows(matrix* m) {
    double max = m->mat[0][0];
    for(unsigned int i = 0; i < m->rows; i++) {
        for(unsigned int j = 0; j < m->cols; j++) {
            if(m->mat[i][j] > max) max = m->mat[i][j];
        }
    }
    return max;
}

double min_rows(matrix* m) {
    double min = m->mat[0][0];
    for(unsigned int i = 0; i < m->rows; i++) {
        for(unsigned int j = 0; j < m->cols; j++) {
            if(m->mat[i][j] < min) min = m->mat[i][j];
        }
    }
    return min;
}

int* max_rows_index(matrix* m) {
    double max = m->mat[0][0];
    int* index = calloc(2, sizeof(int));
    for(unsigned int i = 0; i < m->rows; i++) {
        for(unsigned int j = 0; j < m->cols; j++) {
            if(m->mat[i][j] > max) { 
                max = m->mat[i][j];
                index[0] = i; index[1] = j;
            }
        }
    }
    return index;
}

int* min_rows_index(matrix* m) {
    double min = m->mat[0][0];
    int* index = calloc(2, sizeof(int));
    for(unsigned int i = 0; i < m->rows; i++) {
        for(unsigned int j = 0; j < m->cols; j++) {
            if(m->mat[i][j] < min) { 
                min = m->mat[i][j];
                index[0] = i; index[1] = j;
            }
        }
    }
    return index;
}

double sum(matrix* m) {
    double total = 0.0;
    for(unsigned int i = 0; i < m->rows; i++) {
        for(unsigned int j = 0; j < m->cols; j++) {
            total += m->mat[i][j];
        }
    }
    return total;
}

matrix* sum_rows(matrix* m) {
    matrix* n = new_matrix(m->rows, 1);
    for(unsigned int i = 0; i < m->rows; i++) {
        double tmp = 0.0;
        for(unsigned int j = 0; j < m->cols; j++) {
            tmp += m->mat[i][j];
        }
        n->mat[i][0] = tmp;
    }
    return n;
}

matrix* sum_cols(matrix* m) {
    matrix* n = new_matrix(1, m->cols);
    for(unsigned int i = 0; i < m->cols; i++) {
        double tmp = 0.0;
        for(unsigned int j = 0; j < m->rows; j++) {
            tmp += m->mat[j][i];
        }
        n->mat[0][i] = tmp;
    }
    return n;
}

double prod(matrix* m) {
    double prod = 1.0;
    for(unsigned int i = 0; i < m->rows; i++) {
        for(unsigned int j = 0; j < m->cols; j++) {
            prod *= m->mat[i][j];
        }
    }
    return prod;
}

matrix* abs_mat(matrix* m) {
    matrix* m2 = new_matrix(m->rows, m->cols);
    for(unsigned int i = 0; i < m->rows; i++) {
        for(unsigned int j = 0; j < m->cols; j++) {
            m2->mat[i][j] = abs(m2->mat[i][j]);
        }
    }
    return m2;
}

matrix* add(matrix* m1, matrix* m2) {
    if(check_dimensions(m1, m2)) {
        matrix* m3 = new_matrix(m1->rows, m1->cols);
        for(unsigned int i = 0; i < m1->rows; i++) {
            for(unsigned int j = 0; j < m1->cols; j++) {
                m3->mat[i][j] = m1->mat[i][j] + m2->mat[i][j];
            }
        }
        return m3;
    } else {
        printf("Matrix dimensions should be equal to sum them!\n");
        exit(1);
    }
}

matrix* sub(matrix* m1, matrix* m2) {
    if(check_dimensions(m1, m2)) {
        matrix* m3 = new_matrix(m1->rows, m1->cols);
        for(unsigned int i = 0; i < m1->rows; i++) {
            for(unsigned int j = 0; j < m1->cols; j++) {
                m3->mat[i][j] = m1->mat[i][j] - m2->mat[i][j];
            }
        }
        return m3;
    } else {
        printf("Matrix dimensions should be equal to subtract them!\n");
        exit(1);
    }
}

matrix* mult(matrix* m1 , matrix* m2) {
    if(check_dimensions(m1, m2)) {
        matrix* m3 = new_matrix(m1->rows, m1->cols);
        for(unsigned int i = 0; i < m1->rows; i++) {
            for(unsigned int j = 0; j < m1->cols; j++) {
                m3->mat[i][j] = m1->mat[i][j] * m2->mat[i][j];
            }
        }
        return m3;
    } else {
        printf("Matrix dimensions should be equal to multiply them!\n");
        exit(1);
    }
}

matrix* divide(matrix* m1, matrix* m2) {
    if(check_dimensions(m1, m2)) {
        matrix* m3 = new_matrix(m1->rows, m1->cols);
        for(unsigned int i = 0; i < m1->rows; i++) {
            for(unsigned int j = 0; j < m1->cols; j++) {
                m3->mat[i][j] = m1->mat[i][j] / m2->mat[i][j];
            }
        }
        return m3;
    } else {
        printf("Matrix dimensions should be equal to divide them!\n");
        exit(1);
    }
}

matrix* power(matrix* m1, int p) {
    matrix* m2 = new_matrix(m1->rows, m1->cols);
    for(unsigned int i = 0; i < m1->rows; i++) {
        for(unsigned int j = 0; j < m1->cols; j++) {
            m2->mat[i][j] = pow(m2->mat[i][j], p);
        }
    }
    return m2;
}

matrix* apply(matrix* m1, double (*f)(double)) {
    matrix* m2 = new_matrix(m1->rows, m1->cols);
    for(unsigned int i = 0; i < m1->rows; i++) {
        for(unsigned int j = 0; j < m1->cols; j++) {
            m2->mat[i][j] = f(m2->mat[i][j]);
        }
    }
    return m2;
}

matrix* dot(matrix* m1, matrix* m2) {
    if(can_dot(m1, m2)) {
        matrix* m3 = new_matrix(m1->rows, m2->cols);
        for(unsigned int i = 0; i < m1->rows; i++) {
            for(unsigned int j = 0; j < m2->cols; j++) {
                double tmp = 0.0;
                for(unsigned int k = 0; k < m1->cols; k++) {
                    tmp += m1->mat[i][k] * m2->mat[k][j];
                }
                m3->mat[i][j] = tmp;
            }
        }
        return m3;
    } else {
        printf("Cannot dot matrices with given dimensions\n");
        exit(1);
    }
}

matrix* scale(matrix* m1, double c) {
    matrix* m2 = new_matrix(m1->rows, m1->cols);
    for(unsigned int i = 0; i < m1->rows; i++) {
        for(unsigned int j = 0; j < m1->cols; j++) {
            m2->mat[i][j] = c * m1->mat[i][j];
        }
    }
    return m2;
}

matrix* scalar_sum(matrix* m1, double c) {
    matrix* m2 = new_matrix(m1->rows, m1->cols);
    for(unsigned int i = 0; i < m1->rows; i++) {
        for(unsigned int j = 0; j < m1->cols; j++) {
            m2->mat[i][j] = c + m2->mat[i][j];
        }
    }
    return m2;
}

void abs_mat_inplace(matrix* m) {
    for(unsigned int i = 0; i < m->rows; i++) {
        for(unsigned int j = 0; j < m->cols; j++) {
            m->mat[i][j] = abs(m->mat[i][j]);
        }
    }
}

void add_inplace(matrix* m1, matrix* m2) {
    if(check_dimensions(m1, m2)) {
        for(unsigned int i = 0; i < m1->rows; i++) {
            for(unsigned int j = 0; j < m1->cols; j++) {
                m1->mat[i][j] = m1->mat[i][j] + m2->mat[i][j];
            }
        }
    } else {
        printf("Matrix dimensions should be equal to sum them!\n");
        exit(1);
    }
}

void sub_inplace(matrix* m1, matrix* m2) {
    if(check_dimensions(m1, m2)) {
        for(unsigned int i = 0; i < m1->rows; i++) {
            for(unsigned int j = 0; j < m1->cols; j++) {
                m1->mat[i][j] = m1->mat[i][j] - m2->mat[i][j];
            }
        }
    } else {
        printf("Matrix dimensions should be equal to subtract them!\n");
        exit(1);
    }
}

void mult_inplace(matrix* m1 , matrix* m2) {
    if(check_dimensions(m1, m2)) {
        for(unsigned int i = 0; i < m1->rows; i++) {
            for(unsigned int j = 0; j < m1->cols; j++) {
                m1->mat[i][j] = m1->mat[i][j] * m2->mat[i][j];
            }
        }
    } else {
        printf("Matrix dimensions should be equal to multiply them!\n");
        exit(1);
    }
}

void div_inplace(matrix* m1, matrix* m2) {
     if(check_dimensions(m1, m2)) {
        for(unsigned int i = 0; i < m1->rows; i++) {
            for(unsigned int j = 0; j < m1->cols; j++) {
                m1->mat[i][j] = m1->mat[i][j] / m2->mat[i][j];
            }
        }
    } else {
        printf("Matrix dimensions should be equal to divide them!\n");
        exit(1);
    }
}

void power_inplace(matrix* m1, int p) {
    for(unsigned int i = 0; i < m1->rows; i++) {
        for(unsigned int j = 0; j < m1->cols; j++) {
            m1->mat[i][j] = pow(m1->mat[i][j], p);
        }
    }
}

void apply_inplace(matrix* m1, double (*f)(double)) {
    for(unsigned int i = 0; i < m1->rows; i++) {
        for(unsigned int j = 0; j < m1->cols; j++) {
            m1->mat[i][j] = f(m1->mat[i][j]);
        }
    }
}

void scale_inplace(matrix* m1, double c) {
    for(unsigned int i = 0; i < m1->rows; i++) {
        for(unsigned int j = 0; j < m1->cols; j++) {
            m1->mat[i][j] = c * m1->mat[i][j];
        }
    }
}

void scalar_sum_inplace(matrix* m1, double c) {
    for(unsigned int i = 0; i < m1->rows; i++) {
        for(unsigned int j = 0; j < m1->cols; j++) {
            m1->mat[i][j] = c + m1->mat[i][j];
        }
    }
}

void shuffle(matrix* m) {
    srand(time(NULL));
    for(unsigned int i = 0; i < m->rows; i++) {
        int r = rand() % m->rows;
        double* tmp = m->mat[r];
        m->mat[r] = m->mat[i];
        m->mat[i] = tmp;
    }
}

void shuffle_with_classes(matrix* m, int* classes) {
    srand(time(NULL));
    for(unsigned int i = 0; i < m->rows; i++) {
        int r = rand() % m->rows;
        double* tmp_m = m->mat[r];
        int tmp_c = classes[r]; 
        m->mat[r] = m->mat[i];
        classes[r] = classes[i];
        m->mat[i] = tmp_m;
        classes[i] = tmp_c;
    }
}

void get_matrix_split(matrix* m, matrix* s1, matrix* s2, double split) {
    if(split <= 1.0 && split >= 0.0) {
        unsigned int n_rows_s1 = (unsigned int)(split * m->rows);
        unsigned int n_rows_s2 = (unsigned int)(m->rows - n_rows_s1);
        s1 = new_matrix(n_rows_s1, m->cols);
        s2 = new_matrix(n_rows_s2, m->cols);
        for(unsigned int i = 0; i < n_rows_s1; i++) {
            for(unsigned int j = 0; j < m->cols; j++) {
                s1->mat[i][j] = m->mat[i][j];
            }
        }
        for(unsigned int i = 0; i < n_rows_s2; i++) {
            for(unsigned int j = 0; j < m->cols; j++) {
                s2->mat[i][j] = m->mat[n_rows_s1+i][j];
            }
        }
    }
}

void print_shape(matrix* m) {
    printf("(%d, %d)\n", m->rows, m->cols);
}