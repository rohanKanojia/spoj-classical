#include <iostream>
#include <cmath>
using namespace std;

long long getNthSum(long long sum) {
  return ( -6 + sqrt(36 + 48*sum)) / (2*6);
}

long long sumOf(long long N) {
  return (N * (12 + (N-1)*6))/2;
}

int main() {
  long long N;

  while(1) {
    cin >> N;
    if(N == -1)
      break;
    
    N--;
    long long nthTerm = getNthSum(N);
    if(sumOf(nthTerm) == N)
      cout << "Y\n";
    else
      cout << "N\n";
  }
}
