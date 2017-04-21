#include <iostream>
#include <string>
using namespace std;

#define SIZE 250
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
  friend std::ostream& operator<<(std::ostream& tmp, const Integer& a);
  friend Integer operator-(const Integer& b, const Integer& a);
  friend Integer addOffset(Integer& a, Integer& b, int offset);
  friend Integer multiplyIntermediate(char a, const Integer& b);
  friend Integer operator*(const Integer& a, const Integer& b);
};

int main() {
  long long T;
  cin >> T;

  while(T--) {
    string a, b, c;
    cin >> a >> b >> c;
    Integer A(a), B(b), C(c), two("2");
    Integer res = two*B - C - A;
    cout << res << endl;
  }
  return 0;
}

std::ostream& operator<<(std::ostream& tmp, const Integer& a) {
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

Integer operator-(const Integer& P, const Integer& Q) {
  Integer C, b = P, a = Q;
  int i, tmp, neighbour, j;

  for(i = a.getCapacity()-1; i >= 0; i--) {
    if(b.getDigit(i) >= a.getDigit(i)) {
      tmp = b.getDigit(i) - a.getDigit(i);
    }
    else {
      neighbour = i - 1;
      while(neighbour > 0 && b.num[neighbour] == '0') { neighbour--; }

      for(j = neighbour; j < i; j++) {
        b.num[j] = b.num[j]-1;
        b.num[j+1] = b.num[j+1] + 10;
      }
      tmp = b.getDigit(i) - a.getDigit(i);
    }
    C.num[i] = tmp + '0';
  }
  C.findDigits();

  return C;
}

Integer addOffset(Integer& a, Integer& b, int offset) {
  int temp, carry, index, a_index = a.getCapacity()-1;
  Integer C = a;
  for(index = a.getCapacity()-offset; a_index >= 0; index--, a_index--) {
    temp = C.getDigit(index) + b.getDigit(a_index);
    carry = temp / 10;
    temp %= 10;
    C.num[index] = temp + '0';
    if(index > 0)
      C.num[index-1] = C.num[index-1] + carry;
  }
  C.findDigits();
  return C;
}

Integer multiplyIntermediate(char a, const Integer& b) {
  int i, product = 0, carry = 0;
  Integer temp;

  for(i = b.getCapacity()-1; i >= 0; i--) {
    product = temp.getDigit(i) + (a-'0')*(b.getDigit(i));
    carry = product / 10;
    product %= 10;
    temp.num[i] = product + '0';
    if(i > 0)
      temp.num[i-1] = carry + temp.num[i-1];
  }
  temp.findDigits();
  return temp;
}

Integer operator*(const Integer& a, const Integer& b) {
  int offset = 1, i;
  Integer temp, res;
  for(int i = a.getCapacity()-1; i > a.getCapacity()-1-b.getSize(); i--) {
    temp = multiplyIntermediate(b.num[i], a);
    res = addOffset(res, temp, offset);
    offset++;
  }
  res.findDigits();
  res.sign = a.sign == b.sign ? '+' : '-';
  return res;
}
