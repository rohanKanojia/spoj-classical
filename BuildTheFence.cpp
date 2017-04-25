#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

class Point {
public:
  int x, y, index;
  bool operator<(const Point& aPoint) const {
    if(y != aPoint.y) return y < aPoint.y;
    if(x != aPoint.x) return x < aPoint.x;

    return index < aPoint.index;
  }
  double distance(const Point& aPoint) const {
    return sqrt((x-aPoint.x)*(x-aPoint.x) + 
      (y-aPoint.y)*(y-aPoint.y));
  }
};

int orientation(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

Point P[100010], H[200010];

int main() {
  int T, N;
  scanf("%d", &T);

  while(T--) {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
      scanf("%d%d",  &P[i].x, &P[i].y);
      P[i].index = i+1;
    }
    // Apply Andrew's monotone chain convex hull algorithm
    std::sort(P, P+N);
    
    int k = 1;
    for(int i = 1; i < N; i++) {
      if(P[i].x != P[i-1].x || P[i].y != P[i-1].y) {
        if(k != i)
          P[k] = P[i];
        k++;
      }
    }
    N = k;

    k = 0;
    for(int i = 0; i < N; i++) {
      while(k >= 2 && orientation(H[k-2], H[k-1], P[i]) <= 0)
        k--;
      H[k++] = P[i];
    }

    for(int i = N-1, t = k+1; i >= 0; i--) {
      while(k >= t && orientation(H[k-2], H[k-1], P[i]) <= 0)
        k--;
      H[k++] = P[i];
    }
    k--;

    // calculate distance and points
    double len =  0;
    for(int i = 0; i < k; i++) 
      len += H[i].distance(H[i+1]);

    printf("%.2f\n", len);

    for(int i = 0; i < k; i++)
      printf("%d ", H[i].index);
    printf("\n");
  }
}
