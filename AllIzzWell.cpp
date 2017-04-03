#include <iostream>
#include <string>
#include <vector>
using namespace std;

string target = "ALLIZZWELL";
bool dfs(vector<string>& arr, int i, int j, int tIndex, vector<vector<bool > >& isVisited) {
  if(arr[i][j] != target[tIndex])
    return false;
  else if(tIndex == target.size()-1 && arr[i][j] == target[tIndex])
    return true;
  isVisited[i][j] = true;
  int dr[] =  {1,1,1, 0, 0, -1, -1,-1};
  int dc[] =  {1,-1,0,1,-1, 1, -1, 0};
  bool bPossible = false;
  for(int k= 0; k < 8; k++) {
    int curR = (i + dr[k]);
    int curC = (j + dc[k]);
    if(curR >= 0 && curC >= 0 && curR < arr.size() && curC < arr[0].size()) {
      if(isVisited[curR][curC] == false && dfs(arr, curR, curC, tIndex+1, isVisited)) {
        bPossible = true;
        break;
      }
    }
  }
  isVisited[i][j] = false;
  return bPossible;
}

int main() {
  int T;
  cin >> T;

  while(T--) {
    int M, N;
    cin >> M >> N;
    vector<string> arr(M);
    vector<vector<bool> > isVisited(M, vector<bool>(N, false));
    for(int i = 0; i < M; i++)
      cin >> arr[i];

    bool bPossible = false;
    for(int i = 0; i < M; i++) {
      for(int j = 0;j < N;j++) {
        if(arr[i][j] == 'A' && dfs(arr, i, j, 0, isVisited)) {
          bPossible = true;
          break;
        }
      }
    }

    cout << (bPossible ? "YES" : "NO") << endl; 
  }
  return 0;
}
