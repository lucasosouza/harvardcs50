#include <stdio.h>
#include <ctype.h>

int main(void)
{
    //get input from user
    printf("Input a credit card to number to be validated\n");    
    char input[16];
    fgets(input, 20, stdin);
    
    while(!isdigit(input[0])) {
        printf("Please insert numbers only\n");
        fgets(input, 20, stdin);
    }
        
    //count valid chars (amex only has 15 chars)
    int inputSize = 0;
    int i; int n;
    for(i=0;i<20;i++) {
        n = input[i] - '0';
        if (n >= 0 && n <= 9) {
            inputSize++;
        }
    }

    //reverse the string
    char output[inputSize];
    for (i=0;i<inputSize;i++) {
        output[i] = input[inputSize - i -1];    
    }
        
    //calculate the total for odds
    //get a string with all the evens
    char totalEvenStr[inputSize];
    int totalOdd = 0;
    int c = 0;
    for (i=0;i<inputSize;i++) {
        n = output[i] - '0';
        if ((i+1)%2==0) {
            int even = (n*2);
            char evenStr[2];
            sprintf(evenStr, "%d", even);
            int j;
            for(j=0;j<2;j++) {
                totalEvenStr[c] = evenStr[j];
                c++;
            }
        } else {
            totalOdd += n;
        }
    }
    
    //calculate the total for evens
    int totalEven = 0;
    for (i=0;i<inputSize;i++){
        n = totalEvenStr[i] - '0';
        if (n>0 && n<=9) {
            totalEven += n;
        }
    }
    
    //reply if is valid and which flag it belongs to
    if ((totalEven + totalOdd)%10==0){
        int fn = input[0] - '0';
        int sn = input[1] - '0';
        if (fn==3 && (sn==4||sn==7)){
            printf("AMEX\n");
        } else if (fn==5 && (sn==1||sn==2||sn==3||sn==4||sn==5)) {
            printf("MASTERCARD\n");
        } else if (fn==4) {
            printf("VISA\n");
        } else {
            printf("UNKNOWN\n");
        }
    } else {
        printf("INVALID\n");
    }  
        
    //end main function
    return 0;
}

//Algorithm:
//multiply every other digit by 2, starting with second-to-last digiter, and then add them together
//add this to the sum of digits that were  not multiplied by 2
//if divisible by 10 the number is valid
