#include <iostream>

using namespace std;

// 'Simple requirement' 
template <typename T>
concept TinyTypeSimple = requires (T a){
  sizeof(T) <= 4;                                   // Simple requirement: just enforces the syntax
};

// 'Nested requirement' 
template <typename T>
concept TinyTypeNested = requires (T a){
  sizeof(T) <= 4;                                   // Nested requirement: enforces the syntax
  requires sizeof(T) <= 4;                          // enforces the expression
};

// Compound 'requirement' 
template <typename T>
concept TinyTypeCompound = requires (T a, T b){
  {a + b} -> std::convertible_to<int>;              // Compound requirement: enforces that both 'a' and 'b' should be addable
};                                                  // and also the result should be convertible to 'int'

TinyTypeSimple auto TTSimple_add (TinyTypeSimple auto a, TinyTypeSimple auto b){
  return a + b;
}

TinyTypeNested auto TTNested_add (TinyTypeNested auto a, TinyTypeNested auto b){
  return a + b;
}

TinyTypeCompound auto TTComp_add (TinyTypeCompound auto a, TinyTypeCompound auto b){
  return a + b;
}

int main(){
  char ca{'a'};
  char cb{'b'};
  int ia {111};
  int ib {222};
  float fa {222.222'222f};
  float fb {111.111'111f};
  long long int lla {111'111'111'111'111'111};
  long long int llb {222'222'222'222'222'222};
  string sa {"Hello,"};
  string sb {" World"};
  string ssa {"hi"};
  string ssb {"Bye"};

  cout << endl;
  cout << " TTSimple_add(char)            = " << TTSimple_add(ca, cb) << endl;
  cout << " TTSimple_add(int)             = " << TTSimple_add(ia, ib) << endl;
  cout << " TTSimple_add(float)           = " << TTSimple_add(fa, fb) << endl;
  cout << " TTSimple_add(long long int)   = " << TTSimple_add(lla, llb) << endl;
  cout << " TTSimple_add(string)          = " << TTSimple_add(sa, sb) << endl;
  
  cout << endl;
  cout << " TTNested_add(char)            = " << TTNested_add(ca, cb) << endl;
  cout << " TTNested_add(int)             = " << TTNested_add(ia, ib) << endl;
  cout << " TTNested_add(float)           = " << TTNested_add(fa, fb) << endl;
  //cout << " TTNested_add(long long int)   = " << TTNested_add(lla, llb) << endl;       // Compilation failure as the 'long long int' size is not <= 4 bytes
  //cout << " TTNested_add(string)          = " << TTNested_add(sa, sb) << endl;         // Compilation failure as sizeof(string) is not <= 4 bytes.  
  //cout << " TTNested_add(short string)    = " << TTNested_add(ssa, ssb) << endl;       // Compilation failure as sizeof(string) is not <= 4 bytes.  
  cout << " sizeof('" << sa << "') = " << sizeof(sa) << ", sizeof('"<< sb <<"') = " << sizeof(sb) << endl;
  cout << " sizeof('" << ssa << "')     = " << sizeof(ssa) << ", sizeof('"<< ssb <<"')    = " << sizeof(ssb) << endl;

  cout << endl;
  cout << " TTComp_add(char)            = " << TTComp_add(ca, cb) << endl;               // char, int, float, double and long long int all are convertible to 'int'  
  cout << " TTComp_add(int)             = " << TTComp_add(ia, ib) << endl;               // so, all these functions will work.
  cout << " TTComp_add(float)           = " << TTComp_add(fa, fb) << endl;
  cout << " TTComp_add(long long int)   = " << TTComp_add(lla, llb) << endl;
  //cout << " TTComp_add(string)          = " << TTComp_add(sa, sb) << endl;             // Compilation failure as two strings can be added but this addition 
                                                                                         // of two strings is not convertible to int.

  return 0;
}

