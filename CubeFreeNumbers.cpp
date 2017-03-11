#include <iostream>
#include <vector>
using namespace std;

vector<bool> isCubeNumber(1000001);
vector<int> cubeFreeIndex(1000001);

void precompute(long long N) {
  for(long long i = 2; i*i*i < N; i++) {
    if(isCubeNumber[i] == false) {
      isCubeNumber[i*i*i] = true;
      long long cube = i*i*i;
      for(long long j = 2; j*cube < N; j++)
        isCubeNumber[j*cube] = true;
    }
  }
  long long pos = 1;
  for(long long i = 1; i < 1000001; i++) {
    if(!isCubeNumber[i])
      cubeFreeIndex[i] = pos++;
  }
}

int main() {
  precompute(1000001);
  long long T, nCase = 1;
  cin >> T;
  while(T--) {
    long long N;
    cin >> N;

    cout << "Case " << nCase++ << ": ";
    if(isCubeNumber[N])
      cout << "Not Cube Free\n";
    else
      cout << cubeFreeIndex[N] << endl;
  }
  return 0;
}
