#include <iostream>
using namespace std;

int main() {
  long long N;
  cin >> N;

  bool isPowerTwo = (N & N-1);
  cout << (isPowerTwo ? "NIE" : "TAK") << endl;
  return 0;
}
