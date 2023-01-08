#include <stdio.h>
#include <stdlib.h>
#include "distances.h"
#include "./vector/vector_ops.h"
#include "./matrix/matrix_ops.h"
#include "matrix_vector_ops.h"

unsigned int* get_nearest_k(matrix* data, vector* x, double (*dist)(double*, double*, size_t), unsigned int k);

unsigned int* get_nearest_k(matrix* data, vector* x, double (*dist)(double*, double*, size_t), unsigned int k) {
    double* distances = calloc(x->dim, sizeof(double));
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