#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

typedef struct Rectangle { int l, b; } Rectangle;

int main() {
  int N;
  scanf("%d", &N);
  vector<Rectangle> arr(N);
  for(int i = 0; i < N; i++)
    scanf("%d%d", &arr[i].l, &arr[i].b);

  vector<pair<int, int> > dp(N);
  dp[0] = make_pair(arr[0].l, arr[0].b);
  for(int i = 1; i < N; i++) {
    pair<int, int> curPos;
    curPos.first = arr[i].l + max(dp[i-1].first + abs(arr[i].b-arr[i-1].b), 
                                 dp[i-1].second + abs(arr[i].b-arr[i-1].l));
    curPos.second = arr[i].b + max(dp[i-1].first + abs(arr[i].l-arr[i-1].b),
                                 dp[i-1].second + abs(arr[i].l-arr[i-1].l));
    dp[i] = curPos;
  }
  printf("%lld\n", max(dp[N-1].first, dp[N-1].second));
  return 0;
}
