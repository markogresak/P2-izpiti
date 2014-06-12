// izpiti komplet 1/5 - naloga 1.

#include <stdio.h>
#include <stdlib.h>

int najBlok(int **z, int m, int n);

int main(int argc, char const *argv[])
{
  int tmp[5][6] = {
    {0, 1, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 1}};
  
  int m = 5, n = 6;
  int **z = malloc(m * sizeof(int *));
  for(int i = 0; i < m; i++) {
    z[i] = calloc(n, sizeof(int));
    for(int j = 0; j < n; j++)
      z[i][j] = tmp[i][j];
  }

  najBlok(z, m, n);

  return 0;
}

int najBlok(int **z, int m, int n) {
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++)
      printf("%d ", z[i][j]);
    printf("\n");
  }
  return 0;
}
