#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int dist[110][110];
bool isVisited[110][110];
#define INF 10000000
typedef pair<int, int> Cell;
bool myComp(Cell a, Cell b) { return dist[a.first][a.second] > dist[b.first][b.second]; }

int dijkstrasShortestReach(vector<vector<int> >& grid, int a, int b, int ROWS, int COLS) {
  priority_queue<Cell, vector<Cell>, decltype(&myComp)> pq(myComp);

  pq.push(make_pair(0, 0));
  dist[0][0] = grid[0][0];
  isVisited[0][0] = true;
  while(!pq.empty()) {
    Cell aCell = pq.top();
    pq.pop();

    int tempx = aCell.first, tempy = aCell.second;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for(int i = 0; i < 4; i++) {
      int cx = dx[i] + tempx;
      int cy = dy[i] + tempy;

      if(cx >= 0 && cx < ROWS && cy >= 0 && cy < COLS && isVisited[cx][cy] == false) {
        if(dist[cx][cy] > dist[tempx][tempy] + grid[cx][cy]) {
          dist[cx][cy] = dist[tempx][tempy] + grid[cx][cy];
          isVisited[cx][cy] = true;
          pq.push(make_pair(cx, cy));
        }
      }
    }
  }
  return dist[a-1][b-1];
}

int main() {
  int K;
  scanf("%d", &K);

  while(K--) {
    int M, N, a, b, T;
    scanf("%d%d", &M, &N);
    
    vector<vector<int> > grid(M, vector<int>(N));
    for(int i = 0; i < M; i++)
      for(int j = 0; j < N; j++) {
        scanf("%d", &grid[i][j]);
        dist[i][j] = INF;
        isVisited[i][j] = false;
      }

    scanf("%d%d%d", &a, &b, &T);

    int nRet = dijkstrasShortestReach(grid, a, b, M, N);
    if(nRet <= T)
      printf("YES\n%d\n", T-nRet);
    else
      printf("NO\n");
  }
  return 0;
}
