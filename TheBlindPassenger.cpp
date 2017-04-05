#include <cstdio>

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);

    if(N > 1) {
      long long nRow = (N-2)/5+1, nSeat = (N-2)%10;
      char seat[] = { 'W', 'A', 'A', 'M', 'W', 'W', 'M', 'A', 'A', 'W'};
      char direction[] = {'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'L', 'L'};
      printf("%lld %c %c\n", nRow, seat[nSeat], direction[nSeat]);
    }
    else
      printf("poor conductor\n");
  }
  return 0;
}
