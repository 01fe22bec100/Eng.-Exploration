#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isPalindrome(const char *str) {
    int len=strlen(str);
    for (int i=0;i<len/2;i++) {
        if (tolower(str[i])!=tolower(str[len-i-1])) {
            return 0;
        }
    }
    return 1;
}
int main() {
    char input[100];
    printf("Enter a string or number to check if it's a palindrome: ");
    fgets(input, sizeof(input),stdin);
    input[strcspn(input,"\n")]='\0';
    if (isPalindrome(input)) {
        printf("%s is a palindrome.\n",input);
    } else {
        printf("%s is not a palindrome.\n",input);
    }
    return 0;
}

