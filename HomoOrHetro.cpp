#include <cstdio>
#include <map>

class ListManager {
  std::map<int, int> listFreqMap;
  int nDuplicates, nDistincts;
public:
  ListManager() : nDuplicates(0), nDistincts(0) { }

  void add(int aItem) {
    if(listFreqMap.find(aItem) == listFreqMap.end()) {
      listFreqMap[aItem]++;
      nDistincts++;
    }
    else {
      listFreqMap[aItem]++;

      if(listFreqMap[aItem] > 1)
        nDuplicates++;
      else
        nDistincts++;
    }
  }

  void remove(int aItem) {
    if(listFreqMap.find(aItem) != listFreqMap.end() && listFreqMap[aItem] > 0) {
      if(listFreqMap[aItem] == 1)
        nDistincts--;
      else if(listFreqMap[aItem] > 1)
        nDuplicates--;

      listFreqMap[aItem]--;
    }
  }

  void printListState() {
    if(nDistincts > 1)
      printf("%s\n", nDuplicates > 0 ? "both" : "hetero");
    else
      printf("%s\n", nDuplicates > 0 ? "homo" : "neither");
  }
};


int main() {
  int nT, nInput;
  char option[100];
  ListManager listManager;

  scanf("%d", &nT);

  while(nT--) {
    scanf("%s%d", option, &nInput);
    
    if(option[0] == 'i')
      listManager.add(nInput);
    else
      listManager.remove(nInput);
    
    listManager.printListState();
  }
  return 0;
}
