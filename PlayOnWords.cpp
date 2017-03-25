#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

bool checkEulerPath(vector<vector<int> >& adj, vector<int>& inDegree,
  vector<int>& outDegree, vector<int>& found);
bool checkConnected(vector<vector<int> >& adj, vector<int>& found);

int main() {
  int T;
  cin >> T;

  while(T--) {
    int N;
    cin >> N;
    vector<int> inDegree(26, 0), outDegree(26, 0), found(26, 0);
    vector<vector<int> > adj(26, vector<int>(26, 0));

    for(int i = 0; i < N; i++) {
      string ss;
      cin >> ss;
      int u = ss[0]-'a', v = ss[ss.length()-1]-'a';
      outDegree[u]++;
      inDegree[v]++;
      adj[u][v] = found[u] = found[v] = 1;
    }
    if(checkEulerPath(adj, inDegree, outDegree, found))
      cout << "Ordering is possible." << endl;
    else
      cout << "The door cannot be opened." << endl;
  }
  return 0;
}

bool checkEulerPath(vector<vector<int> >& adj, vector<int>& inDegree,
  vector<int>& outDegree, vector<int>& found) {
  if(!checkConnected(adj, found))
    return false;
  // Checking properties of Eulerian path for directed graphs
  int nOut = 0, nIn = 0;
  for(int i = 0; i < found.size(); i++) {
    if(outDegree[i]-inDegree[i] == 1)
      nOut++;
    else if(inDegree[i] - outDegree[i] == 1)
      nIn++;
    else if(inDegree[i] != outDegree[i]) // till this point they must be equal
      return false;
  }
  return nOut <= 1 && nIn <= 1;
}

bool checkConnected(vector<vector<int> >& adj, vector<int>& found) {
  int i;
  queue<int> qq;
  vector<int> color(26, 0);
  for(i = 0; i < found.size(); i++) {
    if(!found[i])
      color[i] = 2;
  }
  for(i = 0; color[i] > 0; i++);
  // Start with first node
  color[i] = 1;
  qq.push(i);

  while(!qq.empty()) {
    i = qq.front();
    qq.pop();
    for(int j = 0; j < adj[i].size(); j++) {
      if((adj[i][j] || adj[j][i]) && color[j] == 0) {
        qq.push(j);
        color[j] = 1;
      }
    }
    color[i] = 2;
  }
  
  for(i = 0; i < found.size(); i++) { // there must be one connected component
    if(color[i] != 2) 
      return false;
  }

  return true;
}
