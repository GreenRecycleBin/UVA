import java.math.BigInteger;
import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    while (n-- > 0) {
      StringBuilder inputs[] = new StringBuilder[2];

      for (int i = 0; i < 2; ++i)
        inputs[i] = new StringBuilder(sc.next());

      BigInteger nums[] = new BigInteger[2];

      for (int i = 0; i < 2; ++i)
        nums[i] = new BigInteger(inputs[i].reverse().toString());

      BigInteger sum = nums[0].add(nums[1]);
      StringBuilder result = new StringBuilder(sum.toString());
      sum = new BigInteger(result.reverse().toString());

      System.out.println(sum.toString());
    }
  }
}
