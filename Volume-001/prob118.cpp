#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int MAX_N = 51;

static bool has_scent[MAX_N][MAX_N];

struct Robot
{
  enum Direction {EAST, WEST, SOUTH, NORTH};

  static int dx[4], dy[4];

  static void Setup()
  {
    dx[EAST] = 1;
    dx[WEST] = -1;
    dy[SOUTH] = -1;
    dy[NORTH] = 1;
  }

  Robot(int x, int y, char direction) : x(x), y(y)
  {
    switch (direction) {
      case 'E':
        this->direction = EAST;

        break;

      case 'W':
        this->direction = WEST;

        break;

      case 'S':
        this->direction = SOUTH;

        break;

      case 'N':
        this->direction = NORTH;

        break;
    }

    is_lost = false;
  }

  void Rotate(char r)
  {
    switch (r) {
      case 'L':
        switch (direction) {
          case EAST:
            direction = NORTH;

            break;

          case WEST:
            direction = SOUTH;

            break;

          case SOUTH:
            direction = EAST;

            break;

          case NORTH:
            direction = WEST;

            break;
        }

        break;

      case 'R':
        switch (direction) {
          case EAST:
            direction = SOUTH;

            break;

          case WEST:
            direction = NORTH;

            break;

          case SOUTH:
            direction = WEST;

            break;

          case NORTH:
            direction = EAST;

            break;
        }

        break;
    }
  }

  void MoveForward()
  {
    x += dx[direction];
    y += dy[direction];
  }

  bool IsLost(int row, int column) {
    if (x < 0 || x >= row || y < 0 || y >= column) return true;
    else return false;
  }

  void GetRepresentation(string &s)
  {
    stringstream ss;
    char direction_char;

    ss << x << " " << y << " ";

    switch (direction) {
      case EAST:
        direction_char = 'E';

        break;

      case WEST:
        direction_char = 'W';

        break;

      case SOUTH:
        direction_char = 'S';

        break;

      case NORTH:
        direction_char = 'N';

        break;
    }

    ss << direction_char;

    if (is_lost) ss << " LOST";

    s = ss.str();
  }

  Direction direction;
  int x, y;
  bool is_lost;
};

int Robot::dx[], Robot::dy[];

int main()
{
  Robot::Setup();

  int row, column;
  scanf("%d %d", &row, &column);
  ++row;
  ++column;
  getchar();

  string lines[2];

  while (getline(cin, lines[0]) && getline(cin, lines[1])) {

    int x, y;
    char direction;

    sscanf(lines[0].c_str(), "%d %d %c", &x, &y, &direction);

    Robot robot(x, y, direction);

    for (int i = 0; i < lines[1].size() && !robot.is_lost; ++i) {
      switch (lines[1][i]) {
        case 'L':
        case 'R':
          robot.Rotate(lines[1][i]);

          break;

        case 'F':
          int temp_x = robot.x, temp_y = robot.y;
          robot.MoveForward();

          if (robot.IsLost(row, column)) {
            if (!has_scent[temp_x][temp_y]) {
              has_scent[temp_x][temp_y] = true;
              robot.is_lost = true;
            }

            robot.x = temp_x;
            robot.y = temp_y;
          }

          break;
      }
    }

    string s;
    robot.GetRepresentation(s);

    printf("%s\n", s.c_str());
  }

  return 0;
}
