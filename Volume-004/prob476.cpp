#include <cstdio>
#include <vector>

using namespace std;

typedef pair<double, double> ii;

struct Rectangle
{
  ii upper_left;
  ii lower_right;

  Rectangle(double x1, double y1, double x2, double y2) :
    upper_left(ii(x1, y1)), lower_right(ii(x2, y2)) {}
};

int main()
{
  vector<Rectangle> rectangles;
  char type;

  while (scanf("%c", &type) == 1 && type == 'r') {
    double x1, y1, x2, y2;
    scanf("%lf %lf %lf %lf%*c", &x1, &y1, &x2, &y2);
    rectangles.push_back(Rectangle(x1, y1, x2, y2));
  }

  double x, y;
  int id = 0;

  while (scanf("%lf %lf", &x, &y) == 2 && (x != 9999.9 || y != 9999.9)) {
    bool is_contained = false;

    for (int i = 0; i < rectangles.size(); ++i) {
      if (rectangles[i].upper_left.first < x &&
          x < rectangles[i].lower_right.first &&
          rectangles[i].upper_left.second > y &&
          y > rectangles[i].lower_right.second) {
        printf("Point %d is contained in figure %d\n", id+ 1, i + 1);
        is_contained = true;
      }
    }

    if (!is_contained)
      printf("Point %d is not contained in any figure\n", id + 1);

    ++id;
  }

  return 0;
}
