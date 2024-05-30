#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

int getint() {
    int value = 0;
    int scanf_value = scanf("%d", &value);

    if (!scanf_value) {
        printf("Invalid input. Try again: ");
        scanf("%*[^\n]");
        scanf("%*c");
        return getint();
    }
    return value;
}

void get_complex(double *real, double *imag) {
    char input[100];
    scanf("%s", input);

    if (sscanf(input, "%lf+%lfi", real, imag) != 2) {
        printf("Invalid input. Try again: ");
        get_complex(real, imag);
    }
}

void print_matrix(int xsize, int ysize, double complex **matrix)
{
    for (int i = 0; i < xsize; i++)
    {
        for (int j = 0; j < ysize; j++)
        {
            printf("Complex number: %.2f + %.2fi ", creal(matrix[i][j]), cimag(matrix[i][j]));
        }
        printf("\n");
    }
}

void clear_memory(int xsize, double complex **matrix)
{
    for (int i = 0; i < xsize; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

double complex **plus_matrix(int xsize, int ysize, double complex **matrix, int xsize1, int ysize1, double complex **matrix1)
{
    double complex **arr = (double complex **)malloc(xsize * sizeof(double complex *));
    for (int i = 0; i < ysize; i++)
    {
        arr[i] = (double complex *)malloc(xsize * sizeof(double complex));
    }
    for (int i = 0; i < xsize; i++)
    {
        for (int j = 0; j < ysize; j++)
        {
            arr[i][j] = matrix[i][j] + matrix1[i][j];
        }
    }
    return arr;
}

double complex** mult_matrix(int xsize, int ysize, double complex** matrix, int xsize1, int ysize1, double complex** matrix1) {
    double complex** arr = (double complex**)malloc(xsize * sizeof(double complex*));
    for(int i = 0; i < xsize; i++) {
        arr[i] = (double complex*)malloc(ysize1 * sizeof(double complex));
    }
    for(int i = 0; i < xsize; i++)
    {
        for(int j = 0; j < ysize1; j++)
        {
            arr[i][j] = 0;
            for(int k = 0; k < ysize; k++)
            {
                arr[i][j] += matrix[i][k] * matrix1[k][j];
            }

        }
    }

    return arr;
}

double complex **trans_matrix(int xsize, int ysize, double complex **matrix)
{
    double complex **arr = (double complex **)malloc(ysize * sizeof(double complex *));
    for (int i = 0; i < ysize; i++) {
        arr[i] = (double complex *)malloc(xsize * sizeof(double complex));
    }
    for (int i = 0; i < xsize; i++) {
        for (int j = 0; j < ysize; j++) {
            arr[j][i] = matrix[i][j];
        }
    }

    /*
    int temp = *n1;
    *n1 = *m1;
    *m1 = temp;
    */

    return arr;
}