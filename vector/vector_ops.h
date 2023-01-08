#include "vector.h"

int check_dimensions_vec(vector* v1, vector* v2);
double sum_vec(vector* v);
double prod_vec(vector* v);
double max_vec(vector* v);
int max_vec_index(vector* v);
double min_vec(vector* v);
int min_vec_index(vector* v);
vector* abs_vec(vector* v);
vector* add_vec(vector* v1, vector* v2);
vector* sub_vec(vector* v1, vector* v2);
vector* mult_vec(vector* v1, vector* v2);
vector* div_vec(vector* v1, vector* v2);
vector* power_vec(vector* v1, int p);
vector* delete_element_vec(vector* v, int pos);
vector* apply_vec(vector* v, double (*f)(double));
double dot_vec(vector* v1, vector* v2);
vector* scale_vec(vector* v1, double scalar);
vector* add_scalar_vec(vector* v1, double scalar);