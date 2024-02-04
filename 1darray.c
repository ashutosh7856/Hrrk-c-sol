#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

   int n;
scanf("%d", &n);
int sum = 0;
int elements;
int *arr = (int*)malloc(n * sizeof(int));
for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
    sum=sum + arr[i]; 
}
printf("%d", sum);

free(arr);

return 0;
}
