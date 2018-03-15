// cout.precision(2); // choose the precision I want in the output
// cout.setf(ios::fixed);
#include <iostream>

using namespace std;

int main(){
  int w, x, y, z;
  cin >> w >> x >> y >> z;
  int total = w+x+y+z - 4 + 1;
  cout << total << "\n";
  return 0;
}
