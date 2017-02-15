#include <iostream>
#include <string>
#include <iterator>
#include <map>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long nCase;
    string possibleOutcomes[] = {
      "TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"
    };
    string ss;
    map<string, long long> nOccurences;
    cin >> nCase >> ss;

    nOccurences["HTT"] = 0;
    nOccurences["HTH"] = 0;
    nOccurences["HHT"] = 0;
    nOccurences["HHH"] = 0;
    nOccurences["TTT"] = 0;
    nOccurences["TTH"] = 0;
    nOccurences["THT"] = 0;
    nOccurences["THH"] = 0;

    for(long long i = 0; i < ss.length()-2; i++) {
      nOccurences[ss.substr(i, 3)]++;
    }

    cout << nCase << " ";
    for(long long i = 0; i < 8; i++) {
      cout << nOccurences[possibleOutcomes[i]] << " ";
    }
    cout << endl;
  }
  return 0;
}
