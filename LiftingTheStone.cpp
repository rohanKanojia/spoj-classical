#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    int N;
    scanf("%d", &N);

    vector<pair<int, int> > points(N);
    for(int i = 0; i < N; i++)
      scanf("%d%d", &points[i].first, &points[i].second);
    points.push_back(make_pair(points[0].first, points[0].second));

    double area = 0, cx = 0, cy = 0;
    for(int i = 0; i < N; i++) {
      double p = points[i].first * points[i+1].second - points[i+1].first * points[i].second;
      cx += p*(points[i].first + points[i+1].first);
      cy += p*(points[i].second + points[i+1].second);
      area += p;
    }

    cx /= (3.0*area);
    cy /= (3.0*area);
    printf("%.2lf %.2lf\n", cx, cy);
  }
  return 0;
}
