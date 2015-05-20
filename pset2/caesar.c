#include <stdio.h>
#include <stdlib.h>

void decode(char* text, int key);

int main(int argc, char* argv[])
{
    int key;
    if (argc == 2) {
        key = atoi(argv[1]);
    } else {
        key = 0;
    }
    if (key < 1){
        printf("You should enter a valid positive integer as argument\n");
        return 1;
    }
    char text[256];
    fgets(text, 256, stdin);
    decode(text, key);
    return 0;
}

void decode(char* text, int key)
{
    int k = key % 26;
    int i; int nChar;
    int offset; int upperBound; int lowerBound;
    for(i=0;i<256;i++){
        nChar = text[i];
        //break when it hits new line
        if(nChar == 10) {
            break; 
        }
        //defines condition for uppercase, lowercase and others
        if(nChar >= 97 && nChar <= 122){
            lowerBound = 97; upperBound = 122;
        } else if(nChar >= 65 && nChar <= 90){
            lowerBound = 65; upperBound = 90;
        } else {
            upperBound = 0;
        }  
        //prints the corresponding char      
        if(upperBound){
            offset = k - (upperBound-nChar);  
            if (offset > 0) {
                printf("%c", (lowerBound-1+offset));
            } else {
                printf("%c", (nChar+k));
            }             
        } else {
            printf("%c",nChar);
        }
    }
    printf("\n");
}



