#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
#include <list>
using namespace std;

#define SIZE 100001
class Graph {
  long long V;
  long long nEdges;
  list<long long> *adj;
public:
  Graph(long long V) : nEdges(0) {
    this->V = V;
    adj = new list<long long>[V];
  }
  void addEdge(long long v, long long w) {
    adj[v].push_back(w);
    nEdges++;
  }
  list<long long>& getNeighbours(long long v)   { return adj[v]; }
  long long getNodes() const                    { return V; }
  long long getEdges() const                    { return nEdges; }
};
void buildGraph(Graph& gg);
bool isPrime[SIZE];
void sieveOfEratosthenes(long long N);
long long breadthFirstSearch(Graph& gg, long long start, long long end);

int main() {
  long long T;
  Graph gg(SIZE);
  sieveOfEratosthenes(100000);
  buildGraph(gg);
  scanf("%lld", &T);
  
  while(T--) {
    long long a, b;
    scanf("%lld%lld", &a, &b);

    long long ans = breadthFirstSearch(gg, a, b);
    if(ans == -1)
      printf("Impossible\n");
    else
      printf("%lld\n", ans);
  }
  return 0;
}

void sieveOfEratosthenes(long long N) {
  memset(isPrime, true, sizeof(isPrime));

  for(long long i = 2; i*i <= N; i++) {
    if(isPrime[i] == true) {
      for(long long j = 2*i; j <= N; j += i)
        isPrime[j] = false;
    }
  }
}

void buildGraph(Graph& gg) {
  for(long long i = 1001; i < 100000; i++) {
    if(isPrime[i]) {
      long long pow10 = 1;
      for(long long j = 0; j < 4; j++) {
        long long prefix, suffix, digit;
        prefix = i / pow10;
        digit = prefix % 10;
        suffix = i % pow10;
        prefix = prefix / 10;
        for(long long k = 0; k < 10; k++) {
          if(k != digit) {
            long long curDigit = prefix * pow10 * 10 + pow10 * k + suffix;
            if(isPrime[curDigit])
              gg.addEdge(i, curDigit);
          }
        }
        pow10 *= 10;
      }
    }
  }
}

long long breadthFirstSearch(Graph& gg, long long start, long long end) {
  if(start == end)
    return 0;
  queue<pair<long long, long long> > qq;
  vector<bool> isVisited(SIZE, false);

  isVisited[start] = true;
  qq.push(make_pair(start, 0));

  while(!qq.empty()) {
    pair<long long, long long> curNode = qq.front();
    qq.pop();

    list<long long> neighbours = gg.getNeighbours(curNode.first);
    for(auto ii = neighbours.begin(); ii != neighbours.end(); ii++) {
      if(isVisited[*ii] == false) {
        isVisited[*ii] = true;
        if(*ii == end)
          return curNode.second + 1;
        qq.push(make_pair(*ii, curNode.second + 1));
      }
    }
  }
  return -1;
}
