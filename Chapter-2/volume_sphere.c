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
    scanf("%d", &radius);

    float volume = 4.0f/3.0f * PI * radius * radius * radius;

    printf("The volume is equal to: %.5f", volume);

    return EXIT_SUCCESS;
}