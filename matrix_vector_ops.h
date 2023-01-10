#include "./vector/vector_ops.h"
#include "./matrix/matrix_ops.h"

int check_dimensions_rows(matrix* m, vector* v);
int check_dimensions_cols(matrix* m, vector* v);
matrix* matrix_from_vector(vector* v);
vector* vector_from_matrix(matrix* m);
vector* vector_from_row(matrix* m, unsigned int row);
matrix* add_rows(matrix* m, vector* v);
matrix* add_cols(matrix* m, vector* v);
matrix* sub_rows(matrix* m, vector* v);
matrix* sub_cols(matrix* m, vector* v);
vector* dot_mv(matrix* m, vector* v);
vector* dot_vm(vector* v, matrix* m);
void add_rows_inplace(matrix* m, vector* v);
void add_cols_inplace(matrix* m, vector* v);
void sub_rows_inplace(matrix* m, vector* v);
void sub_cols_inplace(matrix* m, vector* v);
