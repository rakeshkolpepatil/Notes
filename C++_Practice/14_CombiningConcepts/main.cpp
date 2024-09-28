#include <iostream>

using namespace std;

template<typename T>
concept TinyType = requires (T a){
  sizeof(T) <= 4;
  requires sizeof(T) <= 4;
};

template<typename T>
T func_or(T a) requires std::integral<T> || std::floating_point<T> {
  return a + 1.1;
}

template<typename T>
T func_and(T a) requires std::integral<T> && requires (T a) {
                                              sizeof(a) <= 4;             // simple requirement
                                              requires sizeof(a) <= 4;    // nested requirement
                                            } 
{
  cout << "The variable " << a << " is integral and has size less than 4. " << std::endl;
  return a;
}

int main(){
  int a {100};
  float b{222.222};
  long long int c {111'111'111'111};

  func_or(a);
  func_or(b);

  cout << " sizeof(a) = " << sizeof(a) << ", sizeof(b) = " << sizeof(b) << std::endl;

  func_and(a);
  //func_and(b);              // func_and(b) will give compilation error as 'b' is not of integral type. 
                            // Only 'char' and 'int' are of integral type.
  //func_and(c);              // func_and(c) will give compilation error as sizeof('c') is not <= 4.

  return 0;
}

