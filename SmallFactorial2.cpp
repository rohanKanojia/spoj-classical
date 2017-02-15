#include <iostream>
#include <unistd.h>
#include <cstring>
#include <vector>
using namespace std;

#define SIZE 200

void printInteger(char aStr[]) {
  int i = 0;
  while(i < SIZE && aStr[i] == '0') i++;
  if(i == SIZE)
    cout << 0;
  while(i < SIZE) {
    cout << aStr[i++];
  }
}

void copyIntegers(char aStr[], char bStr[]) {
  for(int i = 0; i < SIZE; i++)
    aStr[i] = bStr[i];
}

void addOffset(char aStr[], char aux[], int offset) {
  int temp, carry, index, aIndex = SIZE-1;
  for(index = SIZE-offset; aIndex >= 0; index--, aIndex--) {
    temp = aStr[index]-'0' + aux[aIndex]-'0';
    carry = temp / 10;
    temp %= 10;
    aStr[index] = temp + '0';
    if(index > 0)
      aStr[index-1] = aStr[index-1] + carry;
  }
}

void multiplyIntermediate(int digit, char aStr[], char temp[]) {
  int i, product = 0, carry = 0;

  for(i = SIZE-1; i >= 0; i--) {
    product = temp[i]-'0' + digit*(aStr[i]-'0');
    carry = product / 10;
    product %= 10;
    temp[i] = product + '0';
    if(i > 0)
      temp[i-1] = carry + temp[i-1];
  }
}

void multiply(char aStr[], long long num, char temp[], char res[]) {
  int offset = 1, i;
  memset(res, '0', SIZE);

  while(num) {
    memset(temp, '0', SIZE);
    multiplyIntermediate(num%10, aStr, temp);
    addOffset(res, temp, offset);
    num /= 10;
    offset++;
  }
  copyIntegers(aStr, res);
}


int main() {
  long long T;
  cin >> T;
  while(T--) {
    long long a;
    cin >> a;
    char aStr[SIZE], temp[SIZE], res[SIZE];
    memset(aStr, '0', SIZE);
    aStr[SIZE-1] = '1';
    for(long long i = a; i > 0; i--) {
      multiply(aStr, i, temp, res);
    }

    printInteger(aStr);
    cout << endl;
  }
  return 0;
}
