#include<stdio.h>
int main(){
  int marks_summation(int* marks, int number_of_students, char gender) {
  int result=0;
  for (int i = 0; i < number_of_students; i++){
      if (gender=='b') if (i%2==0) result+=marks[i];
      if (gender=='g') if (i%2!=0) result+=marks[i];
  }
  return result;
   }
} 

