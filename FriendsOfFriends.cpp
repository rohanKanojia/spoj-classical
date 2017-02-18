#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main() {
  long long N;
  scanf("%lld", &N);
  vector<vector<long long> > friendList;
  map<long long, bool> isBobFriend;
  for(long long i = 0; i < N; i++) {
    long long curFriend, nFriends;
    scanf("%lld%lld", &curFriend, &nFriends);
    isBobFriend[curFriend] = true;
    vector<long long> curFriends;
    for(long long j = 0; j < nFriends; j++) {
      long long tmp;
      scanf("%lld", &tmp);
      curFriends.push_back(tmp);
    }
    friendList.push_back(curFriends);
  }

  long long ans = 0;
  for(long long i = 0; i < N; i++) {
    for(long long j = 0; j < friendList[i].size(); j++) {
      if(isBobFriend.find(friendList[i][j]) == isBobFriend.end()) {
        isBobFriend[friendList[i][j]] = true;
        ans++;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
