#include <iostream>
#include "compare.h"
#include "operations.h"

using namespace std;

int main(){

  int result = min(123, 566);
  cout << " Min of (123, 566) = " << result << endl;

  result = max(123, 566);
  cout << " Min of (123, 566) = " << result << endl;

  int x{5};
  int y{6};
  result = incr_mul(x, y);
  cout << " result = " << result << endl;

  return 0;
}

