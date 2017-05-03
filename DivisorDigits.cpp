#include <cstdio>
#include <cstring>

#define SIZE 500
#define TO_DIGIT(x) (x - '0')

int main() {
  char aStr[500];
  int b[] = {0, 1, 3, 2, 6, 4, 5}, c, d, e;

  while(scanf("%s", aStr) > 0) {
    int digitSum = 0, digitLen = strlen(aStr), nDivisors = 0;
    for(int i = 0; i < digitLen; i++)
      digitSum += (aStr[i] - '0');

    for(int i = 0; i < digitLen; i++) {
      switch(aStr[i]) {
        case '1':
          nDivisors++;
          break;
        case '2':
          nDivisors += (TO_DIGIT(aStr[digitLen-1]) % 2 == 0);
          break;
        case '3':
          nDivisors += (digitSum%3 == 0);
          break;
        case '4':
          nDivisors += ((TO_DIGIT(aStr[digitLen-1]) + TO_DIGIT(aStr[digitLen-2])*10) % 4 == 0);
          break;
        case '5':
          nDivisors += (TO_DIGIT(aStr[digitLen-1]) % 5 == 0);
          break;
        case '6':
          nDivisors += (digitSum%3 == 0 && TO_DIGIT(aStr[digitLen-1])%2 == 0);
          break;
        case '7':
          c = 1, d = digitLen-1, e = 0;
          while(d >= 0) {
            e += (TO_DIGIT(aStr[d]) * b[c]);
            c++;
            d--;
            if(c > 6)
              c = 1;
          }
          nDivisors += (e%7 == 0);
          break;
        case '8':
          nDivisors += ((TO_DIGIT(aStr[digitLen-1]) + TO_DIGIT(aStr[digitLen-2])*10 + TO_DIGIT(aStr[digitLen-3])*100)%8 == 0);
          break;
        case '9':
          nDivisors += (digitSum % 9 == 0);
          break;
      }
    }
    printf("%d\n", nDivisors);
  }
  return 0;
}
