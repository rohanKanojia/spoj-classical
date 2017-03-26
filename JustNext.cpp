#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool getNextPermutation(vector<int>& arr);

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);
    vector<int> arr(N);
    for(int i = 0; i < N; i++)
      scanf("%d", &arr[i]);

    if(!getNextPermutation(arr)) 
      printf("-1\n");
    else {
      for(int i = 0; i < N; i++)
        printf("%d", arr[i]);
      printf("\n");
    }
  }
  return 0;
}

bool getNextPermutation(vector<int>& arr) {
  int i = arr.size()-1;
  while(i > 0 && arr[i-1] >= arr[i]) // 1. Find greatest i such that arr[i] < arr[i+1]
    i--;

  if(i <= 0)
    return false;

  int j = arr.size()-1;
  while(arr[j] <= arr[i-1]) // 2. Find greatest j such that arr[j] > arr[i]
    j--;
  
  int temp = arr[i-1]; // 3. swap(arr, j, i-1)
  arr[i-1] = arr[j];   
  arr[j] = temp;

  j = arr.size()-1;
  while(i < j) {  // 4. reverse(arr, i, j)
    temp = arr[i];
    arr[i++] = arr[j];
    arr[j--] = temp;
  }
  return true;
}
