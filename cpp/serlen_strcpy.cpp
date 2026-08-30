#include <stdio.h>
#include <string.h>

// Implement strlen() 
namespace myFuns {
    int strlen(char* str) {
        int len = 0;
        while(*str != '\0') {
            len++;
            str++;
        }
        return len;
    }

    char* strcpy(char* dest, char* src) {
        char* cpy = dest;
        while(*src!='\0') {
            *dest++ = *src++;
        }
        return cpy;
    }
}

int main() {
    char str[] = "My name is Arnav";
    printf("New len of str: %d\n", myFuns::strlen(str));

    char str2[20];
    myFuns::strcpy(str2, str);
    printf("Copied string: %s\n", str2);

    return 0;
}