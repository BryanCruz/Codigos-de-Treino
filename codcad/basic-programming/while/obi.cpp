#include<iostream>

using namespace std;

int main(void){
  int n, p;

  cin >> n >> p;
  int qtd = 0;
  while(n-- > 0){
    int x, y;
    cin >> x >> y;

    int total = x+y;
    if(total >= p){
      qtd++;
    }
  }

  cout << qtd << "\n";
  return 0;
}
