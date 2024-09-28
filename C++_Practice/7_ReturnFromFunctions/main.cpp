#include <iostream>

using namespace std;

// Modern compilers optimize 'return by value' to 'return by reference' 
std::string add_strings (std::string str1, std::string str2){
  std::string result = str1 + str2;
  cout << "In function : result              = " << result << ",               &result = " << &result << endl;
  return result;
}

int main(){

  // Modern compilers optimize 'return by value' to 'return by reference' 
  std::cout << "\n ----- Modern compilers optimize 'return by value' to 'return by reference' -----" << endl;
  std::string s1 = "Harry ";
  std::string s2 = "Potter";

  std::string s3 = add_strings(s1, s2);
  cout << "Out function: add_strings(s1, s2) = " << s3 << ",                &s3 = " << &s3 << endl;

}

