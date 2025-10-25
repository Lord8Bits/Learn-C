//
// Created by lorend on 10/19/25.
//
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14f

int main(void)
{
    int radius;

    printf("Enter the radius of the sphere: ");
    if (scanf("%d", &radius) != 1) {
        fprintf(stderr, "Error: Invalid input\n");
        return EXIT_FAILURE;
    }

    float volume = 4.0f/3.0f * PI * radius * radius * radius;

    printf("The volume is equal to: %.5f\n", volume);

    return EXIT_SUCCESS;
}