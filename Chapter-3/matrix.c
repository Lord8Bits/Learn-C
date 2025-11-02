#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

// Created by lorend on 10/21/25.
#define M(r,c) (matrix[(r)*dimension + (c)]) // matrix row to column selection

int main(void)
{
    int dimension = 0;
    do
    {
        printf("Entrer l'ordre de la matrice (1-4): ");
        scanf("%d", &dimension);
    }
    while (dimension <= 0 || dimension >= 5);

    int n_coef = dimension*dimension; // The total number of coefficients

    float matrix[n_coef]; // The matrix studied
    float value = 0.0f; // Placeholder variable

    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            printf("Entrer la valeur de a_%d,%d: ", i+1, j+1); // i + 1 and j + 1 only to represent coefficients
            scanf("%f", &value);

            M(i,j) = value; // Adds new values for the selected row
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
            printf("  %+12.2f  ",  M(i,j) );
        }
        printf("\n");
    }

    // Lower Triangular:
    /*
     * Checks numbers over the diagonal by starting from r = 0 to r = dimension - 2, and c = r+1 till c = dimension - 1.
     * Example:
     * for the row = 0 we have [2,0,0,0] so c = 0 + 1 --> M(0,1) == 0 --> M(0,2) == 0 --> M(0,3) == 0 --> c = 4 < 4 is False
     * Then we check the rest of the rows except the last since there's no number over the diagonal.
     */
    bool is_triangular_lower = true;

    for (int r = 0 ; r < dimension - 1 && is_triangular_lower; r++)
    {
        for (int c = r+1; c < dimension; c++)
        {
            if (M(r,c) != 0.0f)
            {
                is_triangular_lower = false;
                break;
            }
        }
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

    for (int r = dimension - 1; r > 0 && is_triangular_upper; r--)
    {
        for (int c = 0; c < r; c++)
        {
            if (M(r,c) != 0.0f)
            {
                is_triangular_upper = false;
                break;
            }
        }
    }


    if (is_triangular_upper && is_triangular_lower) printf("The square matrix is diagonal hence symmetrical.");
    else if (is_triangular_upper) printf("The square matrix is an upper triangular.");
    else if (is_triangular_lower) printf("The square matrix is a lower triangular.");
    else
    {
        bool is_symmetrical = true;

        for (int r = 0; r < dimension && is_symmetrical; r++)
        {
            for (int c = 0; c < dimension; c++)
            {
                if (M(r,c) != M(c,r))
                    // following the definition of symmetrical: M[i,j] == M[j,i]
                {
                    is_symmetrical = false;
                    break;
                }
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

