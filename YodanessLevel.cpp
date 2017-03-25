#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void mergeSort(vector<int>& arr, vector<int>& aux, int start, int end);
void merge(vector<int>& arr, vector<int>& aux, int start, int end);
int nInversions;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N;
    cin >> N;
    
    vector<string> yodaStr(N), orignalStr(N);
    vector<int> arr(N), aux(N);
    unordered_map<string, int> indexOf;
    for(int i = 0; i < N; i++)
      cin >> yodaStr[i];
    for(int i = 0; i < N; i++) {
      cin >> orignalStr[i];
      indexOf[orignalStr[i]] = i;
    }

    for(int i = 0; i < N; i++) 
      arr[i] = indexOf[yodaStr[i]];

    nInversions = 0;
    mergeSort(arr, aux, 0, arr.size()-1);
    cout << nInversions << endl;
  }
  return 0;
}


void mergeSort(vector<int>& arr, vector<int>& aux, int start, int end) {
  if(start < end) {
    int mid = (start+end)/2;
    mergeSort(arr, aux, start, mid);
    mergeSort(arr, aux, mid+1, end);
    merge(arr, aux, start, end);

    for(int i = start; i <= end; i++)
      arr[i] = aux[i];
  }
}

void merge(vector<int>& arr, vector<int>& aux, int start, int end) {
  int mid = (start+end)/2;
  int l = start, r = mid+1, curIndex = start;

  while(l <= mid && r <= end) {
    if(arr[l] < arr[r]) {
      aux[curIndex++] = arr[l++];
    }
    else if(arr[l] >= arr[r]) {
      nInversions += (mid - l+1);
      aux[curIndex++] = arr[r++];
    }
  }
  while(l <= mid)
    aux[curIndex++] = arr[l++];
  while(r <= end)
    aux[curIndex++] = arr[r++];
}
