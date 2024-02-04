#include<stdio.h>
int main(){
    

int ne;
    scanf("%d",&ne);
    char *words[]={"one","two","three","four","five","six","seven","eight","nine","ten"};
    if (ne>9){
        printf("Greater than 9");
    }
     else
     printf("%s\n",words[ne-1]);

    return 0;
}

