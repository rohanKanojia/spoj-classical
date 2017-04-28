#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define SIZE 2100
class Integer {
  char num[SIZE], sign;
  long long size, capacity;
  void initializeStr(int limit) {
    for(int i = 0; i < limit; i++)
      num[i] = '0';
  }
public:
  Integer() : size(0), capacity(0) {
    capacity = SIZE;
    sign = '+';
    initializeStr(capacity);
  }
  Integer(std::string aStr) : size(aStr.length()), capacity(0) {
    capacity = SIZE;
    if(aStr.find('-') != std::string::npos) {
      sign = '-';
    }
    else
      sign = '+';
    initializeStr(capacity);
    for(int i = capacity-1, j = aStr.length()-1; i >= 0 && j >= 0;  j--, i--) {
      num[i] = aStr[j];
    }
  }
  Integer(const Integer& a) {
    capacity = a.getCapacity();
    for(int index = 0; index < capacity; index++) {
      num[index] = a.getChar(index);
    }
    sign = a.getSign();
    size = a.getSize();
  }
  int getDigit(int index) const  { 
    return num[index] - '0'; 
  }
  char getChar(int index) const  { return num[index]; }
  char getSign() const           { return sign; }
  long long getSize() const      { return size; }
  long long getCapacity() const  { return capacity; }
  void findDigits() {
    int i = 0;
    while(i < SIZE && num[i] == '0') i++;
    size = capacity - i;
    if(size == 0) // In case of zero
      size = 1;
  }
  friend std::ostream& operator<<(std::ostream& tmp, const Integer& a) {
    int i = 0;
    while(i < SIZE && a.num[i] == '0') i++;
    if(i == SIZE)
      tmp << 0;
    else {
      while(i < SIZE) {
        tmp << a.num[i++];
      }
    }
    return tmp;
  }
  friend Integer operator+(const Integer& a, const Integer& b) {
    int index, tmp = 0, carry = 0;
    Integer C;

    for(int i = a.getCapacity()-1; i >= 0; i--) {
      tmp = a.getDigit(i) + b.getDigit(i) + C.getDigit(i);
      carry = tmp / 10;
      tmp = tmp % 10;
      C.num[i] = tmp + '0';
      if(i > 0) {
        C.num[i-1] = C.num[i-1] + carry;
      }
    }
    C.findDigits();
    return C;
  }
  void set_integer(const char buffer[]) {
    int buffer_index = strlen(buffer)-1, index = SIZE - 1;
    sign = (buffer[0] == '-') ? '-' : '+';
    while(buffer_index >= 0) {
      if(buffer[buffer_index] != '-') {
        num[index] = buffer[buffer_index];
        buffer_index --;
        index --;
      }
      else break;
    }
    size = (buffer[0] == '-') ? strlen(buffer) - 1 : strlen(buffer);
  } 
};

int main() {
  int N;
  cin >> N;

  if(N <= 2)
    cout << N+1 << endl;
  else {
    Integer f1(string("2")), f2(string("3"));
    Integer result;

    for(int i = 0; i < N-2; i++) {
      result = f1 + f2;
      f1 = f2;
      f2 = result;
    }
    cout << result << endl;
  }
  return 0;
}
