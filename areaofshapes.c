#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

float rectangleArea(float length, float width) {
    return length*width;
}

float triangleArea(float base, float height) {
    return 0.5*base*height;
}

float circleArea(float radius) {
    return PI*radius*radius;
}
int main() {
    int choice;
    float length, width, base, height, radius;
    printf("Choose a shape to calculate its area:\n");
    printf("1. Rectangle\n");
    printf("2. Triangle\n");
    printf("3. Circle\n");
    printf("Enter your choice (1, 2, or 3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter length and width of the rectangle: ");
            scanf("%f %f", &length, &width);
            printf("Area of rectangle: %.2f\n", rectangleArea(length, width));
            break;
        case 2:
            printf("Enter base and height of the triangle: ");
            scanf("%f %f", &base, &height);
            printf("Area of triangle: %.2f\n", triangleArea(base, height));
            break;
        case 3:
            printf("Enter radius of the circle: ");
            scanf("%f", &radius);
            printf("Area of circle: %.2f\n", circleArea(radius));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}

