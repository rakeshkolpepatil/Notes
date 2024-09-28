#include <iostream>
#include <cstring>

using namespace std;


// Template type parameters by value.
template <typename T> T maximum(T a, T b) {
  cout << "\n Inside &a : " << &a << ", &b : " << &b << endl;
  return (a > b) ? a : b;
}

// Template specialization - Using template specialization we can overload the 'maximum' function for the special data types where
//                           we need to modify the function code slightly to suit the specific needs.
template <>
const char* maximum<const char*>(const char* a, const char* b) {
  return (std::strcmp(a, b) > 0 ) ? a : b;
}

template <>
int* maximum<int*>(int* a, int* b) {
  return (*a > *b) ? a : b;
}

template <>
const int* maximum<const int*>(const int* a, const int* b) {
  cout << "(Called const int* template function) = ";
  return (*a > *b) ? a : b;
}

/*
// Template type parameters by reference.
template <typename T> const T& maximum(const T& a, const T& b) {
  cout << " Inside &a : " << &a << ", &b : " << &b << endl;
  return (a > b) ? a : b;
}
*/

int main(){

  /*
  // Template type parameters by value.
  int x{5};
  int y{7};
  auto result1 = maximum(x, y);
  cout << " result1 : " << result1 << endl;

  double a{5.5};
  double b{7.7};
  auto result2 = maximum(a, b);
  cout << " result2 : " << result2 << endl;

  long long int m{55565};
  long long int n{78868};
  auto result3 = maximum(m, n);
  cout << " result3 : " << result3 << endl;

  std::string p{"Hello"};
  std::string q{"World"};
  auto result4 = maximum(p, q);
  cout << " result4 : " << result4 << endl;

  //Pointers will not work as expected with function templates as they require dereferencing.
  int* u = &x;
  int* v = &y;
  auto result5 = maximum(u, v);
  cout << " result5 : " << *result5 << endl;
  */

  /*
	// Template type deduction and explicit arguments
  int a{1};
  double c{22.11};
  double d{10.11};

  std::string e{"Hello, "};
  std::string f{"world!"};

  auto result1 = maximum<double> (c, d); 		// explicitly say that we want the double version called, if the instance is not 
                                            // there already, it will be created.

  auto result2 = maximum<double> (a, d); 		// explicitly say that we want the double version called, First argument is of 
                                            // type 'int' but we have called template with explicit type 'double' so 'a' will
                                            // be converted to double and 'double' type instance of 'maximum' will be called.

  //auto result2 = maximum<double> (c, e);			// Compiler error will be thrown as for parameter 'e', conversion from 'std::string' to
                                              // 'double' is not possible. 
  */

  /*
  // Template type parameters by value.
  double a{22.11};
  double b{10.11};

  cout << " Before &a: " << &a << ", &b: " << &b << endl;
  auto result1 = maximum(a, b); 		
  cout << " After &a : " << &a << ", &b: " << &b << endl;
  */

  /*
  // Template type parameters by reference.
  double a{22.11};
  double b{10.11};

  cout << " Before &a : " << &a << ", &b : " << &b << endl;
  auto result1 = maximum(a, b); 		
  cout << " After &a  : " << &a << ", &b : " << &b << endl;
  */

  /*
  // Template specialization
  */  
  int a = 23;
  int b = 34;
  const int* p {&a};
  const int* q {&b};
  const char* i{"Hello, "};
  const char* j{"World!"};
  std::cout << "max(const char*) : maximum(i, j) = " << maximum(i, j) << endl;
  std::cout << "comparing two pointers : maximum(&a, &b) = " << *maximum(&a, &b) << endl;
  std::cout << "comparing two pointers : maximum(p, q)   = " << *maximum(p, q) << endl;

  return 0;
}