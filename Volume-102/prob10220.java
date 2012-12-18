import java.math.BigInteger;
import java.util.Scanner;

class Main {
  static final int MAX_N = 1000;
  static int[] digit_sums = new int[MAX_N + 1];

  public static void main(String[] args) {
    digit_sums[0] = 1;
    digit_sums[1] = 1;
    BigInteger factorial = BigInteger.ONE;

    for (int i = 2; i <= MAX_N; ++i) {
      BigInteger factor = new BigInteger(Integer.toString(i));
      factorial = factorial.multiply(factor);
      String digits = factorial.toString();

      for (int j = 0; j < digits.length(); ++j)
        digit_sums[i] += digits.charAt(j) - '0';
    }

    int n;
    Scanner sc = new Scanner(System.in);

    while (sc.hasNextInt()) {
      n = sc.nextInt();
      System.out.println(digit_sums[n]);
    }
  }
}
