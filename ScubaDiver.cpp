#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define INF 10000000
typedef struct Cylinder { int nitrogen, oxygen, weight; } Cylinder;
int getMinimalWeight(int O, int N, vector<Cylinder>& cylinders);
int dp[1001][22][80];

int main() {
  int T;
  cin >> T;

  while(T--) {
    int N, O, nCylinders;
    cin >> O >> N >> nCylinders;
    vector<Cylinder> cylinders;
    for(int i = 0; i < nCylinders; i++) {
      Cylinder aCylinder;
      cin >> aCylinder.oxygen >> aCylinder.nitrogen >> aCylinder.weight;
      cylinders.push_back(aCylinder);
    }

    cout << getMinimalWeight(O, N, cylinders) << endl;
  }
  return 0;
}

int getMinimalWeight(int O, int N, vector<Cylinder>& cylinders) {
  for(int j = 0; j < 22; j++)
    for(int k = 0; k < 80; k++)
      dp[0][j][k] = INF;


  dp[0][0][0] = 0;

  for(int i = 1; i <= cylinders.size(); i++) {
    for(int j = 0; j < 22; j++) {
      for(int k = 0; k < 80; k++) {
          dp[i][j][k] = std::min( 
            dp[i-1][j][k],

            cylinders[i-1].weight + 
            dp[i-1][std::max(j-cylinders[i-1].oxygen, 0)][std::max(k-cylinders[i-1].nitrogen, 0)]
          );
      }
    }
  }

  return dp[cylinders.size()][O][N];
}
