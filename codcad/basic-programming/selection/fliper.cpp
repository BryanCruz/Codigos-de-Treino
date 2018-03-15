#include<iostream>

using namespace std;

int main(void){
  int p, r;
  cin >> p >> r;

  char result;
  if(p){
    if(r){
      result = 'A';
    }else{
      result = 'B';
    }
  }else{
    result = 'C';
  }

  cout << result << '\n';

  return 0;
}
