#include <cstdio>
using namespace std;

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long nPlayers, nTowers, damage;
    bool life = true;

    scanf("%lld%lld%lld", &nPlayers, &nTowers, &damage);

    long long count= 0;
    for(long long i = 0; i < nPlayers; i++) {
      long long tmp;
      scanf("%lld", &tmp);
      while(tmp - damage > 0 ) {
        tmp -= damage;
        count++;
      }
    }

    printf("%s\n", (count >= nTowers ? "YES" : "NO"));
  }
  return 0;
}
