#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    int N;
    scanf("%d", &N);
    vector<int> arr(N);
    for(int i = 0; i < N; i++)
      scanf("%d", &arr[i]);

    std::sort(arr.begin(), arr.end());
    int nPairs = 0;
    vector<bool> isVisited(N, false);
    for(int i = 0; i < N; i++) {
      if(!isVisited[i]) 
        for(int j = i+1; j < N; j++) {
          if(2*arr[i] == arr[j] && isVisited[j] == false) {
            nPairs++;
            isVisited[j] = true;
            break;
          }
        }
    }
    printf("%d\n", nPairs);
  }
  return 0;
}
