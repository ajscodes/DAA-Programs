#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

int main() {
    FILE *file;

    // BestCase.txt: Sorted ascending
    file = fopen("BestCase.txt", "w");
    for (int i = 0; i < N; i++) {
        fprintf(file, "%d ", i);
    }
    fclose(file);

    // WorstCase.txt: Sorted descending
    file = fopen("WorstCase.txt", "w");
    for (int i = N - 1; i >= 0; i--) {
        fprintf(file, "%d ", i);
    }
    fclose(file);

    // AverageCase.txt: Random values
    file = fopen("AverageCase.txt", "w");
    srand(time(NULL)); // Seed random generator
    for (int i = 0; i < N; i++) {
        fprintf(file, "%d ", rand() % N);
    }
    fclose(file);

    printf("Test case files generated successfully.\n");
    return 0;
}
