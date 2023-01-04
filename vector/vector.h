typedef struct {
    int dim;
    double* vec;
} vector;

vector* new_vector(int dim);
void fill_vector(vector* v, double* entries);
void fill_vector_value(vector* v, double val);
void free_vector(vector* v);
void print_vector(vector* v);
vector* copy_vector(vector* v);
