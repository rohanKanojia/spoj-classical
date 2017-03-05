/*
 * i've used karatsuba but i this implementation is slow. Native C arrays can work but
 * i haven't tried that.
 * !! Gives TLE :(
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define SIZE 10005
void subString(char buffer[], char num[], int start, int end);
class Integer {
  char num[SIZE];
  long long size;
  long long capacity;
  char sign;
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
  Integer(string aStr) : size(aStr.length()), capacity(0) {
    capacity = SIZE;
    if(aStr.find('-') != string::npos) {
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
  void print() {
    int i = 0;
    while(i < SIZE && num[i] == '0') i++;
    if(i == SIZE)
      printf("0");
    else {
      while(i < SIZE)
        printf("%c", num[i++]);
    }
  }
  string getStr() {
    string tempStr = "";
    int i = 0;
    while(i < SIZE && num[i] == '0') i++;
    if(i == SIZE)
      tempStr += '0';
    else
      while(i < SIZE)
        tempStr += num[i++];
    return tempStr;
  }
  friend bool operator>(const Integer& b, const Integer& a) {
    if(b.sign == '-' && a.sign == '+') {
      return false;
    }
    else if(a.sign == '-' && b.sign == '+') {
      return true;
    }
    else if(b.getSize() > a.getSize()) {
      return true;
    }
    else if(b.getSize() < a.getSize()) {
      return false;
    }
    else if(b.getSize() == a.getSize()) {
      int i = b.getCapacity() - a.getSize();
      while(i != b.getCapacity()) {
        if(b.getDigit(i) > a.getDigit(i)) {
          return true;
        }
        else if(b.getDigit(i) < a.getDigit(i)) {
          return false;
        }
        i++;
      }
      return false;
    }
    else
      return false;
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
  friend Integer operator-(Integer b, Integer a) {
    Integer C;
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
  friend Integer addOffset(Integer& a, Integer& b, int offset) {
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
  friend Integer multiplyIntermediate(char a, const Integer& b) {
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
  friend Integer operator*(const Integer& a, const Integer& b) {
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
  void set_integer(const char buffer[])
  {
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
  friend bool operator>=(const Integer& b, const Integer& a)
  {
    if(b == a)
      return 1;
    else 
      return (b > a);
  }
  friend Integer operator<<(Integer& b, long long shiftVal) {
    Integer two(string("2")), res = b;
    while(shiftVal--)
      res = res*two;
    return res;
  }
  friend bool operator==(const Integer& a, const Integer& b)
  {
    if(a.size == b.size   &&   a.sign == b.sign) {
      int i = SIZE - (a.size);
      while(i != SIZE) {
        if(b.num[i] != a.num[i])
          return 0;
        else 
          i++;
      }
      return 1;
    }
    else
      return 0;
  }
  friend Integer powerOf(const Integer& a, long long num) {
    Integer res(string("1"));
    while(num--) 
      res = res * a;
    return res;
  }
  friend Integer operator/(const Integer& b, const Integer& a)
  {
    Integer divisor, dividend, tmp, multiple, quotient_digit, q;
    char buffer[SIZE], quotient_str[SIZE];
    memset(buffer, '\0', SIZE);
    memset(quotient_str, '\0', SIZE);
    int j = 0, k;
    divisor = absolute(a);
    dividend = absolute(b);
    if(divisor > dividend) {
      tmp.set_integer("0");
      return tmp;
    }
    k = SIZE - (b.size);
    subString(buffer, dividend.num, k, k + a.size);
    k = k + a.size - 1;
    tmp.set_integer(buffer);
    while(k < SIZE) {
      while(divisor > tmp  &&  k < SIZE) {
        quotient_str[j++] ='0';
        tmp = addDigitToRight(tmp, dividend.num[++k]);
      }
      if(k == SIZE) break;
      quotient_digit = findNearestMultiple(tmp, divisor);
      multiple = quotient_digit * divisor;
      quotient_str[j++] = quotient_digit.num[SIZE - 1];
      tmp = tmp - multiple;
      tmp = addDigitToRight(tmp, dividend.num[++k]);
      tmp.findDigits();
    }
    q.set_integer(quotient_str);
    q.sign = (a.sign == b.sign) ? '+' : '-';
    return q;
  }
  friend Integer findNearestMultiple(const Integer& a, const Integer& b)
  {
    Integer  product = b, one;
    Integer i;
    one.set_integer("1");
    i = one;
    while(a >= product) {
      i = i + one;
      product = b * i;
    }
    i = i - one;

    return i;
  } 
  friend Integer addDigitToRight(Integer temp, char ch)
  {
    Integer a, ten;
    char digit[2];
    sprintf(digit, "%c", ch); 
    a.set_integer(digit);
    ten.set_integer("10");
    temp = temp * ten;
    temp = temp + a;
    return temp;
  }
  friend Integer absolute(const Integer& a)
  {
    Integer minusOne, zero, temp;
    minusOne.set_integer("-1");
    zero.set_integer("0");
    if(a > zero) 
      return a;
    else {
      temp = a * minusOne;
      return temp; 
    }
  }
};

Integer KaratsubaMultiply(Integer a, Integer b);
string addBitStrings(string first, string second);
long long makeEqualLength(string& str1, string& str2);
long long multiplySingleBit(string a, string b);

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    char aStr[SIZE], bStr[SIZE];
    scanf("%s%s", aStr, bStr);
    string a(aStr), b(bStr);
    Integer A(a), B(b);

    Integer res = KaratsubaMultiply(A, B);
    res.print();
    printf("\n");
  }
  return 0;
}

string addBitStrings(string first, string second) {
  string result;

  int length = makeEqualLength(first, second);
  int carry  = 0;

  for(int i = length -1; i >= 0; i--) {
    int firstBit = first[i] - '0';
    int secondBit = second[i] - '0';

    int sum = (firstBit ^ secondBit ^ carry) + '0';
    result = (char)sum + result;

    carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry);
  }
  if(carry) result += '1';
  return result;
}

long long multiplySingleBit(string a, string b) {
  return (a[0] - '0') * (b[0] - '0');
}

long long makeEqualLength(string& str1, string& str2) {
  long long len1 = str1.size();
  long long len2 = str2.size();
  if(len1 < len2) {
    for(long long i = 0; i < len2-len1; i++)
      str1 += '0';
    return len2;
  }
  else if(len1 > len2) {
    for(long long i = 0; i < len1-len2; i++)
      str2 += '0';
  }
  return len1;
}

Integer KaratsubaMultiply(Integer X, Integer Y) {
  Integer ten(string("10"));
  long long N = std::max(X.getSize(), Y.getSize()); 

  if(N < 10) 
    return X*Y;

  N = (N/2) + (N%2);
  Integer multiplier = powerOf(ten, N);
  Integer bigN(to_string(N));

  Integer b = X/multiplier;
  Integer a = X - (b*multiplier);
  Integer d = Y/multiplier;
  Integer c = Y-(d*bigN);

  Integer z0 = a*c;
  Integer z1 = (a + b) * (c + d);
  Integer z2 = b*d;
  Integer diff = z1-z0;
  diff = diff - z2;

  return z0 + (diff *multiplier) + 
    (z2*powerOf(ten, 2*N));
}

void subString(char buffer[], char num[], int start, int end)
{
  int i;
  for(i = 0; start < end; start++, i++) {
    buffer[i] =num[start]; 
  }
  buffer[i] = '\0';
}
