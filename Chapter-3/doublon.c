//
// Created by lorend on 10/22/25.
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Creer un code qui nous laisse specifier la taille de la liste:
    int taille = 0;
    printf("Entrer la taille de la liste: ");
    scanf("%d", &taille);

    int array[taille];

    for (int i = 0; i < taille; i++)
    {
        printf("Entrer la valeur dans l'indexe %d: ", i);
        scanf("%d", &array[i]);
    }


    for (int i = 0; i < taille-1; i++) // i --> 4 , taille = 5
    {
        for (int j = i+1; j < taille; j++)
        {
            if (array[i] == array[j])
            {
                array[i] = 0;
            }
        }
    }
    for (int i = 0; i < taille; i++)
    {
        printf(" %d ", array[i]);
    }
    printf("\n");


    // array= [4,0,0,0]
    bool swap = false;
    for (int i = 0; i < taille; i++) // i= 0 --> array[0] = 4 | i = 1 --> array[1] = 0
    {
        if (array[i] == 0) // array[0]= 4 != 0 | array[1] = 0
        {
            for (int j = taille-1; j > i; j--) // array[3] = 0 | array[2] = 0 | i = 1 > 1 = j
            {
                if (array[j] != 0) // array[3] = 0 --> False | array[2] = 0 --> False
                {
                    array[i] = array[j]; // array[i] = 0, array[j] = 3 ---> array[i] = 3, array[j] = 0
                    array[j] = 0;
                    swap = true;
                    break;
                }
            }

            if (!swap) break; // swap = false --> not swap => not False = True
        }
    }

    for (int i = 0; i < taille; i++)
    {
        printf(" %d ", array[i]);
    }


    return EXIT_SUCCESS;
}
