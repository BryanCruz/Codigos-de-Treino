#include<iostream>

using namespace std;

int main(void){
  int g1, s1, b1, g2, s2, b2;

  cin >> g1 >> s1 >> b1 >> g2 >> s2 >> b2;

  if(g1 > g2){
    cout << "A";
  }else if(g2 > g1){
    cout << "B";
  }else if(s1 > s2){
    cout << "A";
  }else if(s2 > s1){
    cout << "B";
  }else if(b1 > b2){
    cout << "A";
  }else if(b2 > b1){
    cout << "B";
  }
  cout << "\n";

  return 0;
}
