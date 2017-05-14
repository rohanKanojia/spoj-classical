#include <cstdio>

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    int arr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const char *daysStr[] = {"Sunday", "Monday", "Tuesday", "Wednesday", 
      "Thursday", "Friday", "Saturday"};
    long long month, day, year, Y, M, nDays = 0;
    scanf("%lld%lld%lld", &day, &month, &year);
    Y = 1900, M = 1;
    if(year > 1900) {
      while(Y < year) {
        if((Y%4 == 0 && Y%100 != 0) || (Y%400) == 0)
          nDays += 366;
        else
          nDays += 365;
        Y++;
      }
    }
    if(month > 1) {
      for(M = 1; M < month; M++) {
        if(M == 2) {
          if((Y%4 == 0 && Y%100 != 0) || Y%400 == 0)
            nDays += 29;
        }
        else
          nDays += arr[M];
      }
    }
    nDays += day;

    printf("%s\n", daysStr[nDays % 7]);
  }
  return 0;
}
