#pragma once
#include "function.h"

int menu() {
    while (1) {
        printf("\nChoose a test to run:\n");
        printf("1. Test plus_matrix\n");
        printf("2. Test mult_matrix\n");
        printf("3. Test trans_matrix\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        int choice = getint();

        switch (choice) {
            case 1:
                test_plus_matrix();
                break;
            case 2:
                test_mult_matrix();
                break;
            case 3:
                test_trans_matrix();
                break;
            case 0:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void test_plus_matrix() {
    printf("Testing plus_matrix\n");

    int xsize = 2, ysize = 2;
    double complex **matrix1 = (double complex **)malloc(xsize * sizeof(double complex *));
    double complex **matrix2 = (double complex **)malloc(xsize * sizeof(double complex *));
    for (int i = 0; i < xsize; i++) {
        matrix1[i] = (double complex *)malloc(ysize * sizeof(double complex));
        matrix2[i] = (double complex *)malloc(ysize * sizeof(double complex));
    }

    matrix1[0][0] = 1 + 2*I; matrix1[0][1] = 3 + 4*I;
    matrix1[1][0] = 5 + 6*I; matrix1[1][1] = 7 + 8*I;

    matrix2[0][0] = 1 + 1*I; matrix2[0][1] = 1 + 1*I;
    matrix2[1][0] = 1 + 1*I; matrix2[1][1] = 1 + 1*I;

    double complex **result = plus_matrix(xsize, ysize, matrix1, xsize, ysize, matrix2);

    printf("Expected result:\n");
    printf("2.00 + 3.00i 4.00 + 5.00i\n");
    printf("6.00 + 7.00i 8.00 + 9.00i\n");

    printf("Actual result:\n");
    print_matrix(xsize, ysize, result);

    clear_memory(xsize, matrix1);
    clear_memory(xsize, matrix2);
    clear_memory(xsize, result);
}

void test_mult_matrix() {
    printf("Testing mult_matrix\n");

    int xsize = 2, ysize = 2, xsize1 = 2, ysize1 = 2;
    double complex **matrix1 = (double complex **)malloc(xsize * sizeof(double complex *));
    double complex **matrix2 = (double complex **)malloc(xsize1 * sizeof(double complex *));
    for (int i = 0; i < xsize; i++) {
        matrix1[i] = (double complex *)malloc(ysize * sizeof(double complex));
    }
    for (int i = 0; i < xsize1; i++) {
        matrix2[i] = (double complex *)malloc(ysize1 * sizeof(double complex));
    }

    matrix1[0][0] = 1 + 2*I; matrix1[0][1] = 3 + 4*I;
    matrix1[1][0] = 5 + 6*I; matrix1[1][1] = 7 + 8*I;

    matrix2[0][0] = 1 + 1*I; matrix2[0][1] = 1 + 1*I;
    matrix2[1][0] = 1 + 1*I; matrix2[1][1] = 1 + 1*I;

    double complex **result = mult_matrix(xsize, ysize, matrix1, xsize1, ysize1, matrix2);

    printf("Expected result:\n");
    printf("-2.00 + 8.00i -2.00 + 8.00i\n");
    printf("-2.00 + 20.00i -2.00 + 20.00i\n");

    printf("Actual result:\n");
    print_matrix(xsize, ysize1, result);

    clear_memory(xsize, matrix1);
    clear_memory(xsize1, matrix2);
    clear_memory(xsize, result);
}

void test_trans_matrix() {
    printf("Testing trans_matrix\n");

    int xsize = 2, ysize = 3;
    double complex **matrix = (double complex **)malloc(xsize * sizeof(double complex *));
    for (int i = 0; i < xsize; i++) {
        matrix[i] = (double complex *)malloc(ysize * sizeof(double complex));
    }

    matrix[0][0] = 1 + 2*I; matrix[0][1] = 3 + 4*I; matrix[0][2] = 5 + 6*I;
    matrix[1][0] = 7 + 8*I; matrix[1][1] = 9 + 10*I; matrix[1][2] = 11 + 12*I;

    double complex **result = trans_matrix(xsize, ysize, matrix);

    printf("Expected result:\n");
    printf("1.00 + 2.00i 7.00 + 8.00i\n");
    printf("3.00 + 4.00i 9.00 + 10.00i\n");
    printf("5.00 + 6.00i 11.00 + 12.00i\n");

    printf("Actual result:\n");
    print_matrix(ysize, xsize, result);

    clear_memory(xsize, matrix);
    clear_memory(ysize, result);
}