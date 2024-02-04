#include <stdio.h>

void update(int *x,int *y) {
    // Complete this function    
    int temp = *x;
    *x=*x+*y;
    if (temp>*y){
        *y=temp-*y;
    }else{
        *y=*y-temp;
    }
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n""%d", a , b);
    return 0;
}
