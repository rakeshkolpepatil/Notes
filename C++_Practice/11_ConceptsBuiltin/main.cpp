#include <iostream>
#include <concepts>
#include <type_traits>

using namespace std;

/*
// --------------------- Standard built in concepts --------------------- 
*/
// Syntax 1 :-
template <typename T>
requires std::integral<T>
T maximum(T a, T b) {
  return a + b;
}

// Syntax 2 :-
template <std::integral T>
T add (T a, T b){ 
	return a + b;
}
/*
// syntax 3 :-
auto add (std::integral auto a, std::integral auto b){
  return a + b;
}

// syntax 4 :- 
template <typename T>
T add (T a, T b) requires std::integral<T>{
  return a + b;
}
*/

int main(){
  char a1{10};
  char b1{20};

  auto result1 = maximum(a1, b1);
  cout << "maximum('char') result : " << static_cast<int>(result1) << endl;

  int a2 {90};
  int b2 {40};
  auto result2 = maximum(a2, b2);
  cout << "maximum('int') result : " << result2 << endl;

  auto result_add = add(a1, b1);
  cout << "add result: " << static_cast<int>(result_add) << endl;

  /*
  double a3 {10};
  double b3 {20};
  auto result3 = maximum(a3, b3);            // 'double' is of not integral type, so it will give compilation error.
  cout << "result3: " << result3 << endl;
  */

  return 0;
}

