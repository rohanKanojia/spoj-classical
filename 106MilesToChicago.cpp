#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
  while(true) {
    int N, nEdges;
    cin >> N;
    if(N == 0)
      break;

    vector<vector<double> > grid(N, vector<double>(N, 0));
    cin >> nEdges;
    for(int i = 0; i < nEdges; i++) {
      int a, b, probability;
      cin >> a >> b >> probability;
      grid[a-1][b-1] = grid[b-1][a-1] = (probability/100.);
    }
    for(int k = 0; k < N; k++) {
      for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) 
          grid[i][j] = std::max(grid[i][j], grid[i][k] * grid[k][j]);
      }
    }
    cout << std::fixed << std::setprecision(6) << grid[0][N-1]*100 
      << " percent" << endl;
  }
  return 0;
}
