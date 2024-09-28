#include <iostream>
#include <concepts>
#include <type_traits>

using namespace std;

/*
// --------------------- Custom Built Concepts --------------------- 
*/
// Different ways to build/define Custom Concepts

// Type 1 :-
template <typename T>
concept MyIntegral = std::is_integral_v<T>;

// Type 2 :-
template <typename T>
concept Multiplyable = requires (T a, T b){
  a * b;
};

// Type 3 :-
template <typename T>
concept Incrementable = requires(T a){
  a += 1;
  ++a;
  a++;
};


// --------------------- Using Custom-Built Concepts ---------------------
// Type 1 :-
template <typename T>
requires MyIntegral<T>
T add1 (T a, T b){
  return a + b;
}

// Type 2 :-
template <Multiplyable T>
T mul1 (T a, T b){
  return a + b;
}

template <Incrementable T>
T increment1(T a){
  return ++a;
}

// Type 3 :-
MyIntegral auto add2(MyIntegral auto a, MyIntegral auto b){
  return a + b;
}

// Type 4 :-
template <typename T>
T add3 (T a, T b) requires MyIntegral<T> {
  return a + b;
}

// Type 5 :-
template <typename T>
requires Multiplyable<T>
T add4 (T a, T b) {
    return a + b;
}

int main(){
  char a1{10};
  char b1{20};

  auto result_add1 = add1(a1, b1);
  cout << "result_add1 = " << static_cast<int>(result_add1) << endl;
  cout << "result_add3 = " << static_cast<int>(add3(a1, b1)) << endl;
  cout << "result_add4 = " << static_cast<int>(add4(a1, b1)) << endl;

  auto result_mul = mul1(a1, b1);
  cout << "result_mul = " << static_cast<int>(result_mul) << endl;

  int a2 {10};
  auto result_incr_int = increment1(a2);
  cout << "increment(int(10))      = " << result_incr_int << endl;

  float b2 {20.40};
  auto result_incr_float = increment1(b2);
  cout << "increment(float(20.40)) = " << result_incr_float << endl;


  /*
  double a3 {10};
  double b3 {20};
  auto result3 = maximum(a3, b3);            // 'double' is of not integral type, so it will give compilation error.
  cout << "result3: " << result3 << endl;
  */

  /*
  string a4 {"Hello"};
  string b4 {"World"};
  cout << "add(a4, b4) = " << add1(a4, b4) << endl;
  cout << "mul(a4, b4) = " << mul1(a4, b4) << endl;
  cout << "increment(a4) = " << increment1(a4) << endl;
  */

  return 0;
}

