#include <cstdio>
#include <vector>
using namespace std;

long long getSum(vector<long long>& arr);
void merge(vector<long long>& arr, vector<long long>& left, vector<long long>& right, long long& sum);
void mergeSort(vector<long long>& arr, long long& sum, long long start, long long end);

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);
    vector<long long> arr(N);
    for(long long i = 0; i < N; i++)
      scanf("%lld", &arr[i]);

    printf("%lld\n", getSum(arr));
  }
  return 0;
}

long long getSum(vector<long long>& arr) {
  long long sum = 0;
  mergeSort(arr, sum, 0, arr.size());
  return sum;
}

void mergeSort(vector<long long>& arr, long long& sum, long long start, long long end) {
  if(arr.size() <= 1)
    return;

  long long mid = start + (end-start)/2;
  std::vector<long long> left, right;
  left.assign(arr.begin()+start, arr.begin()+mid);
  right.assign(arr.begin()+mid, arr.begin()+end);

  mergeSort(left, sum, 0, mid);
  mergeSort(right, sum, 0, arr.size()-mid);

  merge(arr, left, right, sum);
}

void merge(vector<long long>& arr, vector<long long>& left, vector<long long>& right, 
  long long& sum) {
  long long i, l, r;
  l = r = i = 0;

  while(l < left.size() && r < right.size()) {
    if(left[l] < right[r]) {
      sum += left[l] * (right.size()-r);
      arr[i++] = left[l++];
    }
    else {
      arr[i++] = right[r++];
    }
  }

  while(l < left.size()) arr[i++] = left[l++];
  while(r < right.size()) arr[i++] = right[r++];
}
