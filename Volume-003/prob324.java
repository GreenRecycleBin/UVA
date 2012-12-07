import java.util.Scanner;
import java.math.BigInteger;

class Main {
  static final int MAX_N = 366;

  static BigInteger factorials[] = new BigInteger[MAX_N + 1];
  static int digits[][] = new int[MAX_N + 1][10];

  public static void main(String[] args) {
    BigInteger x = new BigInteger("1");
    factorials[0] = x;

    for (int i = 1; i <= MAX_N; ++i) {
      factorials[i] = factorials[i - 1].multiply(new BigInteger(Integer.toString(i)));
    }

    for (int i = 0; i <= MAX_N; ++i) {
      String factorial = factorials[i].toString();

      for (int j = 0; j < factorial.length(); ++j)
        ++digits[i][factorial.charAt(j) - '0'];
    }

    int n;
    Scanner sc = new Scanner(System.in);

    while (sc.hasNextInt()) {
      n = sc.nextInt();

      if (n == 0) break;

      System.out.printf("%d! --\n", n);

      for (int i = 0; i < 10; ++i) {
        System.out.printf("   (%d)%5d", i, digits[n][i]);

        if (i == 4 || i == 9) System.out.println();
      }
    }
  }
}
