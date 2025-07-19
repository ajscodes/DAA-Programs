#include<stdio.h>
#include<stdlib.h>

void main(){
    FILE *file;

    //BestCase.txt generator
    file = fopen("BestCase.txt", "w");
    for (int i = 0; i < 100000; i++)
    {
        fprintf(file, "%d ", i);
    }
    fclose(file);

    //WorstCase.txt generator
    file = fopen("WorstCase.txt", "w");
    for (int i = 100000; i > 0; i--)
    {
        fprintf(file, "%d ", i);
    }
    fclose(file);

    //AverageCase.txt generator
    file = fopen("AverageCase.txt", "w");
    for (int i = 0; i < 100000; i++)
    {
        fprintf(file, "%d ", rand() % 100000);
    }
    fclose(file);
}