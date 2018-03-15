#include<iostream>

using namespace std;

int main(void){
  int x;
  cin >> x;

  int n = 1;
  while(n <= x/2){
    if(x%n == 0){
      cout << n << " ";
    }
    n += 1;
  }
  cout << x << "\n";
  return 0;
}
