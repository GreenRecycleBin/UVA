import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int minStart = Integer.MAX_VALUE;
        int maxEnd = Integer.MIN_VALUE;

        do {
            int start = in.nextInt();

            if (start == 0) {
                break;
            }

            int end = in.nextInt();

            System.out.println(numSquareNumbersInInclusiveRange(start, end));
        } while (in.hasNextInt());
    }

    private static int numSquareNumbersInInclusiveRange(int start, int end) {
        return (int) Math.floor(Math.sqrt(end))
            - (int) Math.ceil(Math.sqrt(start))
            + 1;
    }
}
