#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

void dfsUtil(vector<string>& grid, int i, int j, int& nPaths, vector<vector<bool> >& isVisited
  , int M, int N) {
  stack<pair<int, int> > aStack;
  aStack.push(make_pair(i, j));
  isVisited[i][j] = true;

  while(!aStack.empty()) {
    pair<int, int> aPair = aStack.top();
    aStack.pop();

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,1,-1};
    for(int i = 0; i < 4; i++) {
      int cx = aPair.first + dx[i];
      int cy = aPair.second + dy[i];

      if(cx < 0 || cx > M-1 || cy < 0 || cy > N-1 || 
         grid[cx][cy] == '#' || isVisited[cx][cy] == true)
        continue;
      if(cx == 0 || cy == 0 || cx == M-1 || cy == N-1)
        nPaths++;
      aStack.push(make_pair(cx, cy));
      isVisited[cx][cy] = true;
    }
  }
}

bool dfs(vector<string>& grid, int M, int N) {
  int nExits = 0, nPaths = 0;
  bool bFound = false;
  for(int i = 0; i < M && !bFound; i++) {
    for(int j = 0; j < N && !bFound; j++) {
      if(grid[i][j] == '.' && (i == 0 || j == 0 || i == M-1 || j == N-1)) {
        vector<vector<bool> > isVisited(M, vector<bool>(N, false)); 
        dfsUtil(grid, i, j, nPaths, isVisited, M, N);
        if(nPaths > 0)
          bFound = true;

      }
    }
  }

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      if(grid[i][j]== '.' && (i == 0 || j == 0 || i == M-1 || j == N-1))
        nExits++;
    }
  }
  return !(nPaths > 1 || nPaths == 0 || nExits > 2);
}

int main() {
  int T;
  cin >> T;

  while(T--) {
    int M, N;
    cin >> M >> N;
    vector<string> grid(M);
    for(int i = 0; i < M; i++)
      cin >> grid[i];

    cout << (dfs(grid, M, N) ? "valid\n" : "invalid\n");
  }
  return 0;
}
