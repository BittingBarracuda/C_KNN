#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "distances.h"

#define MAXINPUT 1024

int* fit(matrix* train, matrix* test, int* classes, vector* (*dist)(matrix*, vector*), unsigned int k);
int* read_classes_file(char* file_path, int n_instances);
unsigned int* get_nearest_k(matrix* data, vector* x, vector* (*dist)(matrix*, vector*), unsigned int k);
int get_class(int* classes, unsigned int* closest, int k);
void split_classes_array(int* classes, int* classes_train, int* classes_test, unsigned int n1, unsigned int n2, int size);
double get_precission(int* classes, int* predicted_classes, int size);

int* fit(matrix* train, matrix* test, int* classes, vector* (*dist)(matrix*, vector*), unsigned int k) {
    int* predicted_classes = calloc(test->rows, sizeof(int));
    for(unsigned int i = 0; i < test->rows; i++) {
        vector* tmp = vector_from_row(test, i);
        unsigned int* tmp_closest = get_nearest_k(train, tmp, dist, k);
        *(predicted_classes + i) = get_class(classes, tmp_closest, k);
        free(tmp_closest);
    }
    return predicted_classes;
}

int* read_classes_file(char* file_path, int n_instances) {
    FILE* fd = fopen(file_path, "r");
    char line[MAXINPUT];
    int* classes = calloc(n_instances, sizeof(int));
    for(unsigned int i = 0; i < n_instances; i++) {
        fgets(line, MAXINPUT, fd);
        *(classes + i) = atoi(line);
    }
    fclose(fd);
    return classes;
}

unsigned int* get_nearest_k(matrix* data, vector* x, vector* (*dist)(matrix*, vector*), unsigned int k) {
    vector* distances = dist(data, x);
    unsigned int* closest = calloc(k, sizeof(double));
    for(unsigned int i = 0; i < k; i++) {
        *(closest + i) = min_vec_index(distances);
        //printf("%d", *(closest+i));
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

void split_classes_array(int* classes, int* classes_train, int* classes_test, unsigned int n1, unsigned int n2, int size) {
    if(n1 < size && n2 < size && n1 + n2 == size) {
        for(unsigned int i = 0; i < n1; i++) {
            *(classes_train + i) = *(classes + i);
        }
        for(unsigned int i = 0; i < n2; i++) {
            *(classes_test + i) = *(classes + n1 + i);
        }
    }
}

double get_precission(int* classes, int* predicted_classes, int size) {
    int count_ok = 0;
    for(unsigned int i = 0; i < size; i++) {
        if(*(classes + i) == *(predicted_classes + i)) count_ok += 1;
    }
    return (double)count_ok / size;
}

int main(void) {
    // ---------------------- GET USER INPUT ----------------------
    int k;
    char* file_path = calloc(MAXINPUT, sizeof(char));
    char* classes_path = calloc(MAXINPUT, sizeof(char));
    printf("[+] Enter the path to the dataset file: ");
    scanf(" %s", file_path);
    printf("[+] Enter the path to the file with the classes: ");
    scanf(" %s", classes_path);
    printf("[+] Enter the number of neighbors for the K-NN classifier: ");
    scanf(" %d", &k);
    printf("[!] Reading dataset and classes files...\n");

    // ---------------------- READ FILES ----------------------
    matrix* data = read_matrix(file_path);
    int* classes = read_classes_file(classes_path, data->rows);
    shuffle_with_classes(data, classes);
    printf("[!] Datasets files read and saved!\n");

    // ---------------------- SPLIT DATASET INTO TEST AND TRAIN ----------------------
    printf("[!] Splitting dataset into test and train sets...\n");
    unsigned int n_rows_train = (unsigned int)(0.7 * data->rows);
    unsigned int n_rows_test = data->rows - n_rows_train;
    matrix* train = new_matrix(n_rows_train, data->cols);
    matrix* test = new_matrix(n_rows_test, data->cols);
    int* classes_train = calloc(n_rows_train, sizeof(int));
    int* classes_test = calloc(n_rows_test, sizeof(int));
    int size_classes = sizeof(classes) / sizeof(int);
    get_matrix_split(data, train, test, n_rows_train, n_rows_test);
    split_classes_array(classes, classes_train, classes_test, n_rows_test, n_rows_train, size_classes);
    free_matrix(data); free(classes);
    printf("[!] Shape of train data: "); print_shape(train);
    printf("[!] Shape of test data: "); print_shape(test);

    // ---------------------- GET PRECISSION WITH TEST DATASET ----------------------
    printf("[!] Fitting test dataset...\n");
    clock_t begin = clock();
    int* predicted_classes = fit(train, test, classes_test, euclidean, k);
    printf("[+] Precission of the model is: %.6f\n", get_precission(classes_test, predicted_classes, n_rows_test));
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("[+] Time required for fitting: %f s", time_spent);
    free(predicted_classes);
    free_matrix(train); free_matrix(test); 
    free(file_path); free(classes_path);
    free(classes_test); free(classes_train);
}