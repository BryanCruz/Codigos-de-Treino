#include<iostream>

using namespace std;

int main(void){
  double n1, n2, n3, n4, n5;
  double total;

  cin >> n1 >> n2 >> n3 >> n4 >> n5;
  total = n1+n2+n3+n4+n5;

  double menor = n1, maior = n1;
  if(n2 < menor){
    menor = n2;
  }
  if(n2 > maior){
    maior = n2;
  }

  if(n3 < menor){
    menor = n3;
  }
  if(n3 > maior){
    maior = n3;
  }

  if(n4 < menor){
    menor = n4;
  }
  if(n4 > maior){
    maior = n4;
  }

  if(n5 < menor){
    menor = n5;
  }
  if(n5 > maior){
    maior = n5;
  }

  total -= (menor+maior);

  cout.precision(1);
  cout.setf(ios::fixed);
  cout << total << "\n";
  return 0;
}
