#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define SIZE 10001
bool isComposite[4*SIZE];
void sieveOfEratosethens(vector<int>& prime, int N) {
  isComposite[0] = isComposite[1] = true;
  for(int i = 2; i < N; i++) {
    if(!isComposite[i]) {
      for(int j = 2; i*j < N; j++)
        isComposite[i*j] = true;
    }
  }

  for(int i = 0; i < N; i++) {
    if(!isComposite[i])
      prime.push_back(i);
  }
}

int main() {
  int N;
  vector<int> prime;
  sieveOfEratosethens(prime, 4*SIZE);
  while(cin >> N) {
    map<int, int> pFactors;

    for(int i = N; i >= 2; i--) {
      int n = i;
      for(int j = 0; prime[j] <= n; j++) {
        while(n > 0 && n%prime[j] == 0 ) {
          pFactors[prime[j]]++;
          n /= prime[j];
        }
      }
    }
    
    map<int, int>::iterator ii = pFactors.begin();
    while(ii != pFactors.end()) {
      cout << ii->first << "^" << ii->second;
      ii++;
      if(ii != pFactors.end())
        cout << " * ";
    }
    cout << endl;
  }
  return 0;
}
