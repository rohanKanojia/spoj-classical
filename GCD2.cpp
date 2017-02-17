#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  long long T;
  char str[300];
  scanf("%lld", &T);

  while(T--) {
    long long b, a = 0;
    scanf("%lld%s", &b, str);
    
    if(b > 0) {    
      for(long long i = 0; i < strlen(str); i++) 
        a = (a*10 + str[i]-'0') % b;
    
      while(a != 0) {
        long long tmp = b % a;
        b = a;
        a = tmp;
      }
      printf("%lld\n", b);
    }
    else 
      printf("%s\n", str);
  }
  return 0;
}
