#include <stdio.h>
#include <string.h>

static int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int main()
{
  int g[3][3], new_g[3][3];
  int n;
  scanf("%d", &n);

  while (n--) {
    /* Zero matrix is infinite */
    int is_finite = 0, count = -1, i;

    for (i = 0; i < 3; ++i) {
      int j;

      for (j = 0; j < 3; ++j) {
        scanf("%1d", &g[i][j]);
        is_finite |= g[i][j];
      }
    }

    for (; is_finite; ++count) {
      is_finite = 0;

      for (i = 0; i < 3; ++i) {
        int j;

        for (j = 0; j < 3; ++j) {
          int k;
          new_g[i][j] = 0;

          for (k = 0; k < 4; ++k) {
            int new_i = i + dx[k], new_j = j + dy[k];

            /* XOR is sum modulo 2 */
            if (0 <= new_i && new_i < 3 && 0 <= new_j && new_j < 3) {
              new_g[i][j] ^= g[new_i][new_j];
            }
          }
        }
      }

      memcpy(g, new_g, sizeof(new_g));

      for (i = 0; i < 3; ++i) {
        int j;

        for (j = 0; j < 3; ++j) {
          is_finite |= g[i][j];
        }
      }
    }

    printf("%d\n", count);
  }

  return 0;
}
