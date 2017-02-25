#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  string s1, s2;

  while(cin >> s1) {
    cin >> s2;

    vector<long long> freq1(26, 0), freq2(26, 0);
    for(long long i = 0; i < s1.length(); i++) 
      freq1[s1[i]-'a']++;
    for(long long i = 0; i < s2.length(); i++)
      freq2[s2[i]-'a']++;


    for(long long i = 0; i < 26; i++) {
      if(freq1[i] > 0 && freq2[i] > 0) {
        long long minFreq = std::min(freq1[i], freq2[i]);

        while(minFreq--)
          cout << (char)('a'+i);
      }
    }
    cout << endl;
  }
  return 0;
}
