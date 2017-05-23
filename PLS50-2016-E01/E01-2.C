/* PLS50 2016-17 E01 - 2 */ 
/* ANTONIOS TOMAZOS */
/* Perimeter Calculation */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415927

/* Perimeter of Rectangular */

float prect(a)
float a; {
  return (4.0*a);
}

/* Perimeter of Parallelogram */

float pparal(a, b)
float a, b; {
  return (2.0*(a+b));
}

/* Perimeter of Right Triangle */

float ptrian(a, b)
float a, b; {
  return (a+b+sqrt(a*a+b*b));
}

/* Perimeter of Cirlce */

float pcirc(r)
float r; {
  return (2.0*PI*r);
}

main() {
  float a=0.0, b=0.0, r=0.0, perim=0.0;
  char choice=' ';

  while (choice != '0') {
    printf("\nPerimeter Calculation\n");
    printf("---------------------\n");
    printf("0. Exit\n");
    printf("1. Rectangle\n");
    printf("2. Parallelogram\n");
    printf("3. Right Triangle\n");
    printf("4. Circle\n");
    printf("Please select:");
    scanf(" %c",&choice);
    if (choice == '1') {
      printf("\nLength A = ");
      scanf(" %f", &a);
      perim=prect(a);
      printf("Perimeter of Rectangle = %f\n", perim);
    }
    else if (choice == '2') {
      printf("\nLength A Width B = ");
      scanf(" %f %f", &a, &b);
      perim=pparal(a, b);
      printf("Perimeter of Parallelogram = %f\n", perim);
    }
    else if (choice == '3') {
      printf("\nEdge A Edge B = ");
      scanf(" %f %f", &a, &b);
      perim=ptrian(a, b);
      printf("Perimeter of Right Triangle = %f\n", perim);
    }
    else if (choice == '4') {
      printf("\nRadius = ");
      scanf(" %f", &r);
      perim=pcirc(r);
      printf("Perimeter of Circle = %f\n", perim);
    }
    else if (choice != '0')
      printf("Wrong choice!\n");
  }
}
