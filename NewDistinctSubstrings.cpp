#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define SIZE 50001

char aStr[SIZE]; // input string
int SA[SIZE], RA[SIZE], tempSA[SIZE], tempRA[SIZE], counting[SIZE];
int LCP[SIZE], PLCP[SIZE], phi[SIZE];

void countingSort(int k, int n) {
  int maxRange = std::max(300, n);
  memset(counting, 0, sizeof(counting));
  for(int i = 0; i < n; i++) {
    int curIndex = i+k < n ? RA[i+k] : 0;
    counting[curIndex]++; 
  }

  int sum = 0;
  for(int i = 0; i < maxRange; i++) {
    int temp = counting[i];
    counting[i] = sum;
    sum += temp;
  }

  for(int i = 0; i < n; i++)
    tempSA[counting[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
  for(int i = 0; i < n; i++)
    SA[i] = tempSA[i];
}

void constructSA(int n) {
  for(int i = 0; i < n; i++) {
    SA[i] = i;
    RA[i] = aStr[i];
  }

  for(int k = 1; k < n; k <<= 1) {
    countingSort(k, n);
    countingSort(0, n);
    int rank;
    tempRA[SA[0]] = rank = 0;
    for(int i = 1; i < n; i++)
      tempRA[SA[i]] = (RA[SA[i-1]] == RA[SA[i]] && RA[SA[i-1]+k] == RA[SA[i]+k]) ? rank : ++rank;
    for(int i = 0; i < n; i++)
      RA[i] = tempRA[i];
    if(RA[SA[n-1]] == n-1)
      break;
  }
}


void computeLCP(int n) { // kasai's algo
  phi[SA[0]] = -1;
  for(int i = 1; i < n; i++)
    phi[SA[i]] = SA[i-1];
  int l = 0;
  for(int i = 0; i < n; i++) {
    if(phi[i] == -1) {
      PLCP[i] = 0;
      continue;
    }
    while(aStr[i+l] == aStr[phi[i] + l])
      l++;
    PLCP[i] = l;
    l = std::max(l-1, 0);
  }
  for(int i = 0; i < n; i++)
    LCP[i] = PLCP[SA[i]];
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%s", aStr);
    int n = strlen(aStr);
    aStr[n++] = '$';
    constructSA(n);

    computeLCP(n);
    int substring = 0;
    for(int i = 0; i < n; i++) {
      substring += (n - 1 - SA[i]);
      substring -= LCP[i];
    }
    printf("%d\n", substring);
  }
  return 0;
}
