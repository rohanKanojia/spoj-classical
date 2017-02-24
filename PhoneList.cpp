#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define ALPHABET_SIZE 10

class TNode {
  long long nWords;
  TNode *children[ALPHABET_SIZE];
public:
  TNode() : nWords(0) { for(long long i = 0; i < ALPHABET_SIZE; i++) children[i] = NULL; }
  void setChild(long long index, TNode *val) { children[index] = val; }
  TNode *getChild(long long index)           { return children[index]; }
  long long getWordCount() const             { return nWords; }
  void setWordCount(long long count)         { nWords = count; }
};

class Trie {
  TNode *root;
  long long count;
public:
  Trie() : root(new TNode()) { }
  void add(std::string item) {
    TNode *curNode = root;
    
    for(long long i = 0; i < item.length()+1; i++) {
      long long cIndex = item[i]-'0';
      if(!curNode->getChild(cIndex)) {
        TNode *newNode = new TNode();
        curNode->setChild(cIndex, newNode);
      }
      if(curNode != root)
        curNode->setWordCount(curNode->getWordCount() + 1);
      curNode = curNode->getChild(cIndex);
    }
    count++;
  }
  long long findPartially(std::string item) {
    TNode *curNode = root;

    for(long long i = 0; i < item.length(); i++) {
      if(!curNode->getChild(item[i]-'0'))
        return 0;
      curNode = curNode->getChild(item[i]-'0');
    }
    return curNode == NULL ? 0 : curNode->getWordCount();
  }
};

int main() {
  long long T;
  cin >> T;
  while(T--) {
    Trie* tt = new Trie();;
    long long N;
    cin >> N;
    vector<string> arr(N);
    for(long long i = 0; i < N; i++) {
      cin >> arr[i];
      tt->add(arr[i]);
    }

    bool bConsistent = true;
    for(long long i = 0; i < N; i++) {
      if(tt->findPartially(arr[i]) > 1) {
        bConsistent = false;
        break;
      }
    }

    cout << (bConsistent ? "YES" : "NO") << endl;
    delete tt;
  }
  return 0;
}
