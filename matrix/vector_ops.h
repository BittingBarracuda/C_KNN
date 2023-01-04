#include "vector.h"

int check_dimensions(vector* v1, vector* v2);
double sum(vector* v);
double prod(vector* v);
double max_vec(vector* v);
int max_vec_index(vector* v);
double min_vec(vector* v);
int min_vec_intex(vector* v);
vector* abs_vec(vector* v);
vector* add(vector* v1, vector* v2);
vector* sub(vector* v1, vector* v2);
vector* mult(vector* v1, vector* v2);
vector* div(vector* v1, vector* v2);
vector* power(vector* v1, int p);
vector* delete_element(vector* v, int pos);
double dot(vector* v1, vector* v2);
vector* scale(vector* v1, double scalar);
vector* add_scalar(vector* v1, double scalar);