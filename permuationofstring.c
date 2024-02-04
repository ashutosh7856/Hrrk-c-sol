#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int next_permutation(int n, char **s) {
    int i, j;

    for (i = n - 2; i >= 0; i--) {
        if (strcmp(s[i], s[i + 1]) < 0)
            break;
    }
    if (i < 0)
        return 0;

    for (j = n - 1; j > i; j--) {
        if (strcmp(s[j], s[i]) > 0)
            break;
    }

    swap(&s[i], &s[j]);

    int left = i + 1, right = n - 1;
    while (left < right) {
        swap(&s[left], &s[right]);
        left++;
        right--;
    }

    return 1;
}


