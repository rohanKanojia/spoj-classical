#include <cstdio>
#include <cstring>

int main() {
  int T;
  int b[] = {0, 1, 3, 2, 6, 4, 5}, c, d, e, i;
  char aStr[50001];
  scanf("%d", &T);
  getchar();

  while(T--) {
    bool b3(0), b25(0), b9(0), b7(0), b4(0);
    scanf("%s", aStr);
    int length = strlen(aStr), sum = 0;
    int lastTwo = (aStr[length-2]-'0')*10 + (aStr[length-1]-'0');
    for(i = 0; i < length; i++)
      sum += (aStr[i] - '0');

    /* checking 7 divisibility */
    c = 1, d = length-1, e = 0;
    while(d >= 0) {
      e += (aStr[d] - '0') * b[c];
      c++;
      d--;
      if(c > 6)
        c = 1;
    }

    b7  = (e%7 == 0);
    b3  = (sum%3 == 0);
    b9  = (sum%9 == 0);
    b4  = (lastTwo%4 == 0);
    b25 = (lastTwo%25 == 0);
    
    printf("%s ", (b4 && b9 && b7) ? "Yes" : "No");
    printf("%s\n", (b3 && b25 && b7) ? "Yes" : "No");
  }
  return 0;
}
