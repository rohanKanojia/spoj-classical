#include <iostream>
#include <stack>
#include <map>
#include <string>

bool isOperator(char cc) {
  return cc == '+' ||
         cc == '-' ||
         cc == '*' ||
         cc == '/' ||
         cc == '^';
}

bool isOperand(char cc) {
  return cc >= 'a' && cc <= 'z';
}

std::string convertToPostfix(std::string ss) {
  std::stack<char> st;
  std::string postfixExp;
  std::map<char, int> precedence = {
   {'+', 1}, {'-', 1}, {'/', 2}, {'*', 2}, {'^', 3}
  };

  
  st.push('(');
  ss += ')';

  for(long long i = 0; i < ss.size(); i++) {
    if(isOperand(ss[i])) {
      postfixExp += ss[i];
    }
    else if(ss[i] == '(') {
      st.push(ss[i]);
    }
    else if(isOperator(ss[i])) {
      while(!st.empty() && precedence[ss[i]] < precedence[st.top()]) {
        postfixExp += st.top();
        st.pop();
      }
      st.push(ss[i]);
    }
    else if(ss[i] == ')') {    
      while(!st.empty() && st.top() != '(') {
        postfixExp += st.top();
        st.pop();
      }
      if(st.top() == '(')
        st.pop();
    }
  }
  return postfixExp;
}

int main() {
  long long T;
  std::cin >> T;
  while(T--) {
    std::string ss;
    std::cin >> ss;
    std::cout << convertToPostfix(ss) << std::endl;
  }
  return 0;
}
