#include <iostream>
#include <climits>
#include <vector>
using namespace std;

long long getMaxSum(vector<long long>& a1, vector<long long>& a2);

int main() {
  while(true) {
    long long M, N;
    cin >> M;
    if(M == 0) break;

    vector<long long> a1(M);
    for(long long i = 0; i < M; i++)
      cin >> a1[i];
    a1.push_back(INT_MAX);
    cin >> N;
    vector<long long> a2(N);
    for(long long i = 0; i < N; i++)
      cin >> a2[i];
    a2.push_back(INT_MAX);

    cout << getMaxSum(a1, a2) << endl;
  }
  return 0;
}


long long getMaxSum(vector<long long>& a1, vector<long long>& a2) {
  long long i, j, ans = 0, suma = 0, sumb = 0;
  i = j = 0;

  while(i < a1.size()) {
    if(a1[i] == a2[j]) {
      ans += std::max(suma, sumb);
      suma = sumb = a1[i];
      i++;
      j++;
    }
    else if(a1[i] < a2[j]) 
      suma += a1[i++];
    else 
      sumb += a2[j++];
  }
  return ans;
}
