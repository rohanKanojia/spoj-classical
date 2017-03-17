#include <iostream>
#include <vector>
using namespace std;

#define SIZE 100002
int dp[SIZE][2];
bool isVisited[SIZE][2];
class Graph {
  long long V;
public:
  vector<long long> *adj;
  Graph(long long vertices) : V(vertices) { adj = new vector<long long>[V]; }
  void addEdge(long long a, long long b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  ~Graph() { delete[] adj; }
};
long long getMDS(Graph& gg, long long curNode, bool isIncluded, long long parent);

int main() {
  long long N;
  cin >> N;
  
  Graph gg(N);
  for(long long i = 0; i < N-1; i++) {
    long long a, b;
    cin >> a >> b;
    gg.addEdge(a-1, b-1); 
  }
  
  long long ans = 1;
  if(N > 1) 
    ans = std::min(getMDS(gg, 1, true, -1), getMDS(gg, 1, false, -1));
  cout << ans << endl;
  return 0;
}

long long getMDS(Graph& gg, long long curNode, bool bIncluded, long long parent) {
  if(isVisited[curNode][bIncluded])
    return dp[curNode][bIncluded];
  
  isVisited[curNode][bIncluded] = true;
  long long cover = 0;
  for(long long i = 0; i < gg.adj[curNode].size(); i++) {
    int child = gg.adj[curNode][i];
    if(child != parent) {
      if(bIncluded == false) // if root is not included, there is only one way
        cover += getMDS(gg, child, true, curNode);
      else
        cover += std::min(getMDS(gg, child, true, curNode), getMDS(gg, child, false, curNode));
    }
  }
  
  dp[curNode][bIncluded] = bIncluded ? cover+1 : cover;
  
  return dp[curNode][bIncluded];
}
