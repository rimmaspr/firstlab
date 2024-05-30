#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "function.h"
#include "tests_first.h"

int main()
{
    printf("Tests\n");
    menu();

    int xsize = 0, ysize = 0;
    double real = 0, imag = 0;
    char line[100];

    printf("\nEnter the whole number of rows in the first matrix:\n");
    xsize = getint();
    printf("Enter the whole number of columns in the first matrix:\n");
    ysize = getint();

    double complex **matrix = (double complex **)malloc(xsize * sizeof(double complex *));
    for (int i = 0; i < xsize; i++) {
        matrix[i] = (double complex *)malloc(ysize * sizeof(double complex));
    }

    printf("Enter the first matrix:\n");

    for (int i = 0; i < xsize; i++) {
        for (int j = 0; j < ysize; j++) {
            // scanf("%[^\n] %lf + %lfi", &real, &imag);
            get_complex(&real, &imag);

            // printf("%.2lf\n", real);
            matrix[i][j] = real + imag * I;
            imag = 0;
        }
    }
    // целое число - imag = 0

    printf("\nThe first matrix:\n");
    print_matrix(xsize, ysize, matrix);

    // вторая матрица
    int xsize1 = 0, ysize1 = 0;
    double real1 = 0, imag1 = 0;

    printf("\nEnter the number of rows in the second matrix:\n");
    xsize1 = getint();
    printf("Enter the number of columns in the second matrix:\n");
    ysize = getint();

    printf("Enter second matrix:\n");
    double complex **matrix1 = (double complex **)malloc(xsize * sizeof(double complex *));
    for (int i = 0; i < xsize1; i++) {
        matrix1[i] = (double complex *)malloc(ysize1 * sizeof(double complex));
    }

    for (int i = 0; i < xsize1; i++) {
        for (int j = 0; j < ysize1; j++) {
            get_complex(&real1, &imag1);

            matrix1[i][j] = real1 + imag1 * I;
            imag1 = 0; // чтобы imag менялся
        }
    }

    printf("\nThe second matrix:\n");
    print_matrix(xsize1, ysize1, matrix1);

    printf("\nThe result of adding two matrices:\n");
    if (xsize == xsize1 && ysize == ysize1) {
        double complex **summa = plus_matrix(xsize, ysize, matrix, xsize1, ysize1, matrix1);
        print_matrix(xsize, ysize, summa);
        clear_memory(xsize, summa); // очистка памяти
    }
    else {
        printf("The sizes of the matrices do not match. Addition is impossible.\n");
    }

    printf("\nThe result of multiplying two matrices:\n");
    if (ysize == xsize1) {
        double complex **comp = mult_matrix(xsize, ysize, matrix, xsize1, ysize1, matrix1);
        print_matrix(xsize, ysize1, comp);
        clear_memory(xsize, comp); // очистка памяти
    }
    else {
        printf("The number of columns in the first matrix is not equal to the number of rows in the second matrix. Multiplication is impossible.\n");
    }

    double complex **trans = trans_matrix(xsize, ysize, matrix);
    printf("\nThe result of transposing the first matrix:\n");
    print_matrix(ysize, xsize, trans);
    clear_memory(ysize, trans); // очистка памяти

    double complex **trans1 = trans_matrix(xsize1, ysize1, matrix1);
    printf("\nThe result of transposing the second matrix:\n");
    print_matrix(ysize1, xsize1, trans1);
    clear_memory(ysize1, trans1); // очистка памяти
    printf("\n");

    clear_memory(xsize, matrix);
    clear_memory(xsize1, matrix1);

    return 0;
}

/*

2 2
1 2 3 4
2 2
4 3 2 1

3 4
3 2 4 1 5 2 1 4 1 3 4 2
4 3
2 4 5 3 2 1 4 3 3 1 5 2

*/
