/* PLS50 2016-17 E02 - 1 */
/* ANTONIOS TOMAZOS */
/* Bus Seats Ver. 2 */

#include <stdio.h>
#include <stdlib.h>

#define MAXPLATENUM 7
#define MAXSEAT 53
#define MAXTEL 10
#define MAXNAME 40
#define NUL '\0'

FILE* fin, *fout;

struct seatstruct {
  char name[MAXNAME];
  unsigned short int tel[MAXTEL];
  unsigned int seat;
};

void readbusf(char*, int*, struct seatstruct seatrec[]);
void writebusf(char*,int, struct seatstruct seatrec[]);
void printnumfs(int, struct seatstruct seatrec[]);
void reserveseat(int, int, struct seatstruct seatrec[]);
void checkreserv(int, struct seatstruct seatrec[]);
void cancelreserv(int, int, struct seatstruct seatrec[]);
void printreserv(int, struct seatstruct seatrec[]);

int main(void) {
  struct seatstruct seatrec[MAXSEAT];
  int numseats=0, i=0, j=0, reserv=0;
  char platenum[MAXPLATENUM] = "       ";
  char choice=' ';

/* Initializations */

  for (i=0; i<=MAXSEAT; i++) {
    seatrec[i].name[0] = NUL;
    for (j=0; j<=MAXTEL; j++)
      seatrec[i].tel[j] = 0;
    seatrec[i].seat = i;
  }

/* Read Data File */

  readbusf(platenum, &numseats, seatrec);
  printf("\nBus Plate Number: %s\n", platenum);
  printf("Number of seats : %d\n", numseats);

/* Print Menu */

  while (choice != '0') {
    printf("\n");
    printf("---------------------------------------------------------\n");
    printf("1. Print the total number of free seats and their numbers\n");
    printf("2. Reserve seat\n");
    printf("3. Check if a seat is reserved\n");
    printf("4. Cancel reservation\n");
    printf("5. Print reserved seats\n");
    printf("0. Exit\n");
    printf("---------------------------------------------------------\n");
    printf("Please select:");
    scanf(" %c", &choice);
    if (choice == '1')
      printnumfs(numseats, seatrec);
    else if (choice == '2') {
      printf("\nEnter seat number: ");
      scanf("%d", &reserv);
      reserveseat(reserv, numseats, seatrec);
    }
    else if (choice == '3')
      checkreserv(numseats, seatrec);
    else if (choice == '4') {
      printf("\nEnter seat number to cancel reservation: ");
      scanf("%d", &reserv);
      cancelreserv(reserv, numseats, seatrec);
    }
    else if (choice == '5')
      printreserv(numseats, seatrec);
    else if (choice != '0')
      printf("Wrong choice!\n");
  }
  writebusf(platenum, numseats, seatrec);
  return 0;
}

/* Read Bus File */

void readbusf(char* platenum, int* numseats, struct seatstruct seatrec[]) {
  int readnumseats = 0, numrec=0, count=0, count1=0, count2=0;
  char name1[MAXNAME], name2[MAXNAME], stel[MAXTEL];
  unsigned int iseat=0;

  fin = fopen("bus.txt", "r");
  if (fin==NULL) {
    printf("Error Opening Bus File!\n");
    exit(1);
  }
  fscanf(fin, "%s %d\n", platenum, &readnumseats);
  *numseats = readnumseats;
  while (!feof(fin)) {
    fscanf(fin, "%s %s %u %10s\n", name1, name2, &iseat, stel);
    numrec++;
    seatrec[iseat].seat = iseat;
    count = 0;
    while (stel[count] != NUL) {
      seatrec[iseat].tel[count] = stel[count]-48;
      count++;
    }
    count1 = 0;
    while (name1[count1] != NUL) {
      seatrec[iseat].name[count1]=name1[count1];
      count1++;
    }
    seatrec[iseat].name[count1] = ' ';
    count1++;
    count2 = 0;
    while (name2[count2] != NUL) {
      seatrec[iseat].name[count1+count2]=name2[count2];
      count2++;
    }
    seatrec[iseat].name[count1+count2] = NUL;
  }
  fclose(fin);
}

/* Write Bus File */

void writebusf(char* platenum, int numseats, struct seatstruct seatrec[]) {
  int i=0, j=0;

  fout = fopen("bus.txt", "w");
  if (fout==NULL) {
    printf("Error Creating Bus File!\n");
    exit(1);
  }
  fprintf(fout, "%s %d\n", platenum, numseats);
  for (i=1; i<=numseats; i++) {
    if (seatrec[i].name[0] != NUL) {
      fprintf(fout, "%s %u ", seatrec[i].name, seatrec[i].seat);
      for (j=0; j<=MAXTEL-1; j++)
        fprintf(fout, "%u", seatrec[i].tel[j]);
      fprintf(fout, "\n");
    }
  }
  fclose(fout);
}

/* Print the total number of free seats and their numbers */

void printnumfs(int numseats, struct seatstruct seatrec[]) {
  int count = 0, i = 0;

  printf("\nNumbers of free seats:\n");
  count = 0;
  for (i=1; i<=numseats; i++)
    if (seatrec[i].name[0] == NUL) {
      count++;
      printf("%d ", i);
    }
  printf("\nTotal number of free seats: %d\n", count);
}

/* Reserve seat */

void reserveseat(int reserv, int numseats, struct seatstruct seatrec[]) {
  int i=0, count=0, count1=0, count2=0;
  unsigned short int itel[MAXTEL];
  char name1[MAXNAME], name2[MAXNAME], stel[MAXTEL];

  for (i=0; i<=MAXTEL-1; i++)
    itel[i] = 0;
  if ((reserv <= 0) || (reserv > numseats))
    printf("Seat number %d is out of limits!\n", reserv);
  else if (seatrec[reserv].name[0] != NUL)
    printf("Seat number %d is already reserved!\n", reserv);
  else {
    printf("Enter Surname: ");
    scanf("%s", name1);
    printf("Enter Name: ");
    scanf("%s", name2);
    printf("Enter Tel Number: ");
    scanf("%s", stel);
    count = 0;
    while (stel[count] != NUL) {
      itel[count] = stel[count]-48;
      count++;
    }
    if (itel[0] == 0) {
      printf("Wrong Tel Number!");
      return;
    }
    for (i=0; i<=MAXTEL-1; i++) {
      if (itel[i] > 9) {
        printf("Wrong Tel Number!\n");
        return;
      }
    }
    for (i=0; i<=MAXTEL-1; i++)
      seatrec[reserv].tel[i] = itel[i];
    seatrec[reserv].seat = reserv;
    count1 = 0;
    while (name1[count1] != NUL) {
      seatrec[reserv].name[count1]=name1[count1];
      count1++;
    }
    seatrec[reserv].name[count1] = ' ';
    count1++;
    count2 = 0;
    while (name2[count2] != NUL) {
      seatrec[reserv].name[count1+count2]=name2[count2];
      count2++;
    }
    seatrec[reserv].name[count1+count2] = NUL;
    printf("\nSeat number %d is reserved for %s \n", reserv, seatrec[reserv].name);
  }
}

/* Check if a seat is reserved */

void checkreserv(int numseats, struct seatstruct seatrec[]) {
  char name1[MAXNAME], name2[MAXNAME], name3[MAXNAME], stel[MAXTEL];
  char choice=' ';
  unsigned short int itel[MAXTEL];
  int i=0, j=0, count=0, count1=0, count2=0, reserv=0;

  for (i=0; i<=MAXTEL-1; i++)
    itel[i] = 0;
  printf("\nCheck Reservation\n");
  printf("-----------------\n");
  printf("1. By Name\n");
  printf("2. By Tel Number\n");
  printf("-----------------\n");
  printf("Please select:");
  scanf(" %c", &choice);
  if (choice == '1') {
    printf("Enter Surname: ");
    scanf("%s", name1);
    printf("Enter Name: ");
    scanf("%s", name2);
    count1 = 0;
    while (name1[count1] != NUL) {
      name3[count1]=name1[count1];
      count1++;
    }
    name3[count1] = ' ';
    count1++;
    count2 = 0;
    while (name2[count2] != NUL) {
      name3[count1+count2]=name2[count2];
      count2++;
    }
    name3[count1+count2] = NUL;
    for (i=1; i<=numseats; i++) {
      reserv = 0;
      count = 0;
      while (name3[count] != NUL) {
        if (seatrec[i].name[count] == name3[count])
          reserv = 1;
        else {
          reserv = 0;
          break;
        }
        count++;
      }
      if (reserv) {
        printf("There is a reservation for this Name. Seat No %d\n", i);
        return;
      }
    }
    if (reserv == 0) {
      printf("There is not any reservation for this Name\n");
      return;
    }
  }
  else if (choice == '2') {
    printf("\nEnter Tel Number: ");
    scanf("%s", stel);
    count = 0;
    while (stel[count] != NUL) {
      itel[count] = stel[count]-48;
      count++;
    }
    if (itel[0] == 0) {
      printf("Wrong Tel Number!");
      return;
    }
    for (i=0; i<=MAXTEL-1; i++) {
      if (itel[i] > 9) {
        printf("Wrong Tel Number!\n");
        return;
      }
    }
    for (i=1; i<=numseats; i++) {
      reserv = 0;
      for (j=0; j<=MAXTEL-1; j++)
        if (seatrec[i].tel[j] == itel[j])
          reserv = 1;
        else {
          reserv = 0;
          break;
        }
      if (reserv) {
        printf("There is a reservation for this Tel Number. Seat No %d\n", i);
        return;
      }
    }
    if (reserv == 0) {
      printf("There is not any reservation for this Tel Number\n");
      return;
    }
  }
    else {
      printf("Wrong choice!\n");
      return;
    }
}

/* Cancel reservation */

void cancelreserv(int reserv, int numseats, struct seatstruct seatrec[]) {

  if ((reserv <= 0) || (reserv > numseats))
    printf("Seat number %d is out of limits!\n", reserv);
  else if (seatrec[reserv].name[0] == NUL)
    printf("Seat number %d is already free!\n", reserv);
  else {
    seatrec[reserv].name[0] = NUL;
    printf("Seat number %d is now free\n", reserv);
  }
}

/* Print reserved seats */

void printreserv(int numseats, struct seatstruct seatrec[]) {
  int i=0, j=0;

  printf("\n%34s\n", "Reserved Seats");
  printf("%34s\n", "--------------");
  printf("%2s %40s %10s\n", "NO", "NAME", "TEL");
  for (i=1; i<=numseats; i++)
    if (seatrec[i].name[0] != NUL) {
      printf("%2u %40s ", seatrec[i].seat, seatrec[i].name);
      for (j=0; j<=MAXTEL-1; j++)
        printf("%u", seatrec[i].tel[j]);
      printf("\n");
    }
}

