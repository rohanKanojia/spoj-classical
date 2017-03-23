#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define SIZE 30
char adj[SIZE][SIZE];
int dist[SIZE][SIZE];
typedef pair<int, int> Point;
typedef pair<int, Point> Edge;
int dijkstrasShortestPath(Point start, Point end, int ROWS, int COLS);

int main() {
  while(true) {
    int ROWS, COLS;
    scanf("%d%d", &COLS, &ROWS);
    if(!ROWS && !COLS)
      break;

    for(int i = 0; i < ROWS; i++)
      scanf("%s", adj[i]);

    Point start, end;
    for(int i = 0; i < ROWS; i++) {
      for(int j = 0; j < COLS; j++) {
        if(adj[i][j] == 'S')
          start.first = i, start.second = j;
        else if(adj[i][j] == 'D')
          end.first = i, end.second = j;
      }
    }

    printf("%d\n", dijkstrasShortestPath(start, end, ROWS, COLS));
  }
  return 0;
}


int dijkstrasShortestPath(Point start, Point end, int ROWS, int COLS) {
  priority_queue<Edge, vector<Edge>, greater<Edge> > qq;
  qq.push(make_pair(0, start));
  memset(dist, 100, sizeof(dist));
  dist[start.first][start.second] = 0;

  while(!qq.empty()) {
    int curR = qq.top().second.first;
    int curC = qq.top().second.second;
    qq.pop();

    int dx[] = { 0, 1, 0, -1};
    int dy[] = { 1, 0, -1, 0};
    for(int i = 0; i < 4; i++) {
      int vi = curR + dx[i];
      int vj = curC + dy[i];
      
      if(vi >= 0 && vi < ROWS && vj >= 0 && vj < COLS && adj[vi][vj] != 'X') {
        int val = adj[vi][vj] == 'D' ? 0 : adj[vi][vj] - '0';

        if(dist[curR][curC] + val < dist[vi][vj]) {
          dist[vi][vj] = dist[curR][curC] + val;
          qq.push(make_pair(dist[vi][vj], make_pair(vi, vj)));
        }
      }
    }
  }
  return dist[end.first][end.second];
}
