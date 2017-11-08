#include <cstdio>
#include <iostream>
#include <string>
#include <map>

#define SIZE 250001
struct State {
  int len, link;
  std::map<char, int> next;
};
State states[SIZE*2];

class SuffixAutomata {
  int size, prev;
public:
  SuffixAutomata() : size(0), prev(0) {
    states[size].len = 0;
    states[size].link = -1;
    size++;
  }

  State& get(int index)   { return states[index]; } 

  void extend(char aChar) {
    int curIndex = size++;
    states[curIndex].len = states[prev].len + 1;

    int p = prev;
    while(p != -1 && !(states[p].next.count(aChar))) {
      states[p].next[aChar] = curIndex;
      p = states[p].link;
    }

    if(p == -1)
      states[curIndex].link = 0;
    else {
      int q = states[p].next[aChar];
      if(states[p].len + 1 == states[q].len) {
        states[curIndex].link = q;
      }
      else {
        int clone = size++;
        states[clone].len  = states[p].len + 1;
        states[clone].next = states[q].next;
        states[clone].link = states[q].link;

        while(p != -1 && states[p].next[aChar] == q) {
          states[p].next[aChar] = clone;
          p = states[p].link;
        }
        states[q].link = states[curIndex].link = clone;
      }
    }
    prev = curIndex;
  }
};

std::string lcs(std::string& s1, std::string& s2) {
  SuffixAutomata sa;
  for(int i = 0; i < s1.length(); i++) 
    sa.extend(s1[i]);

  int v = 0, l = 0, best = 0, bestPos = 0;
  for(int i = 0; i < s2.length(); i++) {
    while(v && !sa.get(v).next.count(s2[i]) > 0) {
      v = sa.get(v).link;
      l = sa.get(v).len;
    }

    if(sa.get(v).next.count(s2[i])) {
      v = sa.get(v).next[s2[i]];
      l++;
    }
    if(l > best)
      best = l, bestPos = i;
  }

  return s2.substr(bestPos - best + 1, best);
}

int main() {
  std::string s1, s2;
  
  std::getline(std::cin, s1);
  std::getline(std::cin, s2);
  
  printf("%ld\n", lcs(s1, s2).length());
  return 0;
}
