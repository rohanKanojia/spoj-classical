#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

long long BLOCK_SZ = 555;
int freqArr[10000000];
typedef struct query { long long start, end, index; } query;
bool myComp(query a, query b);
void add(long long index, long long& curAns);
void remove(long long index, long long& curAns);

int main() {
  long long N, Q;
  scanf("%lld", &N);

  BLOCK_SZ = sqrt(N);
  vector<long long> arr(N);
  for(long long i = 0; i < N; i++)
    scanf("%lld", &arr[i]);

  scanf("%lld", &Q);
  vector<query> qq(Q);
  for(long long i = 0; i < Q; i++) {
    scanf("%lld%lld", &qq[i].start, &qq[i].end);
    qq[i].start--;
    qq[i].end--;
    qq[i].index = i;
  }
  sort(qq.begin(), qq.end(), myComp);

  vector<long long> queryAns(Q);
  long long curL = 0, curR = 0, curAns = 0;
  for(long long i = 0; i < Q; i++) {
    while(curL < qq[i].start) {
      remove(arr[curL], curAns);
      curL++;
    }
    while(curL > qq[i].start) {
      add(arr[curL-1], curAns);
      curL--;
    }
    while(curR <= qq[i].end) {
      add(arr[curR], curAns);
      curR++;
    }
    while(curR > qq[i].end+1) {
      remove(arr[curR-1], curAns);
      curR--;
    }
    queryAns[qq[i].index] = curAns;
  }

  for(long long i = 0; i < Q; i++)
    printf("%lld\n", queryAns[i]);
  return 0;
}

bool myComp(query a, query b) {
  if(a.start/BLOCK_SZ == b.start/BLOCK_SZ)
    return a.end < b.end;
  return a.start/BLOCK_SZ < b.start/BLOCK_SZ;
}

void add(long long index, long long& curAns) {
  freqArr[index]++;
  curAns += (freqArr[index] == 1);
}

void remove(long long index, long long& curAns) {
  freqArr[index]--;
  curAns -= (freqArr[index] == 0);
}
