import java.util.Collections;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            final int ROW = scanner.nextInt();
            final int COLUMN = scanner.nextInt();
            final int[][] grid = new int[ROW][COLUMN];

            for (int i = 0; i < ROW; ++i)
                for (int j = 0; j < COLUMN; ++j)
                    grid[i][j] = scanner.nextInt();

            MinPath minPath = new MinPath(ROW, COLUMN, grid);
            int[] path = minPath.getMinPath();

            for (int i = 0; i < path.length; ++i) {
                System.out.print(path[i] + 1);

                if (i == path.length - 1) System.out.println();
                else System.out.print(" ");
            }

            System.out.println(minPath.getMinCost());
        }
    }
}

class MinPath {
    private final int ROW;
    private final int COLUMN;
    private final int[][] grid;
    private int[][] costs;
    private int[][] lastRow;
    private int[] minPath;

    public MinPath(final int ROW, final int COLUMN, final int[][] grid) {
        this.ROW = ROW;
        this.COLUMN = COLUMN;
        this.grid = grid;
    }

    public int[] getMinPath() {
        calculate();

        return minPath;
    }

    public int getMinCost() {
        calculateCosts();

        int minCost = costs[0][0];

        for (int i = 1; i < ROW; ++i) {
            final int CURRENT_COST = costs[i][0];

            if (CURRENT_COST < minCost)
                minCost = CURRENT_COST;
        }

        return minCost;
    }

    private void calculate() {
        calculateCosts();
        calculateMinPath();
    }

    private void calculateCosts() {
        if (costs != null) return;

        costs = new int[ROW][COLUMN];
        lastRow = new int[ROW][COLUMN - 1];

        for (int i = 0; i < ROW; ++i)
            costs[i][COLUMN - 1] = grid[i][COLUMN - 1];

        for (int i = COLUMN - 2; i >= 0; --i)
            for (int j = 0; j < ROW; ++j) {
                final int NEXT_COLUMN = i + 1;

                final int ROW_UP_RIGHT = (ROW + j - 1) % ROW;
                final int COST_UP_RIGHT = costs[ROW_UP_RIGHT][NEXT_COLUMN];

                final int ROW_RIGHT = j;
                final int COST_RIGHT = costs[ROW_RIGHT][NEXT_COLUMN];

                final int ROW_DOWN_RIGHT = (j + 1) % ROW;
                final int COST_DOWN_RIGHT = costs[ROW_DOWN_RIGHT][NEXT_COLUMN];

                final int MIN_COST = Math.min(Math.min(COST_UP_RIGHT, COST_RIGHT), COST_DOWN_RIGHT);

                SortedSet<Integer> lastRows = new TreeSet<Integer>();

                if (MIN_COST == COST_UP_RIGHT)
                    lastRows.add(ROW_UP_RIGHT);

                if (MIN_COST == COST_RIGHT)
                    lastRows.add(ROW_RIGHT);

                if (MIN_COST == COST_DOWN_RIGHT)
                    lastRows.add(ROW_DOWN_RIGHT);

                lastRow[j][i] = lastRows.first();
                costs[j][i] = grid[j][i] + MIN_COST;
            }
    }

    private void printCost() {
        for (int i = 0; i < ROW; ++i)
            for (int j = 0; j < COLUMN; ++j) {
                System.out.print(costs[i][j]);

                if (j == COLUMN - 1) System.out.println();
                else System.out.print(" ");
            }
    }

    private void calculateMinPath() {
        if (minPath != null) return;

        minPath = new int[COLUMN];
        minPath[0] = getMinRowInFirstColumn();

        for (int i = 1; i < COLUMN; ++i) {
            minPath[i] = lastRow[minPath[i - 1]][i - 1];
        }
    }

    private int getMinRowInFirstColumn() {
        int minRow = ROW - 1;
        int minCost = costs[minRow][0];

        for (int i = ROW - 2; i >= 0; --i) {
            final int CURRENT_COST = costs[i][0];

            if (CURRENT_COST <= minCost) {
                minCost = CURRENT_COST;
                minRow = i;
            }
        }

        return minRow;
    }
}
