#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define SIZE 10001
string ss;
int SA[SIZE], RA[SIZE], tempSA[SIZE], tempRA[SIZE], counting[SIZE];

void countingSort(int k, int n);
void constructSA(int n);

int main() {
  int T;
  cin >> T;

  while(T--) {
    cin >> ss;

    int n = ss.length();
    constructSA(n);

    // Since SA[0] is the lexicographically smallest string
    cout << SA[0] + 1 << endl;
  }
  return 0;
}

void countingSort(int k, int n) {
  int maxRange = std::max(256, n);
  memset(counting, 0, sizeof(counting));
  for(int i = 0; i < n; i++) {
    int curIndex = (i+k) % n;
    counting[RA[curIndex]]++;
  }

  int sum = 0;
  for(int i = 0; i < maxRange; i++) {
    int temp = counting[i];
    counting[i] = sum;
    sum += temp;
  }

  for(int i = 0; i < n; i++)
    tempSA[counting[RA[(SA[i]+k)%n]]++] = SA[i];
  for(int i = 0; i < n; i++)
    SA[i] = tempSA[i];
}

void constructSA(int n) {
  for(int i = 0; i < n; i++) {
    SA[i] = i;
    RA[i] = ss[i];
  }

  for(int k = 1; k < n; k <<=  1) {
    countingSort(k, n);
    countingSort(0, n);
    int rank;
    tempRA[SA[0]] = rank = 0;
    for(int i = 1; i < n; i++) 
      tempRA[SA[i]] = ((RA[SA[i-1]] == RA[SA[i]]) && 
        (RA[(SA[i-1]+k)%n] == RA[(SA[i] + k)%n]) ? rank : ++rank);

    for(int i = 0; i < n; i++)
      RA[i] = tempRA[i];
  }
}
