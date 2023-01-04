#include <stdio.h>
#include <stdlib.h>
#include "distances.h"
#include "./matrix/vector_ops.h"
#include "./matrix/matrix_ops.h"

unsigned int* get_nearest_k(size_t n_rows, size_t n_cols, double data[n_rows][n_cols], double x[n_cols], double (*dist)(double*, double*, size_t), unsigned int k);

unsigned int* get_nearest_k(size_t n_rows, size_t n_cols, double data[n_rows][n_cols], double x[n_cols], double (*dist)(double*, double*, size_t), unsigned int k) {
    double* distances = calloc(n_rows, sizeof(double));
    for(unsigned int i = 0; i < n_rows; ++i) {
        *(distances + i) = dist(data[i], x, n_cols);
    }
    unsigned int* closest = calloc(k, sizeof(unsigned int));
    for(unsigned int i = 0; i < k; i++) {
        unsigned int aux = min_vec_index(distances, n_rows);
        delete_element(distances, aux, n_rows);
        *(closest + i) = aux;
    }
    free(distances);
    return closest;
}

unsigned int get_class(int* classes, unsigned int* closest, int k) {
    int* selected_classes = calloc(k, sizeof(int));
    for(unsigned int i = 0; i < k; i++) {
        selected_classes[i] = classes[closest[i]];
    }
    int max_count = 0, max = 0;
    for(unsigned int i = 0; i < k; i++) {
        int count = 0;
        for(unsigned int j = 0; j < k; j++) {
            if(selected_classes[i] == selected_classes[j]) {
                count++;
            }
        }
        if(count > max_count) {
            max_count = count;
            max = selected_classes[i];
        }
    }
    return max;
}

int main(void) {
    return 0;
}