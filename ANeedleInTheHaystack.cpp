#include <iostream>
#include <vector>
#include <string>
using namespace std;

void KMP(string& ss, string& pat);
void computeLPS(vector<long long>& lps, string& pat);

int main() {
  long long N;

  while(cin >> N) {
    string ss, pat;
    cin >> pat >> ss;

    KMP(ss, pat);
    cout << endl;
  }
  return 0;
}

void KMP(string& ss, string& pat) {
  long long M = pat.length(), N = ss.length();
  vector<long long> lps(M);

  computeLPS(lps, pat);

  for(long long i = 0, j = 0; i < N; ) {
    if(pat[j] == ss[i]) {
      i++;
      j++;
    }
    if(j == M) {
      // pattern found at index i - j
      cout << i - j << endl;
      // reset j to next search position
      j = lps[j-1];
    }
    else if(i < N && pat[j] != ss[i]) {
      if(j != 0)
        j = lps[j-1];
      else
        i++;
    }
  }
}

void computeLPS(vector<long long>& lps, string& pat) {
  long long len = 0, i;
  lps[0] = 0; // lps[0] is always zero

  for(i = 1; i < pat.length(); ) {
    if(pat[i] == pat[len]) 
      lps[i++] = ++len;
    else { // pat[i] != pat[len]
      if(len != 0)
        len = lps[len-1]; // reset len
      else
        lps[i++] = 0;
    }
  }
}
