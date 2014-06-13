// izpiti komplet 4/5 - naloga 1.

// zazeni z ukazom v terminalu:
// gcc -std=c99 izpiti-4-1.c -o izpiti-4-1 && ./izpiti-4-1 < input-1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define END_TEMP -9999

typedef struct day
{
  int temp;
  struct day *next;
} day;

// for shits and giggles (ali za hitro popravljanje pogoja)
bool isHot(int temp) { return temp >= 300; }

day* addDayEnd(day*, int);
int dolzinaZaporednihVrocihDni(day*);

// naloga zahteva celoten program, zato tukaj dodatne kode ni,
// podan je samo testni primer iz besedila (navodila za test so zgoraj)
int main(int argc, char const *argv[])
{
  int tmp;
  day *days = NULL;
  
  // ko prebere zadnjo temperaturo = -9999, se zanka ne izvede
  while(scanf("%d", &tmp) != EOF && tmp != END_TEMP)
    days = addDayEnd(days, tmp);

  day *next = days;

  int count = 0, start = 0, maxLen = 0;
  while(next != NULL) {
    int len = dolzinaZaporednihVrocihDni(next);
    if(len > maxLen) {
      maxLen = len;
      start = count + 1;
    }
    count++;
    next = next->next;
  }

  printf("%d %d\n", start, maxLen);

  free(days);
  return 0;
}

day* addDayEnd(day *days, int temp) {
  if(days == NULL) {
    days = (day *) malloc(sizeof(day));
    days->temp = temp;
    days->next = NULL;
  }
  else
    days->next = addDayEnd(days->next, temp);
  return days;
}

// Vrne dolzino strnjenega zaporedja vrocih dni
int dolzinaZaporednihVrocihDni(day *days) {
  day *tmp = days;
  int count = 0;

  while(tmp != NULL) {
    if(isHot(tmp->temp))
      count++;
    else
      break;
    tmp = tmp->next;
  }

  return count;
}
