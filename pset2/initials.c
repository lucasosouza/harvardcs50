#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void printInitials(char* s, int length);
char toUpperCase(char c);

int main(void)
{
    //printf("What's your name?\n");
    char name[100];
    fgets(name, 100, stdin);

    printInitials(name, 100);
    return 0;
}

void printInitials(char* s, int length)
{
    int i;
    int nChar;
    bool initial = true;
    for(i=0;i<=length;i++){
        if (initial) 
        {
            printf("%c", toUpperCase(s[i]));
            initial = false;
        }
        nChar = s[i]; 
        if (nChar == 32)
        { 
            initial = true;
        }
        if (nChar == 10) {
            break;
        } 
    }
    printf("\n");   
}

char toUpperCase(char c)
{
    int nc = c; int nc2upper;
    if (nc >= 97 && nc <= 122) {
        nc2upper = nc-32;    
        char c2upper = nc2upper;
        return c2upper;   
    }
    return c;   
}

//prompt user for username
//outputs their initials in uppercase with no space or periods
//Lucas Oliveira Souza - LOS


