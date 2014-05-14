import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            int n = scanner.nextInt();
            n = n / 2 + 1;

            System.out.println((long)6 * n * n - 9);
        }
    }
}
