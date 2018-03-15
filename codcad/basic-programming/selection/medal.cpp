#include<iostream>

using namespace std;

int main(void){
  int t1, t2, t3;
  cin >> t1 >> t2 >> t3;



  int first, second, third;
  //sort the times
  if(t1 < t2){
    if(t1 < t3){
      first = 1;
      if(t2 < t3){
        second = 2;
        third = 3;
      }else{
        second = 3;
        third = 2;
      }
    }else{
      first = 3;
      second = 1;
      third = 2;
    }
  }else{
    if(t2 < t3){
      first = 2;
      if(t1 < t3){
        second = 1;
        third = 3;
      }else{
        second = 3;
        third = 1;
      }
    }else{
      first = 3;
      second = 2;
      third = 1;
    }
  }

  cout << first  << "\n";
  cout << second << "\n";
  cout << third  << "\n";

  return 0;
}
