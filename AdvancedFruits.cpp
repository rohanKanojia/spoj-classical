#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

void backTrack(std::vector<std::vector<int> >& dp, std::vector<bool>& lcsInS1, std::vector<bool>& lcsInS2, std::string s1, std::string s2) {
  for(int i = lcsInS1.size(), j = lcsInS2.size(); i > 0 && j > 0; ) {
    if(s1[i-1] == s2[j-1]) {
      lcsInS1[i-1] = true;
      lcsInS2[j-1] = true;
      i--, j--;
    }
    else {
      if(dp[i-1][j] >= dp[i][j-1])
        i--;
      else
        j--;
    }
  }
}

std::string mergeStrings(std::string s1, std::string s2, std::vector<bool>& lcsInS1, std::vector<bool>& lcsInS2) {
  std::string nRet;
  int i = 0, j = 0;

  for(; i < s1.length() && j < s2.length();) {
    int nS1 = i, nS2 = j;
    for(; nS1 < s1.length() && lcsInS1[nS1] == false; nS1++)
      nRet.push_back(s1[nS1]);
    for(; nS2 < s2.length() && lcsInS2[nS2] == false; nS2++)
      nRet.push_back(s2[nS2]);

    while(nS1 < s1.length() && nS2 < s2.length() && lcsInS1[nS1] && lcsInS2[nS2]) {
      nRet.push_back(s1[nS1]);
      nS1++, nS2++;
    }

    i = nS1, j = nS2;
  }

  while(i < s1.length()) nRet.push_back(s1[i++]);
  while(j < s2.length()) nRet.push_back(s2[j++]);

  return nRet;
}

int main() {
  char aStr1[101], aStr2[101];
  while(scanf("%s%s", aStr1, aStr2) > 0) {
    std::string s1(aStr1), s2(aStr2);
    std::vector<std::vector<int> > dp(s1.size()+1, std::vector<int>(s2.size()+1, 0));

    for(int i = 1; i <= s1.length(); i++) {
      for(int j = 1; j <= s2.length(); j++) {
        if(s1[i-1] == s2[j-1])
          dp[i][j] = 1 + dp[i-1][j-1];
        else
          dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
      }
    }

    std::vector<bool> lcsInS1(s1.length(), false);
    std::vector<bool> lcsInS2(s2.length(), false);
    backTrack(dp, lcsInS1, lcsInS2, s1, s2);

    printf("%s\n", mergeStrings(s1, s2, lcsInS1, lcsInS2).c_str());
  }
  return 0;
}
