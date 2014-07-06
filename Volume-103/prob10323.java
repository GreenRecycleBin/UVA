import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (in.hasNextInt()) {
            long factorial = factorial(in.nextInt());

            if (factorial == Long.MIN_VALUE) {
                System.out.println("Underflow!");
            } else if (factorial == Long.MAX_VALUE) {
                System.out.println("Overflow!");
            } else {
                System.out.println(factorial);
            }
        }
    }

    private static long factorial(int n) {
        switch (n) {
        case 8:
            return 40_320L;

        case 9:
            return 362_880L;

        case 10:
            return 3_628_800L;

        case 11:
            return 39_916_800L;

        case 12:
            return 479_001_600L;

        case 13:
            return 6_227_020_800L;

        default:
            if (n < 0) {
                if ((n & 1) == 0) {
                    return Long.MIN_VALUE;
                } else {
                    return Long.MAX_VALUE;
                }
            } else if (n < 8) {
                return Long.MIN_VALUE;
            } else {
                return Long.MAX_VALUE;
            }
        }
    }
}
