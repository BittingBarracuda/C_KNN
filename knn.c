#include <stdio.h>
#include <stdlib.h>
#include "distances.h"
#include "./vector/vector_ops.h"

#define MAXINPUT 1024

int* fit(matrix* train, matrix* test, int* classes, vector* (*dist)(matrix*, vector*), unsigned int k);
void read_data(char* file_path, char* classes_path, matrix* data, int* classes);
int* read_classes_file(char* file_path, int n_instances);
unsigned int* get_nearest_k(matrix* data, vector* x, vector* (*dist)(matrix*, vector*), unsigned int k);
int get_class(int* classes, unsigned int* closest, int k);
void split_classes_array(int* classes, int* classes_train, int* classes_test, double training_split);
double get_precission(int* classes, int* predicted_classes);

int* fit(matrix* train, matrix* test, int* classes, vector* (*dist)(matrix*, vector*), unsigned int k) {
    int* predicted_classes = calloc(test->rows, sizeof(int));
    for(unsigned int i = 0; i < test->rows; i++) {
        vector* tmp = vector_from_row(test, i);
        unsigned int* tmp_closest = get_nearest_k(train, tmp, dist, k);
        *(predicted_classes + i) = get_class(classes, tmp_closest, k);
        free(tmp);
    }
    return predicted_classes;
}

void read_data(char* file_path, char* classes_path, matrix* data, int* classes) {
    data = read_matrix(file_path);
    classes = read_classes_file(classes_path, data->rows);
    shuffle_with_classes(data, classes);
}

int* read_classes_file(char* file_path, int n_instances) {
    FILE* fd = fopen(file_path, "r");
    char line[MAXINPUT];
    int* classes = calloc(n_instances, sizeof(int));
    for(unsigned int i = 0; i < n_instances; i++) {
        fgets(line, MAXINPUT, fd);
        *(classes + i) = atoi(line);
    }
    return classes;
}

unsigned int* get_nearest_k(matrix* data, vector* x, vector* (*dist)(matrix*, vector*), unsigned int k) {
    vector* distances = dist(data, x);
    unsigned int* closest = calloc(k, sizeof(double));
    for(unsigned int i = 0; i < k; i++) {
        *(closest + i) = min_vec_index(distances);
        delete_element_vec(distances, *(closest + i));
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

void split_classes_array(int* classes, int* classes_train, int* classes_test, double training_split) {
    if(training_split >= 0.0 && training_split <= 1.0) {
        int size = sizeof(classes) / sizeof(int);
        int n_rows_train = (int)(0.7 * size);
        int n_rows_test = size - n_rows_train;
        classes_train = calloc(n_rows_train, sizeof(int));
        classes_test = calloc(n_rows_test, sizeof(int));
        for(unsigned int i = 0; i < n_rows_train; i++) {
            *(classes_train + i) = *(classes + i);
        }
        for(unsigned int i = n_rows_train; i < size; i++) {
            *(classes_test + i) = *(classes + i);
        }
    }
}

double get_precission(int* classes, int* predicted_classes) {
    int size = sizeof(classes) / sizeof(int);
    int count_ok = 0;
    for(unsigned int i = 0; i < size; i++) {
        if(*(classes + i) == *(predicted_classes + i)) count_ok += 1;
    }
    return (double)(count_ok / size);
}

int main(void) {
    int k;
    char* file_path = calloc(MAXINPUT, sizeof(char));
    char* classes_path = calloc(MAXINPUT, sizeof(char));
    matrix* data; int* classes;
    scanf("[+] Enter the path to the dataset file: %s\n", file_path);
    scanf("[+] Enter the path to the file with the classes: %s\n", classes_path);
    scanf("[+] Enter the number of neighbors for the K-NN classifier: %d\n", &k);
    printf("[!] Reading dataset and classes files...\n");
    read_data(file_path, classes_path, data, classes);
    printf("[!] Datasets files read and saved!\n");
    matrix* train; matrix* test;
    printf("[!] Splitting dataset into test and train sets...\n");
    get_matrix_split(data, train, test, 0.7);
    free_matrix(data);
    printf("[!] Fitting test dataset...\n");
    int* predicted_classes = fit(train, test, classes, euclidean, k);
    printf("[+] Precission of the model is: %.6f\n", get_precission(classes, predicted_classes));
    free(predicted_classes); free_matrix(train); free_matrix(test); free(file_path); free(classes_path);
}