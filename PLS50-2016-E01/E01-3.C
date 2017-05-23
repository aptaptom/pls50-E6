/* PLS50 2016-17 E01 - 3 */
/* ANTONIOS TOMAZOS */
/* Binary Number */

#include <stdio.h>
#include <stdlib.h>

main() {
  const int divisor=2;
  int number=0, divident=0, quotient=0, modulo=0;
  do {
    printf("\nType a positive integer number: ");
    scanf("%d",&number);
    if (number<0)
      printf("The number is not a positive integer, try again!\n");
    else if (number>0) {
      printf("Binary Number : ");
      divident = number;
      while (divident != 0) {
        quotient = divident / divisor;
        modulo = divident % divisor;
        modulo ? putchar('1') : putchar('0');
        divident = quotient;
      }
      printf("\n");
    }
  }
  while (number!= 0);
}
