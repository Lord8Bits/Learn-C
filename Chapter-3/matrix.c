#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

// Created by lorend on 10/21/25.

int main(void)
{
    int dimension;
    while (true)
    {
        printf("Entrer l'ordre de la matrice (1-4): ");
        scanf("%d", &dimension);
        if (dimension > 0 && dimension < 5) break;
    }

    int n_coef = dimension*dimension; // The total number of coefficients

    float matrix[n_coef]; // The matrix studied
    float value = 0.0f; // Placeholder variable

    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            printf("Entrer la valeur de a_%d,%d: ", i+1, j+1); // i + 1 and j + 1 only to represent coefficients
            scanf("%f", &value);

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
     * dimension value (since lower triangular has no zeros in the first row) until the n_coef - dimension
     * (for example for dim = 3, we would stop until 9-3 = 6 else we are out of bound).
     * Index i will serve to select the coefficient in a row, and required_0s is the number of 0s that should be in a row.
     * If at least one of them is not 0 the loop will stop and isTriangular_lower will be set to false.
     */
    bool is_triangular_lower = true;
    int required_0s = 1;

    for (int selected_row = dimension ; selected_row <= n_coef - dimension ; selected_row += dimension)
    {
        for (int i = 0; i < required_0s; i++)
        {
            if (matrix[i+selected_row]) // if we have row 2 = [0,2,9,10] | i = 0 -> matrix[0 + dimension] = matrix[0 + 4] = 0, so if (0) is false
            {
                is_triangular_lower = false;
                break; // if the coefficient isn't 0 then break
            }
        }
        required_0s++; // each row would need +1 zero, row 1 need none, row 2 needs 1 zero, row 3 needs 2 zeros and so on
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

    for (int r = 0 ; r < n_coef - dimension ; r += dimension)
    {
        for (int i = 1 + next; i <= required_0s; i++)
        {
            if (matrix[i + r + next])
            {
                is_triangular_upper = false;
                break; // if the coefficient isn't 0 then break
            }
        }
        required_0s--;
        next++;
    }

    if (is_triangular_upper && is_triangular_lower) printf("The square matrix is diagonal hence symmetrical.");
    else if (is_triangular_upper) printf("The square matrix is an upper triangular.");
    else if (is_triangular_lower) printf("The square matrix is a lower triangular.");
    else
    {
        bool is_symmetrical = true;

        for (int r = 0; r < dimension && is_symmetrical; r++)
            for (int c = 0; c < dimension; c++)
            {
                if (matrix[r * dimension + c] != matrix[c * dimension + r])
                // following the definition of symmetrical: M[i,j] == M[j,i]
                {
                    is_symmetrical = false;
                    break;
                }
            }


        if (is_symmetrical) printf("The matrix is symmetrical.\n");
        else printf("The matrix isn't triangular nor is it symmetrical.");

    }
    // clock_t end = clock();
    // double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    // printf("Elapsed time: %.6f seconds\n", elapsed);

    return EXIT_SUCCESS;
}

