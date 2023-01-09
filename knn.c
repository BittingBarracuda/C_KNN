#include <stdio.h>
#include <stdlib.h>
#include "distances.h"

int* fit(matrix* test, matrix* train, vector* (*dist)(matrix*, vector*), unsigned int k);
matrix* read_data(char* file_path);
unsigned int* get_nearest_k(matrix* data, vector* x, vector* (*dist)(matrix*, vector*), unsigned int k);
int get_class(int* classes, unsigned int* closest, int k);

int* fit(matrix* train, matrix* test, int* classes, vector* (*dist)(matrix*, vector*), unsigned int k) {
    int* predicted_classes = calloc(test->rows, sizeof(int));
    for(unsigned int i = 0; i < test->rows; i++) {
        vector* tmp = vector_from_row(test, i);
        unsigned int* tmp_closest = get_nearest_k(train, tmp, dist, k);
        *(predicted_classes + i) = get_class(classes, tmp_closest, k);
    }
    return predicted_classes;
}

matrix* read_data(char* file_path) {
    matrix* data = read_matrix(file_path);
    shuffle(data);
    return data;
}

unsigned int* get_nearest_k(matrix* data, vector* x, vector* (*dist)(matrix*, vector*), unsigned int k) {
    vector* distances = dist(data, x);
    unsigned int* closest = calloc(k, sizeof(double));
    for(unsigned int i = 0; i < k; i++) {
        *(closest + i) = min_vec_index(distances);
        distances = delete_element_vec(distances, *(closest + i));
    }
    free_vector(distances);
    return closest;
}

int get_class(int* classes, unsigned int* closest, int k) {
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
    free(selected_classes);
    return max;
}

int main(void) {
    char* file_path = "TODO";
    matrix* data = read_data(file_path);
    matrix* train; matrix* test;
    get_matrix_split(data, train, test, 0.7);
    free_matrix(data);
}