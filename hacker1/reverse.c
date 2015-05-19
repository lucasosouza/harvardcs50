#include <stdio.h>

int main(void)
{
    char input[] = "5491670349000161";
    size_t inputSize = sizeof(input);
    char output[inputSize];
    int i;
    for (i=1;i<=inputSize;i++) {
        output[i] = input[inputSize - i];    
    }
    size_t outputSize = sizeof(output);
    for (i=1;i<=outputSize;i++) {
        printf("%c",output[i]);
    }
    printf("\n");
    return 0;
}


