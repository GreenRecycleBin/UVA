#include <stdio.h>

#define min(X, Y) ((X) < (Y) ? (X) : (Y))

int main()
{
  int blue[3], green[3], clear[3], min;

  while (scanf("%d %d %d %d %d %d %d %d %d",
                &blue[0], &green[0], &clear[0],
                &blue[1], &green[1], &clear[1],
                &blue[2], &green[2], &clear[2]) != EOF) {
    int bgc = blue[1] + blue[2] + green[0] + green[2] + clear[0] + clear[1]; 
    int bcg = blue[1] + blue[2] + clear[0] + clear[2] + green[0] + green[1];
    int gbc = green[1] + green[2] + blue[0] + blue[2] + clear[0] + clear[1];
    int gcb = green[1] + green[2] + clear[0] + clear[2] + blue[0] + blue[1];
    int cbg = clear[1] + clear[2] + blue[0] + blue[2] + green[0] + green[1];
    int cgb = clear[1] + clear[2] + green[0] + green[2] + blue[0] + blue[1];

    int min = min(min(min(min(min(bgc, bcg), gbc), gcb), cbg), cgb);

    if (min == bcg) {
      printf("BCG");
    }
    else if (min == bgc) {
      printf("BGC");
    }
    else if (min == cbg) {
      printf("CBG");
    }
    else if (min == cgb) {
      printf("CGB");
    } 
    else if (min == gbc) {
      printf("GBC");
    }
    else if (min == gcb) {
      printf("GCB");
    }

    printf(" %d\n", min);
  }

  return 0;
}
