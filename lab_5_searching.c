#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// Linear search function
void LinearSearch(int arr[], int size, int key) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("Element %d found at index %d\n", key, i);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Element not found\n");
    }
}

// Placeholder for binary search (to be implemented)
void BinarySearch(int arr[], int size, int key) {
    printf("Binary Search is not implemented yet.\n");
}

int main() {
    int number_of_element_in_array;
    int element_to_search;
    char type_of_search[100];

    FILE *file;
    clock_t start, end;
    double cpu_time;

    printf("Enter type of search (linear / binary): ");
    scanf("%s", type_of_search);

    printf("Enter number of elements: ");
    scanf("%d", &number_of_element_in_array);

    printf("Enter element to search: ");
    scanf("%d", &element_to_search);

    int arr1[number_of_element_in_array];
    int arr2[number_of_element_in_array];
    int arr3[number_of_element_in_array];

    // Convert search type to number for switch-case
    int option = 0;
    if (strcmp(type_of_search, "linear") == 0)
        option = 1;
    else if (strcmp(type_of_search, "binary") == 0)
        option = 2;

    switch (option) {
        case 1:
            // BEST CASE
            file = fopen("BestCase.txt", "r");
            for (int i = 0; i < number_of_element_in_array; i++) {
                fscanf(file, "%d", &arr1[i]);
            }
            fclose(file);

            printf("\n::: BEST CASE SCENARIO :::\n");
            start = clock();
            LinearSearch(arr1, number_of_element_in_array, element_to_search);
            end = clock();
            cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Time taken: %f seconds\n", cpu_time);

            // AVERAGE CASE
            file = fopen("AverageCase.txt", "r");
            for (int i = 0; i < number_of_element_in_array; i++) {
                fscanf(file, "%d", &arr2[i]);
            }
            fclose(file);

            printf("\n::: AVERAGE CASE SCENARIO :::\n");
            start = clock();
            LinearSearch(arr2, number_of_element_in_array, element_to_search);
            end = clock();
            cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Time taken: %f seconds\n", cpu_time);

            // WORST CASE
            file = fopen("WorstCase.txt", "r");
            for (int i = 0; i < number_of_element_in_array; i++) {
                fscanf(file, "%d", &arr3[i]);
            }
            fclose(file);

            printf("\n::: WORST CASE SCENARIO :::\n");
            start = clock();
            LinearSearch(arr3, number_of_element_in_array, element_to_search);
            end = clock();
            cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Time taken: %f seconds\n", cpu_time);
            break;

        case 2:
            printf("\nBinary Search is not implemented yet.\n");
            break;

        default:
            printf("Invalid search type!\n");
    }

    return 0;
}
