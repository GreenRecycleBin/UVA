import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    while (n-- > 0) {
      int x, y;
      char c;
      x = sc.nextInt(16);
      c = sc.findInLine("[+-]").charAt(0);
      y = sc.nextInt(16);

      String x_binary = String.format("%13s", Integer.toBinaryString(x)).replace(' ', '0');
      String y_binary = String.format("%13s", Integer.toBinaryString(y)).replace(' ', '0');

      int result = 0;

      switch (c) {
        case '+':
          result = x + y;

          break;

        case '-':
          result = x - y;

          break;
      }

      System.out.printf("%s %c %s = %d\n", x_binary, c, y_binary, result);
    }
  }
}
