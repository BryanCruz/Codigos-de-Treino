#include<iostream>

using namespace std;

int main(void){
  //positions of helicopter, police, fugitive and the direction fugitive went
  int h, p, f, d;
  cin >> h >> p >> f >> d;


  int rightDirection;
  if(h < p){
    if(h < f){
      if(p < f){ // h p f
        rightDirection = 1;
      }else{    //  p h f
        rightDirection = -1;
      }
    }else{      //p f h
      rightDirection = 1;
    }
  }else{
    if(p < f){
      if(h < f){ //h f p
        rightDirection = -1;
      }else{ //f h p
        rightDirection = 1;
      }
    }else{ // f p h
      rightDirection = -1;
    }
  }

  if(rightDirection == d){
    cout << "S";
  }else{
    cout << "N";
  }
  cout << "\n";
  
  return 0;
}
