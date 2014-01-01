import java.util.Scanner;

class Main {
  static final int RADIX = 3;

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    while (in.hasNextInt()) {
      int n = in.nextInt();

      if (n < 0) break;

      System.out.println(Integer.toString(n, RADIX));
    }
  }
}
