#include <cstdio>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  
  while(T--) {
    int N, elem;
    scanf("%d", &N);
    
    long long evenSum = 0, oddSum = 0;
    for(int i = 0; i < N; i++) {
      scanf("%d", &elem);
      if(i&1)
        oddSum += elem;
      else
        evenSum += elem;
    }
    printf("%s\n", (oddSum == evenSum ? "YES" : "NO"));
  }
  return 0;
}
