typedef struct {
    int rows;
    int cols;
    double** mat;
} matrix;

matrix* new_matrix(int rows, int cols);
matrix* ones_matrix(int rows, int cols);
matrix* zeros_matrix(int rows, int cols);
matrix* ide(int n);
void fill_matrix(matrix* m, double** mat);
void fill_matrix_val(matrix* m, double val);
void free_matrix(matrix* m);
void print_matrix(matrix* m);
matrix* copy_matrix(matrix* m);
void save_matrix(matrix* m1, char* file_name);
matrix* read_matrix(char* file_name);