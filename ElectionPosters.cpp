// http://zobayer.blogspot.in/2011/01/spoj-posters.html
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define MAX_VAL 1000000001

void compressAndInsert(set<int>& s1, set<int>& s2, map<int, int>& m,
  int N) {
  int c = 1;
  set<int>::iterator it = s1.begin();
  while(it != s1.end()) {
    s2.insert(c);
    m[*it] = c++;
    it++;
  }
}

int main() {
  int T, N;
  scanf("%d", &T);

  while(T--) {
    scanf("%d", &N);
    vector<pair<int, int> > v, c;
    map<int, int> m;
    set<int> s1, s2;
    int a, b;

    for(int i = 0; i < N; i++) {
      scanf("%d%d", &a, &b);
      v.push_back(make_pair(a, b));
      s1.insert(a);
      s1.insert(b);
    }
    std::reverse(v.begin(), v.end());
    compressAndInsert(s1, s2, m, N);

    int ans = 0;
    s2.insert(MAX_VAL);
    for(int i = 0; i < N; i++) {
      int a = m[v[i].first];
      int b = m[v[i].second];

      set<int>::iterator it1 = s2.lower_bound(a);
      set<int>::iterator it2 = s2.upper_bound(b);

      if(it1 != it2) {
        s2.erase(it1, it2);
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
