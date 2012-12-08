#include <cmath>
#include <cstdio>
#include <limits>
#include <utility>

using namespace std;

static const int MAX_N = 10;

typedef pair<double, double> ii;
typedef numeric_limits<double> db;

class Shape
{
public:
  virtual bool contains(const ii &point) = 0;
};

static Shape *shapes[10];

struct Rectangle : Shape
{
  ii upper_left;
  ii lower_right;

  Rectangle(double x1, double y1, double x2, double y2) :
    upper_left(ii(x1, y1)), lower_right(ii(x2, y2)) {}

  bool contains(const ii &point)
  {
    return upper_left.first < point.first  && point.first < lower_right.first &&
      lower_right.second < point.second && point.second < upper_left.second;
  }
};

struct Circle : Shape
{
  ii center;
  double radius;

  Circle(double x, double y, double r) : center(ii(x, y)), radius(r) {}

  bool contains(const ii &point)
  {
    return radius - sqrt(pow(point.first - center.first, 2) +
        pow(point.second - center.second, 2)) >= db::epsilon();
  }
};

int main()
{
  char type;
  int n = 0;

  while (scanf("%c", &type) == 1 && type != '*') {
    if (type == 'r') {
      double x1, y1, x2, y2;
      scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
      shapes[n++] = new Rectangle(x1, y1, x2, y2);
    }
    else if (type == 'c') {
      double x, y, r;
      scanf("%lf %lf %lf", &x, &y, &r);
      shapes[n++] = new Circle(x, y, r);
    }
  }

  int id = 1;
  double x, y;

  while (scanf("%lf %lf", &x, &y) == 2 && (x < 9999.9 || y < 9999.9)) {
    bool is_contained = false;

    for (int i = 0; i < n; ++i) {
      if (shapes[i]->contains(ii(x, y))) {
        printf("Point %d is contained in figure %d\n", id, i + 1);
        is_contained = true;
      }
    }

    if (!is_contained)
      printf("Point %d is not contained in any figure\n", id);

    ++id;
  }

  return 0;
}
