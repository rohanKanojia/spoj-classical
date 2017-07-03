#include <cstdio>
#include <string>
#include <map>
#include <set>

int main() {
  int T;
  scanf("%d", &T);

  for(int t = 1; t <= T; t++) {
    int N;
    scanf("%d", &N);

    std::set<std::string> aStepList;
    std::map<std::string, bool> inDeg, outDeg;
    std::map<std::string, std::string> aAdjTable;

    for(int i = 0; i < N-1; i++) {
      char aBuffer[1000];
      scanf("%s", aBuffer);
      std::string startPoint(aBuffer);
      outDeg[startPoint] = true;

      scanf("%s", aBuffer);
      std::string endPoint(aBuffer);
      inDeg[endPoint] = true;

      aStepList.insert(startPoint);
      aStepList.insert(endPoint);
      aAdjTable[startPoint] = endPoint;
    }

    std::string routeStartPoint;
    std::set<std::string>::iterator aIter = aStepList.begin();
    for(; aIter != aStepList.end(); aIter++) {
      if(inDeg[*aIter] == false && outDeg[*aIter] == true) {
        routeStartPoint = *aIter;
        break;
      }
    }

    printf("Scenario #%d:\n", t);
    for(int i = 0; i < N; i++, routeStartPoint = aAdjTable[routeStartPoint])
      printf("%s\n", routeStartPoint.c_str());

  }
  return 0;
}
