#include "matrix.h"

int check_dimensions(matrix* m1, matrix* m2);
int can_dot(matrix* m1, matrix* m2);
double sum(matrix* m);
double max_rows(matrix* m);
double min_rows(matrix* m);
int* max_rows_index(matrix* m);
int* min_rows_index(matrix* m);
matrix* sum_rows(matrix* m);
matrix* sum_cols(matrix* m);
double prod(matrix* m);
matrix* abs_mat(matrix* m);
matrix* add(matrix* m1, matrix* m2);
matrix* sub(matrix* m1, matrix* m2);
matrix* mult(matrix* m1 , matrix* m2);
matrix* div(matrix* m1, matrix* m2);
matrix* power(matrix* m1, int p);
matrix* apply(matrix* m1, double (*f)(double));
matrix* dot(matrix* m1, matrix* m2);
matrix* scale(matrix* m1, double c);
matrix* scalar_sum(matrix* m1, double c);
void save_matrix(matrix* m1, char* file_name);
matrix* read_matrix(char* file_name);