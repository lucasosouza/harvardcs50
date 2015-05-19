#include <stdio.h>
#include <ctype.h>

int main(void)
{
    //get input
    printf("Insert height:");
    int height;
    char input[20];
    fgets(input, 20, stdin);
    //changes to satisfy test parameters
    if (!isdigit(input[0])) {
        printf("Only numbers are accepted\n");
        return -1;        
    } else {
        sscanf(input, "%d", &height);
        while (height < 0 || height > 23) {
            printf("Minimum height is 0 and maximum is 23. Insert height:");
            fgets(input, 20, stdin);
            sscanf(input, "%d", &height);
        }
    }
    
    //print pyramid 
    int i; int s; int h;
    for(i=1;i<=height;i++){
        for(s=1;s<=(height-i);s++){
            printf(" ");
        }
        for(h=1;h<=i;h++) {
            printf("#");
        }
        printf("  ");
        for(h=1;h<=i;h++) {
            printf("#");
        }
        printf("\n");
    }
}
