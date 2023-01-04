typedef struct {
    int rows;
    int cols;
    double** mat;
} matrix;

matrix* new_matrix(int rows, int cols);
matrix* ones(int rows, int cols);
matrix* zeros(int rows, int cols);
matrix* ide(int n);
void fill_matrix(matrix* m, double val);
void free_matrix(matrix* m);
void print_matrix(matrix* m);
matrix* copy_matrix(matrix* m);