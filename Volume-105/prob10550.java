import java.util.Scanner;

class Main {
    private static final double FULL_TURN = 360.0;
    private static final int NUM_MARKS = 40;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        do {
            int current = in.nextInt();
            int first = in.nextInt();
            int second = in.nextInt();
            int third = in.nextInt();

            if (current == 0 && first == 0 && second == 0 && third == 0) {
                break;
            }

            double total = FULL_TURN * 2;

            total += degreeBetween(current, first, true);
            current = first;

            total += FULL_TURN;

            total += degreeBetween(current, second, false);
            current = second;

            total += degreeBetween(current, third, true);

            System.out.println((int) total);
        } while (in.hasNextInt());
    }

    private static double
        degreeBetween(int start, int end, boolean clockwise) {
        if (start == end) {
            return 0.0;
        }

        int diff;

        if (clockwise) {
            diff = start - end;
        } else {
            diff = end - start;
        }

        if (diff < 0) {
            diff += NUM_MARKS;
        }

        return (double) diff / NUM_MARKS * FULL_TURN;
    }
}
