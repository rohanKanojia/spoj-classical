#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long T, N;
  vector<long long> F(36, 0);

  for(int i = 1; i < F.size(); i++)
    F[i] = 3*F[i-1] + 2;
  
  cin >> T;
  while(T--) {
    cin >> N;
    cout << F[N] << endl;
  }
  return 0;
}
