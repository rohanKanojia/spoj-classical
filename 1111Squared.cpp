#include <iostream>
using namespace std;

int main() {
  long long N;

  while(cin >> N) {
    long long a = 81 * (N/9);
    long long b = (N - 9*(N/9));
    cout << (a + b*b) << endl;
  }
  return 0;
}
