#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int f, s, g, u, d, ans = -1;
  scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);

  vector<bool> isVisited(f+1, false);
  queue<pair<int, int> > aQueue; // <Node, Distance>
  aQueue.push(make_pair(s, 0));
  isVisited[s] = true;

  while(!aQueue.empty()) {
    pair<int, int> curElem = aQueue.front();
    aQueue.pop();
    int curNode = curElem.first, curDist = curElem.second;

    if(curNode == g) {
      ans = curDist;
      break;
    }
    if(curNode+u <= f && isVisited[curNode+u] == false) {
      aQueue.push(make_pair(curNode+u, curDist+1));
      isVisited[curNode+u] = true;
    }
    if(curNode-d >= 1 && isVisited[curNode-d] == false) {
      aQueue.push(make_pair(curNode-d, curDist+1));
      isVisited[curNode-d] = true;
    }
  }
  if(ans == -1)
    printf("use the stairs\n");
  else
    printf("%d\n", ans);
  return 0;
}
