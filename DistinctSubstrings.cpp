#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct suffix {
  long long index;
  long long rank[2];
} suffix;

long long getDistinctSubstrings(string& ss);
void buildSuffixArray(string& txt, vector<long long>& suffAr);
void kasai(string& txt, vector<long long>& suffAr, vector<long long>& lcp);
bool comp(suffix a, suffix b);

int main() {
  long long T;
  cin >> T;
  while(T--) {
    string ss;
    cin >> ss;

    cout << getDistinctSubstrings(ss) << endl;
  }
  return 0;
}

void buildSuffixArray(string& txt, vector<long long>& suffAr) {
  vector<suffix> suffixes(txt.length());

  for(long long i = 0; i < txt.length(); i++) {
    suffixes[i].index = i;
    suffixes[i].rank[0] = txt[i];
    suffixes[i].rank[1] = (i+1 < txt.length() ? txt[i+1] : -1);
  }

  sort(suffixes.begin(), suffixes.end(), comp);

  vector<long long> indexMap(txt.length());
  for(long long k = 4; k < 2*txt.length(); k *= 2) {
    long long rank = 0, prevRank = suffixes[0].rank[0];
    suffixes[0].rank[0] = rank;
    indexMap[suffixes[0].index] = 0;

    for(long long i = 1; i < txt.length(); i++) {
      if(suffixes[i].rank[0] == prevRank && suffixes[i].rank[1] == suffixes[i-1].rank[1]) {
        prevRank = suffixes[i].rank[0];
        suffixes[i].rank[0] = rank;
      }
      else {
        prevRank = suffixes[i].rank[0];
        suffixes[i].rank[0] = ++rank;
      }
      indexMap[suffixes[i].index] = i;
    }

    for(long long i = 0; i < txt.length(); i++) {
      long long nextIndex = suffixes[i].index + k/2;
      suffixes[i].rank[1] = nextIndex < txt.length() ? suffixes[indexMap[nextIndex]].rank[0] : -1;
    }

    sort(suffixes.begin(), suffixes.end(), comp);
  }

  for(long long i = 0; i < txt.length(); i++)
    suffAr[i] = suffixes[i].index;
}

bool comp(suffix a, suffix b) {
  if(a.rank[0] == b.rank[0])
    return a.rank[1] < b.rank[1];
  else
    return a.rank[0] < b.rank[0];
}

void kasai(string& txt, vector<long long>& suffAr, vector<long long>& lcp) {
  long long N = suffAr.size();

  vector<long long> invSuff(N, 0);
  for(long long i = 0; i < N; i++)
    invSuff[suffAr[i]] = i;

  long long k = 0;
  for(long long i = 0; i < N; i++) {
    if(invSuff[i] == N-1) {
      k = 0;
      continue;
    }
    long long j = suffAr[invSuff[i]+1];

    while(i+k < N && j+k < N && txt[i+k] == txt[j+k])
      k++;
    lcp[invSuff[i]] = k;
    if(k > 0)
      k--;
  }
}

long long getDistinctSubstrings(string& ss) {
  vector<long long> suffAr(ss.length());
  vector<long long> lcp(ss.length(), 0);

  buildSuffixArray(ss, suffAr);
  kasai(ss, suffAr, lcp);

  long long ans = 0;
  for(long long i = 0; i < suffAr.size(); i++)
    ans += (ss.length()-suffAr[i] - lcp[i]);
  return ans;
}
