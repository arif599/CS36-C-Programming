#include <stdio.h>

int main() {
  int numberOne;
  int numberTwo;

  printf("I'm in course 60845. I've taken: \nJava\n\n");

  printf("Give me a number:");
  scanf("%d", &numberOne);
  printf("Give me a second number:");
  scanf("%d", &numberTwo);
  printf("\n");

  printf("The sum is %d.\n", numberOne + numberTwo);
  printf("The difference is %d.\n", numberOne - numberTwo);    
  printf("The product is %d.\n", numberOne * numberTwo);
  printf("The quotient is %d.\n", numberOne / numberTwo);
  scanf("%d");
}