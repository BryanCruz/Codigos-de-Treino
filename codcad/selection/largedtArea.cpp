#include<iostream>

using namespace std;

int main(void){
  int l1, h1, l2, h2;

  cin >> l1 >> h1;
  cin >> l2 >> h2;

  int a1 = h1*l1, a2 = h2*l2;
  if(a1 > a2){
    cout << "Primeiro";
  }else if(a1 == a2){
    cout << "Empate";
  }else{
    cout << "Segundo";
  }
  cout << "\n";
  return 0;
}
