#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
  	for (int i = -1 * n + 1; i <= n - 1; i++) {
        int count = n - (abs(i) + 1);
        int count_check = 0;
        int temp = n;
        for (int j = -1 * n + 1; j <= n - 1; j++) {
            printf("%d ", temp);
            if (count != count_check) {
                temp --;
                count_check++;
            } else if (temp < n && j >= n - 1 - count_check) {
                temp++;
            }
        }
        printf("\n");
      }
      return 0;
}
