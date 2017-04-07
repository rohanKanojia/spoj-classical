#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

class Hashtable {
  string* table;
public:
  Hashtable() { 
    table = new string[101];
    for(int i = 0; i < 101; i++) table[i] = string("-"); 
  }
  int hashVal(string key) {
    int res = 0;
    for(int i = 0; i < key.length(); i++) 
      res += ((int)key[i] * (i+1));

    return (res*19) % 101;
  }
  void insert(string key) {
    bool bAlreadyPresent = false;
    for(int i = 0; i < 101; i++) {
      if(table[i] == key) {
        bAlreadyPresent = true;
        break;
      }
    }

    if(bAlreadyPresent) return;
    int index = hashVal(key);
    for(int j = 0; j < 20; j++) {
      int curIndex = (index + j*j + 23*j) % 101;
      if(table[curIndex] == string("-")) {
        table[curIndex] = key;
        break;
      }
    }
  }
  void deleteVal(string key) {
    int index = hashVal(key);
    for(int j = 0; j < 20; j++) {
      int curIndex = (index + j*j + 23*j)%101;
      if(table[curIndex] != string("-") && table[curIndex] == key) {
        table[curIndex] = string("-");
        break;
      }
    }
  }
  void print() {
    int size = 0;
    for(int i = 0; i < 101; i++)
      if(table[i] != string("-"))
        size++;
    cout << size << endl;
    for(int i = 0; i < 101; i++) {
      if(table[i] != string("-"))
        cout << i << ":" << table[i] << endl;
    }
  }
  ~Hashtable() { delete[] table; }
};

int main() {
  int T;
  cin >> T;

  while(T--) {
    int Q;
    cin >> Q;
    getchar();
    Hashtable hh;
    for(int i = 0; i < Q; i++) {
      string line, op, key;
      cin >> line;
      op = line.substr(0, line.find(":"));
      key = line.substr(line.find(":")+1, line.length()-line.find(":"));
      if(op[0] == 'A')
        hh.insert(key);
      else if(op[0] == 'D')
        hh.deleteVal(key);
    }
    hh.print();
  }
  return 0;
}
