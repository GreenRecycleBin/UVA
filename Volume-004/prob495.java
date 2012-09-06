import java.util.Scanner;
import java.math.BigInteger;

class Main {
  final static int MAX_N = 5000;
  static BigInteger[] fibonacci_nums = new BigInteger[MAX_N + 1];
  static int last_index = 1;

  public static void main(String[] args) {
    fibonacci_nums[0] = new BigInteger("0");
    fibonacci_nums[1] = new BigInteger("1");
    Scanner sc = new Scanner(System.in);
    int n;

    while (sc.hasNextInt()) {
      n = sc.nextInt();

      if (fibonacci_nums[n] == null) {
        for (int i = last_index + 1; i <= n; ++i)
          fibonacci_nums[i] = fibonacci_nums[i - 1].add(fibonacci_nums[i - 2]);

        last_index = n;
      }

      System.out.printf("The Fibonacci number for %d is %s\n", n, fibonacci_nums[n].toString());
    }
  }
}
