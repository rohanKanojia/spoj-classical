#include <cstdio>
#include <unordered_map>
using namespace std;

#define SIZE 500004
int recamanSeq[SIZE];
unordered_map<long long, bool> bPresent;

void computeSeq(int N) {
  recamanSeq[0] = 0;
  bPresent[0] = true;
  for(long long i = 1; i < N; i++) {
    if(recamanSeq[i-1]-i > 0 && bPresent.find(recamanSeq[i-1]-i) == bPresent.end())
      recamanSeq[i] = recamanSeq[i-1]-i;
    else 
      recamanSeq[i] = recamanSeq[i-1]+i;
    bPresent[recamanSeq[i]] = true;
  }
}

int main() {
  computeSeq(SIZE);

  while(true) {
    int N;
    scanf("%d", &N);
    if(N == -1)
      break;

    printf("%d\n", recamanSeq[N]);
  }
  return 0;
}

