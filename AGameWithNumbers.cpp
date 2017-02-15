#include <iostream>
using namespace std;

int main() {
  long long N;
  cin >> N;

  if(N%10 == 0) {
    cout << "2\n";
  }
  else {
    cout << "1\n";
    cout << N%10 << endl;
  }
  return 0;
}
