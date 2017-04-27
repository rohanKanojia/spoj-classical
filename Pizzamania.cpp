#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    int N, M;
    scanf("%d%d", &N, &M);
    vector<int> arr(N);
    for(int i = 0; i < N; i++)
      scanf("%d", &arr[i]);

    std::sort(arr.begin(), arr.end());

    int nPairs = 0;
    for(int i = 0; i < N; i++) {
      int nRes = std::lower_bound(arr.begin(), arr.end(), M-arr[i]) - arr.begin();
      if(nRes != i && nRes != N && arr[nRes] == M- arr[i]) 
        nPairs++;
    }
    printf("%d\n", nPairs/2);
  }

  return 0;
}
