#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

void convertToJava(char aStr[], char aux[]);
void convertToCPlusPlus(char aStr[], char aux[]);
bool isValidStr(char aStr[]);
bool isJavaString(char aStr[]);

int main() {
  char aStr[500], res[500];
  while(scanf("%s", aStr) > 0) {
    if(!isValidStr(aStr)) {
      printf("Error!\n");
    }
    else if(isJavaString(aStr)) {
      convertToCPlusPlus(aStr, res);
      printf("%s\n", res);
    }
    else {
      convertToJava(aStr, res);
      printf("%s\n", res);
    }
  }
  return 0;
}

bool isValidStr(char aStr[]) {
  bool bJava = false, bCPlusPlus = false;
  if(strlen(aStr) > 0 && isupper(aStr[0])) // first character can't be uppercase
    return false;
  if(strlen(aStr) > 0 && aStr[0] == '_') // first character can't be underscore
    return false;
  if(strlen(aStr) > 0 && aStr[strlen(aStr)-1] == '_') // trailing underscore
    return false;

  for(long long i = 0; aStr[i] != '\0'; i++) {
    if(aStr[i] == '_')
      bCPlusPlus = true;
    else if(isupper(aStr[i]))
      bJava = true;
    if(bJava && bCPlusPlus) // contains both '_' and uppercase character
      return false;
    if(i > 0 && aStr[i] == '_' && aStr[i-1] == '_') // containing two direct '_'
      return false;
  }
  return true;
}

void convertToCPlusPlus(char aStr[], char aux[]) {
  long long auxIndex = 0;
  for(long long i = 0; aStr[i] != '\0'; i++) {
    if(isupper(aStr[i])) {
      aux[auxIndex++] = '_';
      aux[auxIndex++] = tolower(aStr[i]);
    }
    else {
      aux[auxIndex++] = aStr[i];
    }
  }
  aux[auxIndex] = '\0';
}

void convertToJava(char aStr[], char aux[]) {
  long long auxIndex = 0;
  for(long long i = 0; aStr[i] != '\0'; i++) {
    if(aStr[i] == '_') {
      aux[auxIndex++] = toupper(aStr[i+1]);
      i++;
    }
    else {
      aux[auxIndex++] = aStr[i];
    }
  }
  aux[auxIndex] = '\0';
}

bool isJavaString(char aStr[]) {
  for(long long i = 0; aStr[i] != '\0'; i++) {
    if(isupper(aStr[i]))
      return true;
  }
  return false;
}
