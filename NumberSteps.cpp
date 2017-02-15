#include <iostream>
using namespace std;

int main() {
  long long T;
  cin >> T;
  while(T--) {
    long long a, b;
    cin >> a >> b;

    if(b > a || b < a-2 || b == a-1) 
      cout << "No Number\n";
    else if(a%2 == 0 && b%2 == 0) 
      cout << a+b << endl;
    else if(a%2 != 0 && b%2 != 0) 
      cout << a+b-1 << endl;
  }
  return 0;
}
