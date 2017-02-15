#include <iostream>
using namespace std;

int main() {
  long long a = 1, b = 1, c = 1;
  while(1) {
    cin >> a >> b >> c;

    if(a == 0 && b == 0 && c == 0)
      break;

    if(b - a == c - b) {
      cout << "AP " << c + (c-b) << endl;
    }
    else if(b*b == a*c) {
      long long r;
      if(a)
        r = b/a;
      else if(b)
        r = c/b;
      cout << "GP " << c*r << endl;
    }
  }
  return 0;
}
