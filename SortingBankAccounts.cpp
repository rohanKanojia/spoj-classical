#include <cstdio>
#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

char a1[100], a2[100], a3[100], a4[100], a5[100], a6[100];

int main() {
  long long T;
  scanf("%lld", &T);
  while(T--) {
    map<string, long long> aMap;
    long long N;
    scanf("%lld\n", &N);

    for(long long i = 0; i < N; i++) {
      scanf("%s%s%s%s%s%s", a1, a2, a3, a4, a5, a6);
      string space(" ");
      string curNo = a1 + space + a2 + space + a3 + space + a4 + space + a5 + space + a6;
      aMap[curNo]++; 
    }

    map<string, long long>::iterator ii;
    for(ii = aMap.begin(); ii != aMap.end(); ii++) {
      printf("%s %lld\n", (ii->first).c_str(), ii->second);
    }
    printf("\n");
  }
}
