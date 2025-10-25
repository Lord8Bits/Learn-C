#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <time.h>

// Created by lorend on 10/21/25.

#define MAX_MATRIX_DIMENSION 100

int main(void)
{
    int dimension;
    while (true)
    {
        printf("Entrer l'ordre de la matrice (1-4): ");
        if (scanf("%d", &dimension) != 1) {
            fprintf(stderr, "Error: Invalid input\n");
            return EXIT_FAILURE;
        }
        if (dimension > 0 && dimension <= MAX_MATRIX_DIMENSION) break;
        printf("Error: Matrix dimension must be between 1 and %d\n", MAX_MATRIX_DIMENSION);
    }

    int n_coef = dimension*dimension; // The total number of coefficients

    float matrix[n_coef]; // The matrix studied
    float value = 0.0f; // Placeholder variable

    for (int i = 0; i < dimension; i++) // i and j starts from 1 only for a nicer print in the console
    {
        for (int j = 0; j < dimension; j++)
        {
            printf("Entrer la valeur de a_%d,%d: ", i+1, j+1);
            if (scanf("%f", &value) != 1) {
                fprintf(stderr, "Error: Invalid input for matrix element\n");
                return EXIT_FAILURE;
            }

            matrix[i * dimension + j] = value; // Adds new values for the selected row
        }

    }

    // for (int i = 0; i < dimension; i++)
    //     for (int j = 0; j < dimension; j++)
    //         matrix[i*dimension + j] = (i <= j) ? i + j : j + i;
    //
    // clock_t start = clock();


    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            printf("  %+12.2f  ",  matrix[i * dimension + j] );
        }
        printf("\n");
    }

    // Lower Triangular:
    /*
     * Takes the matrix and separates it into different rows by creating the selected_row variable that start in the
     * dimension value until the n_coef - dimension (for example for dim = 3, we would stop until 9-3 = 6 else we are out of bound).
     * Index i will serve to select the coefficient in a row, and required_0s is the number of 0s that should be in a row.
     * If at least one of them is not 0 the loop will stop and isTriangular_lower will be set to false.
     */
    bool is_triangular_lower = true;
    int required_0s = 1;

    for (int selected_row = dimension ; selected_row <= n_coef - dimension ; selected_row += dimension)
    {
        for (int i = 0; i < required_0s; i++)
        {
            if (matrix[i+selected_row])
            {
                is_triangular_lower = false;
                break; // if the coefficient isn't 0 then break
            }
        }
        required_0s++;
    }

    // Upper Triangular:
    /*
     * Takes the matrix and separates it into different rows by creating the selected_row variable that start in 0
     * until the n_coef - dimension * 2 (for example for dim = 3, we would stop until 9-6 = 3 since there is no need to check the last row).
     * Index i will serve to select the coefficient in a row starting from the second coefficient,
     * and required_0s is the number of 0s that should be in a row. And the 'next' variable serves to skip unnecessary values.
     * If at least one of them is not 0 the loop will stop and isTriangular_upper will be set to false.
     */
    bool is_triangular_upper = true;
    required_0s = dimension-1;
    int next = 0;

    for (int selected_row = 0 ; selected_row < n_coef - dimension ; selected_row += dimension)
    {
        for (int i = 1 + next; i <= required_0s; i++)
        {
            if (matrix[i + selected_row + next])
            {
                is_triangular_upper = false;
                break; // if the coefficient isn't 0 then break
            }
        }
        required_0s--;
        next++;
    }

    if (is_triangular_upper && is_triangular_lower) printf("The square matrix is diagonal and symmetrical.");
    else if (is_triangular_upper) printf("The square matrix is an upper triangular.");
    else if (is_triangular_lower) printf("The square matrix is a lower triangular.");
    else
    {
        bool is_symmetrical = true;
        float matrix_t[n_coef]; // Transposed Matrix
        int t_j = 0; //

        for (int selected_row = 0; selected_row <= n_coef - dimension; selected_row += dimension)
        {
            int t_col = 0;  // Transpose col
            for (int i = 0; i < dimension; i++)
            {
                matrix_t[t_j+t_col] = matrix[i+selected_row];
                t_col += dimension;
            }
            t_j++;
        }

        /*
         * This final loop will simply check whether the matrices are equal by taking the float values and
         * calculate their absolute difference.
         * The difference will have a precision of epsilon = 1e-6
         */
        bool equal = true;
        for (int i = 0; i < n_coef; i++)
        {
            float diff = matrix_t[i] - matrix[i];
            if (diff < 0) diff *= -1;

            if (diff > 1e-6f)
            {
                equal = false;
                break;
            }
        }

        if (equal) printf("The matrix is symmetrical.\n");
        else printf("The matrix isn't triangular nor is it symmetrical.");

    }
    // clock_t end = clock();
    // double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    // printf("Elapsed time: %.6f seconds\n", elapsed);

    return EXIT_SUCCESS;
}

