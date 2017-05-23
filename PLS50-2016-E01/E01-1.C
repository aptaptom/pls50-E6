/* PLS50 2016-17 E01 - 1 */
/* ANTONIOS TOMAZOS */
/* Calculator */

#include <stdio.h>
#include <stdlib.h>

main() {
  float num1=0.0, num2=0.0, res=0.0;
  int devzero=0, wrongop=0;
  char op=' ';

  printf("\nType Number Operation Number:\n");
  scanf("%f %c %f",&num1, &op, &num2);

  if (op=='+')
    res = num1+num2;
  else if (op=='-')
    res = num1-num2;
  else if (op=='*')
    res = num1*num2;
  else if (op=='/') {
    devzero = num2 == 0.0;
    if (!devzero) res = num1/num2;
  }
  else
    wrongop=1;

  if (wrongop) printf("\nWrong Operator!\n");
    else if (devzero) printf("\nDivision by Zero!\n");
      else
	printf("Result = %f", res);
}
