/* PLS50 2016-17 E01 - 4 */
/* ANTONIOS TOMAZOS */
/* Bus Seats */

#include <stdio.h>
#include <stdlib.h>

#define MAXSEAT 53

FILE* fp;

/* Print Seat Series */

int printseats(s1, s2, s3, s4)
int s1, s2, s3, s4; {
  if (s1 == 0) printf("_");
    else printf("*");
  if (s2 == 0) printf("_");
    else printf("*");
  printf(" ");
  if (s3 == 0) printf("_");
    else printf("*");
  if (s4 == 0) printf("_");
    else printf("*");
  printf("\n");
  return 0;
}

/* File Print Seat Series */

int fprintseats(s1, s2, s3, s4)
int s1, s2, s3, s4; {
  if (s1 == 0) fprintf(fp, "_");
    else fprintf(fp, "*");
  if (s2 == 0) fprintf(fp, "_");
    else fprintf(fp, "*");
  fprintf(fp, " ");
  if (s3 == 0) fprintf(fp, "_");
    else fprintf(fp, "*");
  if (s4 == 0) fprintf(fp, "_");
    else fprintf(fp, "*");
  fprintf(fp, "\n");
  return 0;
}

/* Print Seat Last Series */

int printseatls(s1, s2, s3, s4, s5)
int s1, s2, s3, s4, s5; {
  if (s1 == 0) printf("_");
    else printf("*");
  if (s2 == 0) printf("_");
    else printf("*");
  if (s3 == 0) printf("_");
    else printf("*");
  if (s4 == 0) printf("_");
    else printf("*");
  if (s5 == 0) printf("_");
    else printf("*");
  printf("\n");
  return 0;
}

/* File Print Seat Last Series */

int fprintseatls(s1, s2, s3, s4, s5)
int s1, s2, s3, s4, s5; {
  if (s1 == 0) fprintf(fp, "_");
    else fprintf(fp, "*");
  if (s2 == 0) fprintf(fp, "_");
    else fprintf(fp, "*");
  if (s3 == 0) fprintf(fp, "_");
    else fprintf(fp, "*");
  if (s4 == 0) fprintf(fp, "_");
    else fprintf(fp, "*");
  if (s5 == 0) fprintf(fp, "_");
    else fprintf(fp, "*");
  fprintf(fp, "\n");
  return 0;
}

int main() {
  int numseats=0, numseries=0, i=0, count=0, reserv=0, window=0;
  char platenum[7] = "       ";
  int seat[MAXSEAT+1];
  char choice=' ';

  for (i=0; i<=(MAXSEAT+1); i++) seat[i]=0;

  fp = fopen("bus.txt", "r");
  if (fp==NULL) {
    printf("Error Opening Bus File!\n");
    exit(1);
  }
  fscanf(fp, "%s %d", platenum, &numseats);
  fclose(fp);

  if ((numseats <= 0) || (numseats > MAXSEAT)) {
    printf("Number of seats %d is out of limits!\n", numseats);
    exit(1);
  }

  printf("\nBus Plate Number: %s\n", platenum);
  printf("Number of seats : %d\n", numseats);

  numseries = (numseats-5)/4;

  if (numseries < 0) {
    printf("Invalid number of seats!");
    exit(1);
  }

  if (numseats != (4*numseries+5)) {
    printf("Invalid number of seats!");
    exit(1);
  }

  while (choice != '0') {
    printf("\n");
    printf("---------------------------------------------------------\n");
    printf("1. Print the total number of free seats and their numbers\n");
    printf("2. Reserve seat\n");
    printf("3. Find the first free window seat\n");
    printf("4. Cancel reservation\n");
    printf("5. Check if a seat is reserved\n");
    printf("6. Print reserved seats\n");
    printf("7. Print bus plate number and seat chart\n");
    printf("8. Save bus plate number and seat chart\n");
    printf("0. Exit\n");
    printf("---------------------------------------------------------\n");
    printf("Please select:");
    scanf(" %c",&choice);
    if (choice == '1') {
      printf("\nNumbers of free seats:\n");
      count = 0;
      for (i=1; i<=numseats; i++)
      if (seat[i] == 0) {
        count++;
        printf("%d ", i);
      }
      printf("\nTotal number of free seats: %d\n", count);
    }
    else if (choice == '2') {
      printf("\nEnter seat number: ");
      scanf("%d", &reserv);
      if ((reserv <= 0) || (reserv > numseats))
        printf("Seat number %d is out of limits!\n", reserv);
      else if (seat[reserv] != 0)
        printf("Seat number %d is already reserved!\n", reserv);
      else {
        seat[reserv] = 1;
        printf("Seat number %d is reserved\n", reserv);
      }
    }
    else if (choice == '3') {
      window = 0;
      i = 1;
      while ((window == 0) && (i <= numseries)) {
        if (seat[(i-1)*4+1] == 0) window = (i-1)*4+1;
        else if (seat[(i-1)*4+4] == 0) window = (i-1)*4+4;
        i++;
      }
      if (window == 0) {
        if (seat[numseats-4] == 0) window = numseats-4;
        else if (seat[numseats] == 0) window = numseats;
      }
      if (window == 0)
        printf("There are no free window seats!\n");
      else
       printf("The first free window seat is: %d\n", window);
    }
    else if (choice == '4') {
      printf("\nEnter seat number to cancel reservation: ");
      scanf("%d", &reserv);
      if ((reserv <= 0) || (reserv > numseats))
        printf("Seat number %d is out of limits!\n", reserv);
      else if (seat[reserv] == 0)
        printf("Seat number %d is already free!\n", reserv);
      else {
        seat[reserv] = 0;
        printf("Seat number %d is now free\n", reserv);
      }
    }
    else if (choice == '5') {
      printf("\nEnter seat number: ");
      scanf("%d", &reserv);
      if ((reserv <= 0) || (reserv > numseats))
        printf("Seat number %d is out of limits!\n", reserv);
      else if (seat[reserv] != 0)
        printf("Seat number %d is reserved\n", reserv);
      else
        printf("Seat number %d is not reserved\n", reserv);
    }
    else if (choice == '6') {
      printf("\nReserved seats:\n");
      for (i=1; i<=numseats; i++)
        if (seat[i] != 0) printf("%d ", i);
      printf("\n");
    }
    else if (choice == '7') {
      printf("\nBus plate number and seat chart\n\n");
      printf("%c%c%c%c%c%c%c\n\n", platenum[0], platenum[1], platenum[2],
        platenum[3], platenum[4], platenum[5], platenum[6]);
      for (i=1; i<=numseries; i++)
        printseats(seat[(i-1)*4+1], seat[(i-1)*4+2],
          seat[(i-1)*4+3], seat[(i-1)*4+4]);
      printseatls(seat[numseats-4], seat[numseats-3],
        seat[numseats-2], seat[numseats-1], seat[numseats]);
    }
    else if (choice == '8') {
      fp = fopen("layout.txt", "w");
      if (fp==NULL) {
        printf("Error Creating Layout File!\n");
        exit(1);
      }
      fprintf(fp, "%c%c%c%c%c%c%c\n\n", platenum[0], platenum[1], platenum[2],
        platenum[3], platenum[4], platenum[5], platenum[6]);
      for (i=1; i<=numseries; i++)
        fprintseats(seat[(i-1)*4+1], seat[(i-1)*4+2],
          seat[(i-1)*4+3], seat[(i-1)*4+4]);
      fprintseatls(seat[numseats-4], seat[numseats-3],
        seat[numseats-2], seat[numseats-1], seat[numseats]);
      fclose(fp);
      printf("\nBus plate number and seat chart are saved in layout.txt\n");
    }
    else if (choice != '0')
      printf("Wrong choice!\n");
  }
  return 0;
}
