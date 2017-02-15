#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define INF INT_MAX
void breadthFirstSearch(vector<string>& arr, queue<pair<long long, long long> >& aQueue, vector<vector<long long> >& distance, long long ROWS, long long COLS);
bool AreValidCoordinates(long long r, long long c, long long ROWS, long long COLS);

int main() {
  long long T;
  cin >> T;
  while(T--) {
    long long m, n;
    vector<string> arr;
    cin >> m >> n;

    for(long long i = 0; i < m; i++) {
      string tmp;
      cin >> tmp;
      arr.push_back(tmp);
    }

    vector<vector<long long> > distanceArr(m, vector<long long>(n, INF));
    queue<pair<long long, long long> > aQueue;

    for(long long i = 0; i < m; i++) {
      for(long long j = 0; j < n; j++) {
        if(arr[i][j] == '1') {
          aQueue.push(make_pair(i, j));
          distanceArr[i][j] = 0;
        }
      }
    }

    
    breadthFirstSearch(arr, aQueue, distanceArr, m, n);
    for(long long i = 0; i < m; i++) {
      for(long long j = 0; j < n; j++)
        cout << distanceArr[i][j] << " ";
      cout << endl;
    }
  }
  return 0;
}

void breadthFirstSearch(vector<string>& arr, queue<pair<long long, long long> >& aQueue, vector<vector<long long> >& distance, long long ROWS, long long COLS) {
  vector<vector<bool> > isVisited(ROWS, vector<bool>(COLS, false));  

  while(!aQueue.empty()) {
    pair<long long, long long> curElement = aQueue.front();
    aQueue.pop();

    // check all neighbours :
    // 1. (x+1, y)
    if(AreValidCoordinates(curElement.first+1, curElement.second, ROWS, COLS) && !isVisited[curElement.first+1][curElement.second]) {
      distance[curElement.first+1][curElement.second] = std::min(distance[curElement.first][curElement.second] + 1,
                                                                 distance[curElement.first+1][curElement.second]);
      isVisited[curElement.first+1][curElement.second] = true;
      aQueue.push(make_pair(curElement.first+1, curElement.second));
    }
    // 2. (x, y+1)
    if(AreValidCoordinates(curElement.first, curElement.second+1, ROWS, COLS) && !isVisited[curElement.first][curElement.second+1]) {
      distance[curElement.first][curElement.second+1] = std::min(distance[curElement.first][curElement.second] + 1,
                                                                 distance[curElement.first][curElement.second+1]);
      isVisited[curElement.first][curElement.second+1] = true;
      aQueue.push(make_pair(curElement.first, curElement.second+1));
    }
    // 3. (x-1, y)
    if(AreValidCoordinates(curElement.first-1, curElement.second, ROWS, COLS) && !isVisited[curElement.first-1][curElement.second]) {
      distance[curElement.first-1][curElement.second] = std::min(distance[curElement.first][curElement.second] + 1,
                                                                 distance[curElement.first-1][curElement.second]);
      isVisited[curElement.first-1][curElement.second] = true;
      aQueue.push(make_pair(curElement.first-1, curElement.second));
    }
    // 4. (x, y-1)
    if(AreValidCoordinates(curElement.first, curElement.second-1, ROWS, COLS) && !isVisited[curElement.first][curElement.second-1]) {
      distance[curElement.first][curElement.second-1] = std::min(distance[curElement.first][curElement.second] + 1,
                                                                 distance[curElement.first][curElement.second-1]);
      isVisited[curElement.first][curElement.second-1] = true;
      aQueue.push(make_pair(curElement.first, curElement.second-1));
    }
  }
}

bool AreValidCoordinates(long long r, long long c, long long ROWS, long long COLS) {
  return r >= 0 && r < ROWS && c >= 0 && c < COLS;
}
