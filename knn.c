#include <stdio.h>
#include <stdlib.h>
#include "distances.h"

unsigned int* get_nearest_k(matrix* data, vector* x, vector* (*dist)(matrix*, vector*), unsigned int k);
unsigned int get_class(int* classes, unsigned int* closest, int k);

unsigned int* get_nearest_k(matrix* data, vector* x, vector* (*dist)(matrix*, vector*), unsigned int k) {
    vector* distances = dist(data, x);
    unsigned int* closest = calloc(k, sizeof(double));
    for(unsigned int i = 0; i < k; i++) {
        *(closest + i) = min_vec_index(distances);
        distances = delete_element_vec(distances, *(closest + i));
    }
    free_vector(dist);
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