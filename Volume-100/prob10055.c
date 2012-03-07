#include <stdio.h>

int main()
{
  unsigned long long hashmat_num_soldiers, opponent_num_soldiers;

  while (scanf("%llu %llu", &hashmat_num_soldiers, &opponent_num_soldiers) != EOF) {
    if (opponent_num_soldiers < hashmat_num_soldiers) {
      unsigned long long temp = opponent_num_soldiers;
      opponent_num_soldiers = hashmat_num_soldiers;
      hashmat_num_soldiers = temp;
    }

    printf("%llu\n", opponent_num_soldiers - hashmat_num_soldiers); 
  }

  return 0;
}
