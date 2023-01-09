#include "./vector/vector.h"
#include "./matrix/matrix.h"

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
