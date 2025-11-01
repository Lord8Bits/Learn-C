#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int size, number; // Declaring the size of the array and the number to be added
    printf("Enter the size of the array: ");
    scanf("%d", &size); // size received from console input

    int array[size];

    for (int i = 0; i < size; i++) // Loop reads user input until the last index and adds each number to the array
    {
        scanf("%d", &number);
        array[i] = number;
    }

    int non_zero = size - 1; // This will serve as history for the last index that isn't 0
    while (!array[non_zero] && non_zero > 0) non_zero--; // [2,1,0,0,0,0] so non_zero is index 1


    /*
     * Starts by taking the index i of the array starting from 0 to the index before the last non_zero.
     * Then checks if array[i] == 0. If so, it will replace it with the non_zero index value and decrement non_zero and i.
     * Then the second loop will take the index j from 0 to the last non_zero,
     * compare array[i] to array[j], and if equal, it will switch the value at index j with the value at index non_zero,
     * and array[non_zero] will get replaced with the value 0, and we decrement non_zero by one as well as i to recheck the new value.
     * The result would be an array without duplicates with 0s all placed at the end of the array.
     */
    for (int i = 0; i < non_zero; i++)
    {
        if (array[i] == 0) // For edge cases like [5,2,1,5,0]
        {
            array[i] = array[non_zero];
            array[non_zero] = 0;
            non_zero--;
            i--; // Recheck the new value
        }
        else
        {
            for (int j = i + 1; j <= non_zero ; j++)
            {
                if (array[i] == array[j])
                {
                    array[j] = array[non_zero];
                    array[non_zero] = 0;
                    non_zero--;
                    j--; // Recheck the new value
                }
            }
        }
    }
    // This section simply prints the size and the array without zeros, also prints the full array for debugging.
    printf("Size: %d\n\n", size);

    printf("Array: [");

    if (size && array[0])
    {
        printf("%d", array[0]);
        for (int i = 1; i <= non_zero; i++)
        {
            if (array[i])
            {
                printf(",%d", array[i]);
            }
        }

    }
    printf("]\n\n");

    printf("True Array: [");
    for (int i = 0; i < size-1; i++)
    {
        printf("%d,", array[i]);
    }
    printf("%d]", array[size-1]);


    return EXIT_SUCCESS;
}