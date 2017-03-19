#include <cstdio>
#include <vector>
using namespace std;

int josephusWinner(int N, int D) {
  int ans = 0;
  for(int i = 1; i <= N; i++) 
    ans = (ans + D) % i;
  
  return ans+1; 
}

int main() {
  while(true) {
    int N, D;
    scanf("%d%d", &N, &D);
    if(!N && !D) break;

    printf("%d %d %d\n", N, D, josephusWinner(N, D));
  }
  return 0;
}
