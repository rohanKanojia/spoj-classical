#include <cstdio>
#include <numeric>
using namespace std;

bool isEqual(int arr[], int N) {
  for(long long i = 1; i < N; i++) {
    if(arr[i] != arr[0])
      return false;
  }
  return true;
}

int main() {
  long long T;
  int sequence[100], start[100];
  scanf("%lld", &T);

  while(T--) {
    long long S, C, N;
    scanf("%lld%lld", &S, &C);

    for(long long i = 0; i < S; i++)
      scanf("%lld", &sequence[i]);
    
    N = S;
    while(!isEqual(sequence, N)) {
      start[N] = sequence[0];
      for(long long i = 0; i < N-1; i++)
        sequence[i] = sequence[i+1]-sequence[i];
      N--;
    }


    for(long long i = N; i < N+C; i++)
      sequence[i] = sequence[0];

    for(int i = N; i < S; i++) {
      long long sum = std::accumulate(sequence, sequence + i+C, 0) + start[i+1];
      for(int j = i+C; j >= 0; j--) {
        sequence[j] = sum;
        if(j-1 >= 0)
          sum -= sequence[j-1];
      }
    }

    for(long long i = S; i < S+C; i++) {
      if(i > S) printf(" ");
      printf("%lld", sequence[i]);
    }
    printf("\n");
  }
  return 0;
}
