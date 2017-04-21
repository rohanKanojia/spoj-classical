#include <cstdio>
#include <cstring>

int main() {
  long long T;
  char mobileNo[50];
  scanf("%lld", &T);

  while(T--) {
    scanf("%s", mobileNo);
    long long mobileLen = strlen(mobileNo), ans = 1;

    for(long long i = 0; i < mobileLen; i++) {
      long long nEqual = 1;
      while(i+1 < mobileLen && mobileNo[i] == mobileNo[i+1])
        nEqual *= 2, i++;
      ans *= nEqual;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
