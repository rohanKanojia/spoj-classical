#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

int bfs(pair<int, int> start, pair<int, int> end);
int dist[9][9][9][9];

int main() {
  int T;
  scanf("%d", &T);

  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      for(int k = 0; k < 9; k++)
        for(int l = 0; l < 9; l++)
          dist[i][j][k][l] = -1;

  
  while(T--) {
    char s1[10], s2[10];
    scanf("%s%s", s1, s2);
    pair<int, int> start, end;
    start.first = s1[0]-'a';
    start.second = s1[1]-'1';

    end.first = s2[0]-'a';
    end.second = s2[1]-'1';

    printf("%d\n", bfs(start, end));
  }
  return 0;
}

int bfs(pair<int, int> start, pair<int, int> end) {
  if(start == end)
    return 0;
  if(dist[start.first][start.second][end.first][end.second] != -1)
    return dist[start.first][start.second][end.first][end.second];
  if(dist[end.first][end.second][start.first][start.second] != -1)
    return dist[end.first][end.second][start.first][start.second];

  int dr[] = {1, 2, -1, -2, 2, 1, -1, -2};
  int dc[] = {-2, -1, -2, -1, 1, 2, 2, 1};
  queue<pair<int, pair<int, int> > > qq;
  vector<vector<bool> > isVisited(9, vector<bool>(9, false));
  qq.push(make_pair(0, start));
  isVisited[start.first][start.second] = true;

  while(!qq.empty()) {
    pair<int, int> curNode = qq.front().second;
    int curDistance = qq.front().first;
    qq.pop();

    for(int i = 0; i < 8; i++) {
      int curR = curNode.first + dr[i];
      int curC = curNode.second + dc[i];
      if(curR >= 0 && curR < 8 && curC >= 0 && curC < 8 && isVisited[curR][curC] == false) {
        isVisited[curR][curC] = true;
        dist[start.first][start.second][curR][curC] = curDistance + 1;
        qq.push(make_pair(curDistance+1, make_pair(curR, curC)));
      }
    }
  }

  return dist[start.first][start.second][end.first][end.second];
}
