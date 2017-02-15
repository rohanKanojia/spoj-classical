#include <cstdio>
#include <vector>
#include <string>

std::string printPattern(int N) {
  if(N == 0)
    return std::string("0");
  else {
    std::vector<int> binaryIndices;
    int i = 0;
    while(N) {
      if(N&1) binaryIndices.push_back(i);
      N >>= 1;
      i++;
    }

    std::string aStr;
    for(int i = binaryIndices.size()-1; i >= 0; i--) {
      aStr += "2";

      if(binaryIndices[i] != 1) 
        aStr += ("(" + printPattern(binaryIndices[i]) + ")");

      if(i > 0)
        aStr += "+";
    }
    return aStr;
  }
}

int main() {
  printf("137=%s\n", printPattern(137).c_str()); 
  printf("1315=%s\n", printPattern(1315).c_str()); 
  printf("73=%s\n", printPattern(73).c_str()); 
  printf("136=%s\n", printPattern(136).c_str()); 
  printf("255=%s\n", printPattern(255).c_str()); 
  printf("1384=%s\n", printPattern(1384).c_str()); 
  printf("16385=%s\n", printPattern(16385).c_str()); 
  return 0;
}
