#include <iostream>
using namespace std;

double increment_multiply(double a, double b) {
  std::cout << "Inside function, before increment" << endl;
  std::cout << " a : " << a << endl;
  std::cout << " b : " << b << endl;
  
  double result = (++a) * (++b);
  std::cout << "Inside function, after increment" << endl;
  std::cout << " a : " << a << endl;
  std::cout << " b : " << b << endl;
  return result;								
}

int main(){
  double one {11.11};
  double two {22.22};

  cout << "Before calling 'increment_multiply' function " << endl;
  std::cout << " one : " << one << endl;
  std::cout << " two : " << two << endl;

  double result =  increment_multiply(one, two);

  cout << "After calling 'increment_multiply' function " << endl;
  std::cout << " one : " << one << endl;
  std::cout << " two : " << two << endl;

  cout << "increment_multiply(" << one << ", " << two << ") = " << result << endl;

}

