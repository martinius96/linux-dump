#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>
int main()  
{  
    long decimal, tempDecimal;  
    char binary[65];  
    int index = 0;  

    /* 
     * Reads decimal number from user 
     */  
    printf("Enter any decimal value : ");  
    scanf("%ld", &decimal);  

    /* Copies decimal value to temp variable */  
    tempDecimal = decimal;  

    while(tempDecimal!=0)  
    {  
        /* Finds decimal%2 and adds to the binary value */  
        binary[index] = (tempDecimal % 2) + '0';  

        tempDecimal /= 2;  
        index++;  
    }  
    binary[index] = '\0';  

    /* Reverse the binary value found */  
    strrev(binary);  

    printf("\nDecimal value = %ld\n", decimal);  
    printf("Binary value of decimal = %s", binary);  

    return 0;  
} 
