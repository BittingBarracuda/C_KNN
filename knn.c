#include <stdio.h>
#include <stdlib.h>
#include "distances.h"

int* predict(double *data, double *x, int n_rows, int n_cols, int n_inst, double (*dist)(double, double));
int* predict(double *data, double *x, int n_rows, int n_cols, int n_inst, int num_batches);

int* predict(double *data, double *x, int n_rows, int n_cols, int n_inst, double (*dist)(double*, double*)) {
    double* distances = calloc(n_inst, sizeof(double));
    for(unsigned int i = 0; i < n_inst; ++i) {
        for(unsigned int j = 0; j < n_rows; ++j) {
            *(distances + i) = dist(*(data + j), *(x + i), n_cols);
        }
    }

}

//int* predict(double *data)

int main(void) {
    return 0;
}