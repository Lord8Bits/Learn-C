#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ARRAY_SIZE 10000

int main(void)
{
    int size;
    while (true)
    {
        printf("Enter the size of the array: ");
        if (scanf("%d", &size) != 1) {
            fprintf(stderr, "Error: Invalid input\n");
            return EXIT_FAILURE;
        }
        if (size > 0 && size <= MAX_ARRAY_SIZE) break;
        printf("Error: Array size must be between 1 and %d\n", MAX_ARRAY_SIZE);
    }

    int array[size], value, positive = 0;

    for (int i = 0; i < size; i++)
    {
        printf("\nEnter the value in the array: ");
        if (scanf("%d", &value) != 1) {
            fprintf(stderr, "Error: Invalid input for array element\n");
            return EXIT_FAILURE;
        }
        /*
         * This is the positive value logic, it will push the number in the far right to the left
         * with every preceding numbers, then replacing the last index with the new value.
         * this is by taking the number of positive values which will be incremented for every new one,
         * and starting at the index of the last empty slot (from left to right) equal to (size - 1) - positive
         * and replace it with the next index's value.
         * for example: int array[5] = [ , , , 6, 10] there are 2 positives so we will start at (5-1) - 2 = 2
         * then replace: array[2] = array[2 + 1] ---> array[2] = 3 and go on until array[size - 1] --> array[4]
         * which will be replaced with the new value.
         */
        if (value >= 0)
        {
            for (int j = positive; j >= 0; j--)
            {
                if (j == 0)
                {
                    array[size - 1] = value;
                    positive++;
                }
                else
                {
                    array[size - 1 - j] = array[size - 1 - j + 1];
                }
            }
        }
        // This will add negative value to the next empty slot in the left side
        else
        {
            array[i-positive] = value;
        }
    }

    printf("\n[");
    for (int i = 0; i < size-1; i++)
    {
        printf("%d, ", array[i]);
    }

    printf("%d]\n", array[size-1]);

    return EXIT_SUCCESS;
}