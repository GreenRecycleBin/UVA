import java.util.Scanner;
import java.math.BigInteger;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    BigInteger x, y;

    while (sc.hasNext()) {
      x = sc.nextBigInteger();
      y = sc.nextBigInteger();

      System.out.println(x.multiply(y));
    }
  }
}
