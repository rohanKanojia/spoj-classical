#include <iostream>
#include <string>
using namespace std;

string nextPalindromeUtil(string& num);
string nextPalindrome(string& num);
bool allNines(string& num);
void addDigit(string& num, long long index, long long& carry);

int main() {
  long long T;
  cin >> T;
  while(T--) {
    string num;
    cin >> num;
    cout << nextPalindrome(num) << endl;
  }
  return 0;
}

string nextPalindromeUtil(string& num) {
  long long mid = num.length()/2;
  long long start = mid-1;
  long long end = (num.length()%2 == 0 ? mid : (mid+1));
  bool largerLeft = false;

  while(start > 0 && num[start] == num[end]) {
    start--;
    end++;
  }

  if(start < 0 || num[start] > num[end])
    largerLeft = true;

  // mirror left to right side :
  while(start >= 0) {
    num[end++] = num[start--];
  }
  if(largerLeft == false) {
    start = mid-1;
    long long carry = 1;

    if(num.length()%2 == 1) { // add to mid element in middle case
      addDigit(num, mid, carry);
      end = mid+1;
    }
    else
      end = mid;
    
    while(start >= 0) {
      addDigit(num, start, carry);
      num[end++] = num[start--];
    }
  }

  return num;
}

string nextPalindrome(string& num) {
  if(allNines(num)) {
    string ss("1");
    for(long long i = 1; i < num.length(); i++)
      ss += '0';
    ss += '1';
    return ss;
  }
  else
    return nextPalindromeUtil(num);
}

bool allNines(string& num) {
  for(long long i = 0; i < num.length(); i++) {
    if(num[i] != '9')
      return false;
  }
  return true;
}

void addDigit(string& num, long long index, long long& carry) {
  long long tmp = num[index]-'0';
  tmp = tmp + carry;
  carry = tmp / 10;
  tmp = tmp % 10;
  num[index] = tmp + '0';
}
