#include <iostream>
#include <climits>
#include <vector>
#include <string>
using namespace std;

int main() {
  int N, M, startR, startC;
  cin >> N >> M;
  cin >> startR >> startC;
  vector<vector<int> > grid(N, vector<int>(M));
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      cin >> grid[i][j];


  for(int i = startC; i < M; i++)
    grid[startR-1][i] = grid[startR-1][i-1] - grid[startR-1][i];
  for(int i = startR; i < N; i++)
    grid[i][startC-1] = grid[i-1][startC-1] - grid[i][startC-1];

  for(int i = startR; i < N; i++) {
    for(int j = startC; j < M; j++) {
      int up, left = INT_MIN;
      up = grid[i-1][j] - grid[i][j];
      if(j-1 > 0)
        left = grid[i][j-1] - grid[i][j];
      grid[i][j] = std::max(up, left);
    }
  }

  if(grid[N-1][M-1] >= 0) 
    cout << "Y " << grid[N-1][M-1] << endl;
  else
    cout << "N\n";

  return 0;
}
