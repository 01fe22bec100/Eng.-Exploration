#include <stdio.h>
void generateFibonacci(int limit) {
    int num1=0,num2=1,nextT;
    printf("Fibonacci Series up to %d terms:\n", limit);

for (int i=1; i<=limit;i++) {
        printf("%d, ",num1);
        nextT = num1 + num2;
        num1 = num2;
        num2 = nextT;
    }
    printf("\n");
}

int main() {
    int limit;
    printf("Enter the limit for Fibonacci series: ");
    scanf("%d",&limit);
    generateFibonacci(limit);
    return 0;
}
