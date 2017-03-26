#include <iostream>
using namespace std;

long long a[10000001], p[10000001];

void precompute() {
  for(long long i = 2; i < 10000001; i++) {
    if(p[i] == 0) {
      p[i] = i;
      for(long long j = 2*i; j < 10000001; j += i)
        if(!p[j])
          p[j] = i;
      
      a[i] = a[i-1] + p[i];
    }
    else
      a[i] = a[i-1] + p[i];
  }
}

int main() {
  long long T;
  cin >> T;

  precompute();
  while(T--) {
    long long N;
    cin >> N;
    cout << a[N] << endl;
  }
  return 0;
}
