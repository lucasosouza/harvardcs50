#include <stdio.h>
#include <stdlib.h>

void decode(char* text, char* key);
char toUpperCase(char c);

int main(int argc, char* argv[])
{
    //exit if argc != 2 or contains any non-alphabetic char
    if (argc != 2){
        printf("You should enter a valid string as an argument\n");
        return 1;
    }
    char* key = argv[1];
    int i; int n;
    //added: breaks if there is a non-char
    for(i=0;i<255;i++){
        n = key[i];
        if (n==0) { break; }
        if (!((n>=97 && n<=122)||(n>=65 && n<=90))) {
            printf("You should enter a valid string as an argument\n");
            return 1;
        }
    }
    //
    char text[256];
    fgets(text, 256, stdin);
    decode(text, key);
    return 0;
}

void decode(char* text, char* key)
{
    int i; int nChar; int k;
    int offset; int upperBound; int lowerBound;
    int nKeyChar; char keyChar;
    int keyLength = 0;
    int notLetter = 0; 
    //get length of key
    for(i=0;i<=255;i++){
        nChar = key[i];
        if (nChar == 0) {
            keyLength = i;
            break;
        }
    }
    //cypher algorithm
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
            notLetter++;
        }        
        //decide what k is on case by case basis
        keyChar = key[(i-notLetter) % keyLength];
        nKeyChar = toUpperCase(keyChar);
        k = nKeyChar - 65;
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


