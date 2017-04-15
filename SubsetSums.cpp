#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateSubsets(vector<long long>& arr, long long start, long long end, vector<long long>& target) {
  for(long long i = 0; i < (1<<(end-start)); i++) {
    long long sum = 0;
    for(long long j = start; j < end; j++) {
      if(i & (1<<(j-start))) 
        sum += arr[j];
    }
    target.push_back(sum);
  }
}

long long getSumBetweenAB(vector<long long>& arr, long long A, long long B) {
  vector<long long> left, right;
  generateSubsets(arr, 0, arr.size()/2, left);
  generateSubsets(arr, arr.size()/2, arr.size(), right);
  long long nSubsetsBetweenAB = 0;

  std::sort(right.begin(), right.end());
  for(long long i = 0; i < left.size(); i++) {
    long long l = lower_bound(right.begin(), right.end(), A-left[i]) - right.begin();
    long long r = upper_bound(right.begin(), right.end(), B-left[i]) - right.begin();
    nSubsetsBetweenAB += (r-l);
  }
  return nSubsetsBetweenAB;
}

int main() {
  long long N, A, B;
  cin >> N >> A >> B;

  vector<long long> arr(N);
  for(long long i = 0; i < N; i++)
    cin >> arr[i];

  cout << getSumBetweenAB(arr, A, B) << endl;
  return 0;
}
