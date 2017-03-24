#include <cstdio>
#include <cstring>
using namespace std;

int dp[50][500];

int getPossibleGroupings(char str[], int start, int prevVal, int N) {
  if(start == N)
    return 1;
  else if(dp[start][prevVal] == -1) {
    int nGroupings = 0, digitSum = 0;
    for(int i = start; i < N; i++) {
      digitSum += str[i] - '0';
      if(digitSum >= prevVal)
        nGroupings += getPossibleGroupings(str, i+1, digitSum, N);
    }
    dp[start][prevVal] = nGroupings;
  }
  return dp[start][prevVal];
}

int main() {
  int nCase = 1;
  while(true) {
    char str[50];
    scanf("%s", str);
    if(str[0] == 'b')
      break;
    memset(dp, -1, sizeof(dp));

    printf("%d. %d\n", nCase++, getPossibleGroupings(str, 0, 0, strlen(str)));
  }
  return 0;
}
