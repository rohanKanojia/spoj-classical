#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  while(T--) {
    int N;
    cin >> N;
    vector<vector<int> > dist(N, vector<int>(N));

    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
        cin >> dist[i][j];
    
    for(int i = 0; i < N; i++) {
      for(int j = i+1; j < N; j++) {
        bool bNeighbour = true;

        for(int k = 0; k < N; k++) {
          if(k == i || k == j)
            continue;
          else if(dist[i][j] == dist[i][k] + dist[k][j]) {
            bNeighbour = false;
            break;
          }
        }
        if(bNeighbour)
          cout << i+1 << " " << j+1 << endl;
      }
    }
  }
  return 0;
}
