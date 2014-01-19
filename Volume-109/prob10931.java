import java.math.BigInteger;
import java.util.BitSet;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        do {
            int n = in.nextInt();

            if (n == 0) break;

            BigInteger nBig = BigInteger.valueOf(n);
            BitSet bs = BitSet.valueOf(nBig.toByteArray());

            System.out.printf("The parity of %s is %d (mod 2).\n",
                              nBig.toString(2), bs.cardinality());
        } while (in.hasNextInt());
    }
}
