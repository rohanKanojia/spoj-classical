#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

bool checkPrime(long long N) {
  long long sqrtN = sqrt(N);
  if(N < 2) return false;
  for(long long i = 2; i <= sqrtN; i++) {
    if(N%i == 0)
      return false;
  }
  return true;
}

int main() {
  long long T;
  std::cin >> T;
  while(T--) {
    long long start, end;
    std::cin >> start >> end;
    for(long long i = start; i <= end; i++) {
      if(checkPrime(i) == true)
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
  }
}
