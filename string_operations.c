#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';


    char concat[200];
    strcpy(concat, str1);
    strcat(concat, str2);
    printf("Concatenated string: %s\n", concat);


    char copy[100];
    strcpy(copy, str1);
    printf("Copied string: %s\n", copy);

    int compare = strcmp(str1, str2);
    if (compare == 0) {
        printf("The strings are equal.\n");
    } else if (compare < 0) {
        printf("%s comes before %s.\n", str1, str2);
    } else {
        printf("%s comes after %s.\n", str1, str2);
    }

    return 0;
}

