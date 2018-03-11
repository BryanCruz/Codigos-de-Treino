#include<iostream>

int main(void){
  double a, b;

  std::cin >> a >> b;

  double avg = (a+b)/2;

  if(avg >= 7){
    std::cout << "Aprovado";
  }else if(avg >= 4){
    std::cout << "Recuperacao";
  }else{
    std::cout << "Reprovado";
  }
  std::cout << "\n";
  return 0;
}
