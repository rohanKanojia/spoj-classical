#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

long long getDollars(long long N, map<long long, long long>& coinToDollars);

int main() {
  long long N;
  map<long long, long long> coinToDollars;
  coinToDollars[2] = 2;
  coinToDollars[1] = 1;
  while(cin >> N) {
    cout << getDollars(N, coinToDollars) << endl;
  }
  return 0;
}

long long getDollars(long long N, map<long long, long long>& coinToDollars) {
  if(N < 1)
    return 0;
  else if(coinToDollars.find(N) == coinToDollars.end()) {
    long long dollars = getDollars(N/2, coinToDollars) + getDollars(N/3, coinToDollars) + getDollars(N/4, coinToDollars);
    coinToDollars[N] = std::max(dollars, N);
  }
  return coinToDollars[N];
}
