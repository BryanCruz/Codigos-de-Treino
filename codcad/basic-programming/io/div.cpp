// cout.precision(2); // choose the precision I want in the output
// cout.setf(ios::fixed);
#include <iostream>

using namespace std;

int main(){
  cout.precision(2);
  cout.setf(ios::fixed);

  double x, y;
  cin >> x >> y;

  cout << x/y << "\n";
  return 0;
}
