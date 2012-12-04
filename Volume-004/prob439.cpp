#include <cstdio>
#include <queue>

using namespace std;

const int MAX_SIZE = 8;

static int dx[MAX_SIZE] = {2, 2, 1, 1, -1, -1, -2, -2};
static int dy[MAX_SIZE] = {-1, 1, -2, 2, -2, 2, -1, 1};
enum Color {WHITE, GREY, BLACK};

struct Node
{
  int row, column, cost;
  Color color;
} static matrix[MAX_SIZE][MAX_SIZE];

void Setup()
{
  for (int i = 0; i < MAX_SIZE; ++i) {
    for (int j = 0; j < MAX_SIZE; ++j) {
      Node &current = matrix[i][j];
      current.row = i;
      current.column = j;
      current.cost = 99;
      current.color = WHITE;
    }
  }
}

// The knight is at location (x, y)
void CalculateCost(int x, int y)
{
  Setup();
  matrix[x][y].cost = 0;

  queue<Node> q;
  q.push(matrix[x][y]);

  while (!q.empty()) {
    Node current = q.front();
    q.pop();

    for (int i = 0; i < MAX_SIZE; ++i) {
      int new_x = current.row + dx[i], new_y = current.column + dy[i];

      if (0 <= new_x && new_x < MAX_SIZE && 0 <= new_y && new_y < MAX_SIZE &&
          matrix[new_x][new_y].color == WHITE) {
        matrix[new_x][new_y].cost = matrix[current.row][current.column].cost + 1;
        matrix[new_x][new_y].color = GREY;
        q.push(matrix[new_x][new_y]);
      }

      matrix[current.row][current.column].color = BLACK;
    }
  }
}

int main()
{
  char i, j, k, l;

  while (scanf("%c%c %c%c%*c", &j, &i, &l, &k) == 4) {
    CalculateCost(i - '1', j - 'a');

    printf("To get from %c%c to %c%c takes %d knight moves.\n", j, i, l, k, matrix[k - '1'][l - 'a'].cost);
  }

  return 0;
}
