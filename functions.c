#include <stdio.h>
int max_of_four(int x, int y){
    if (x>y){
        return x;
    }
    else{
          return y;
    }
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int max_1=max_of_four(a, b);
    int max_2=max_of_four(c, d);
    int ans=max_of_four(max_1, max_2);
    printf("%d", ans);
    
    return 0;
}
