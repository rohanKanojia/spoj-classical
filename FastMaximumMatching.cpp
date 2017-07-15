#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_V 50000
#define MAX_E 150000
int pairU[MAX_V], pairV[MAX_V];
int to[MAX_E], next[MAX_E], last[MAX_E];
bool isVisited[MAX_V];

class BipartiteGraph {
   int E, nLeft, nRight;
public:
    BipartiteGraph(int left, int right)
        : E(0), nLeft(left), nRight(right)     
        { std::fill(last, last + MAX_E, -1); }
    void addEdge(int u, int v)  {
        to[E]   = v;
        next[E] = last[u];
        last[u] = E++;
    }
    bool pairUp(int u) {
        if(isVisited[u])
            return false;
        isVisited[u] = true;

        for(int e = last[u]; e != -1; e = next[e]) {
            int v = to[e];

            if(pairV[v] == -1 || pairUp(pairV[v])) {
                pairU[u] = v;
                pairV[v] = u;
                return true;
            }
        }
        return false;
    }
    int hopcroftKarp() {
        bool bChanged = true;
        std::fill(pairU, pairU + MAX_V, -1);
        std::fill(pairV, pairV + MAX_V, -1);

        while(bChanged) {
            bChanged = false;
            std::fill(isVisited, isVisited + MAX_V, false);

            for(int i = 0; i < nLeft; i++) {
                if(pairU[i] == -1)
                    bChanged |= pairUp(i);
            }
        }

        int nRet = 0;
        for(int i = 0; i < nLeft; i++) {
            if(pairU[i] != -1)
                nRet++;
        }
        return nRet;
    }
};


int main() {
    int N, M, P;
    scanf("%d%d%d", &N, &M, &P);

    BipartiteGraph aGraph(N, M);
    for(int i = 0; i < P; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        aGraph.addEdge(u-1, v-1);
    }
    printf("%d\n", aGraph.hopcroftKarp());
    return 0;
}
