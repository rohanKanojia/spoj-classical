#include <iostream>
#include <string>
#include <cctype>
#include <set>
using namespace std;

bool checkTautogram(string line) {
  long long i = 0;
  set<char> leadingCharacters;
  do {
    while(i < line.length() && line[i] == ' ')
      i++;
    leadingCharacters.insert(toupper(line[i]));
    while(i < line.length() && line[i] != ' ')
      i++;
  } while(i < line.length());

  return leadingCharacters.size() == 1;
}

int main() {
  string line;
  while(true) {
    getline(cin, line);
    if(line.find("*") != string::npos)
      break;
    bool ans = checkTautogram(line);
    cout << (ans ? 'Y' : 'N') << endl;
  }
  return 0;
}
