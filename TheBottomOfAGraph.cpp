#include <cstdio>
#include <vector>
#include <set>
#include <stack>

class Graph {
  int V;
public:
  std::vector<int> *adj;
  Graph(int nVertices) 
    : V(nVertices), adj(new std::vector<int>[nVertices]) { }
  void addEdge(int from, int to)                         { adj[from].push_back(to); }
};

void dfs(Graph& aGraph, std::vector<bool>& isVisited, int aVertex, std::stack<int>& aNodeStack) {
  if(!isVisited[aVertex]) {
    isVisited[aVertex] = true;

    for(int i = 0; i < aGraph.adj[aVertex].size(); i++)
      dfs(aGraph, isVisited, aGraph.adj[aVertex][i], aNodeStack);
    aNodeStack.push(aVertex);
  }
}

void dfsTranspose(Graph& aGraph, std::vector<bool>& isVisited, int aVertex,
  std::vector<std::vector<int> >& connectedComponents, std::vector<int>& componentVertexMap, int& nGroups) {
  
  if(!isVisited[aVertex]) {
    isVisited[aVertex] = true;

    for(int i = 0; i < aGraph.adj[aVertex].size(); i++)
      dfsTranspose(aGraph, isVisited, aGraph.adj[aVertex][i], connectedComponents, componentVertexMap, nGroups);
    
    connectedComponents[nGroups].push_back(aVertex);
    componentVertexMap[aVertex] = nGroups;
  }
}

int main() {
  while(true) {
    int V, E, nGroups = -1;
    scanf("%d", &V);

    if(V == 0) break;

    scanf("%d", &E);
    std::vector<bool> isVisited(V, false);
    std::vector<int> componentVertexMap(V, -1);
    std::stack<int> aNodeStack;
    std::vector<std::vector<int> > connectedComponents(V);

    Graph aGraph(V), aTranspose(V);

    for(int j = 0; j < E; j++) {
      int from, to;
      scanf("%d%d", &from, &to);
      aGraph.addEdge(from-1, to-1);
      aTranspose.addEdge(to-1, from-1);
    }

    // Apply Kosaraju's Algorithm to find strongly connected components:
    for(int i = 0; i < V; i++)
      dfs(aGraph, isVisited, i, aNodeStack);

    std::fill(isVisited.begin(), isVisited.end(), false);
    while(!aNodeStack.empty()) {
      if(!isVisited[aNodeStack.top()])
        nGroups++;

      dfsTranspose(aTranspose, isVisited, aNodeStack.top(), connectedComponents, componentVertexMap, nGroups); 
      aNodeStack.pop();
    }

    std::set<int> sinkVertices;
    for(int i = 0; i < connectedComponents.size(); i++) {
      if(connectedComponents[i].size() > 1) {
        int group = i;
        bool bFlag = true;

        for(int j = 0; j < connectedComponents[i].size(); j++) {
          for(int k = 0; k < aGraph.adj[connectedComponents[group][j]].size(); k++) {
            // if for two every edge (u, v) if u and v are in different components, 
            // then whole SCC containing u can't be in our sink vertices set.
            if(componentVertexMap[aGraph.adj[connectedComponents[group][j]][k]] != group) {
              bFlag = false;
              break;
            }
          }

          if(!bFlag) break;
        }

        if(bFlag) {
          for(int j = 0; j < connectedComponents[i].size(); j++)
            sinkVertices.insert(connectedComponents[i][j]);
        }

      }
      else if(connectedComponents[i].size() == 1) {
        if(aGraph.adj[connectedComponents[i][0]].size() == 0) {
          sinkVertices.insert(connectedComponents[i][0]);
        }
        else if(aGraph.adj[connectedComponents[i][0]].size() == 1 &&
                aGraph.adj[connectedComponents[i][0]][0] == connectedComponents[i][0])
          sinkVertices.insert(connectedComponents[i][0]);
      }
    }

    for(auto aItem : sinkVertices)
      printf("%d ", aItem + 1);
    printf("\n");
  }
  return 0;
}
