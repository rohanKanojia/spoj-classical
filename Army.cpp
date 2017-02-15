#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long nA, nB;
    cin >> nA >> nB;
    vector<long long> a(nA), b(nB);

    for(long long i = 0; i < nA; i++) cin >> a[i];
    for(long long i = 0; i < nB; i++) cin >> b[i];

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    long long aIndex = 0, bIndex = 0;

    while(aIndex < a.size() && bIndex < b.size()) {
      if(a[aIndex] > b[bIndex])
        bIndex++;
      else if(a[aIndex] < b[bIndex])
        aIndex++;
      else
        bIndex++;
    }
    if(bIndex == b.size())
      cout << "Godzilla\n";
    else if(aIndex == a.size())
      cout << "MechaGodzilla\n";
    else
      cout << "uncertain\n"; 
  }
  return 0;
}
