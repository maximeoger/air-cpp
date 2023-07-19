#include <iostream>

using namespace std;

bool isPrimeNumber(int num) {
  int dividers = 0;
  for(int i=0; i<=num; i++) {
    if(num%i == 0) {
      dividers += 1;
    }
  }
  return dividers == 2; 
}

bool isNumber(string str) {
  for(int i=0; i<str.length(); i++) {
    if(i == 0 && str[i] == '-') continue;
    if(isdigit(str[i]) == false) {
      return false;
    }
  }
  return true;
}