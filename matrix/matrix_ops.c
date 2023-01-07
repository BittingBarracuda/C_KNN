#include <stdlib.h>
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

double sum(matrix* m) {
    double total = 0.0;
    for(unsigned int i = 0; i < m->rows; i++) {
        for(unsigned int j = 0; j < m->cols; j++) {
            total += m->mat[i][j];
        }
    }
    return total;
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

matrix* div(matrix* m1, matrix* m2) {
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
            m2->mat[i][j] = c * m2->mat[i][j];
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