#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch;
    char str[100];
    char sen[100];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    scanf(" %c", &ch); 
    scanf(" %s", &str); 
    scanf(" %[^\n]%*c", &sen); 
    printf("%c\n", ch);
    printf("%s\n", str);
    printf("%s\n", sen);  
    return 0;
}
