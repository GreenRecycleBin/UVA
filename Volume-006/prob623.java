import java.util.Scanner;
import java.math.BigInteger;

class Main {
  static final int MAX_N = 1000;

  static BigInteger factorials[] = new BigInteger[MAX_N + 1];

  public static void main(String[] args) {
    BigInteger x = new BigInteger("1");
    factorials[0] = x;

    for (int i = 1; i <= MAX_N; ++i) {
      factorials[i] = factorials[i - 1].multiply(new BigInteger(Integer.toString(i)));
    }

    int n;
    Scanner sc = new Scanner(System.in);

    while (sc.hasNextInt()) {
      n = sc.nextInt();

      System.out.printf("%d!\n", n);
      System.out.println(factorials[n]);
    }
  }
}
