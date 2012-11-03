import java.util.Scanner;
import java.math.BigInteger;

class Main {
  final static int MAX_N = 5000;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    BigInteger sum = BigInteger.ZERO, input;

    do {
      input = sc.nextBigInteger();
      sum = sum.add(input);
    } while (input.compareTo(BigInteger.ZERO) == 1);

    System.out.println(sum);
  }
}
