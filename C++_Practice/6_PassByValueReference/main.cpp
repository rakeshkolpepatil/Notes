#include <iostream>

using namespace std;

// Pass By Value
void say_age_value(int age){
  std::cout << " You are " << ++age << " years old,   &age : " << &age << endl;
}

// Pass By Pointer 
void say_age_pointer(int *age){
  std::cout << " You are " << ++(*age) << " years old,   &age : " << &age << ",     age : " << age << endl;
}

// Pass By Reference 
void say_age_ref(int& age){
  std::cout << " You are " << ++age << " years old,   &age : " << &age << ",     age : " << age << endl;
}

// Getting data out of the function using reference
void max_int_ref(int input1, int input2, int& output){
  if(input1 > input2)
    output = input1;
  else
    output = input2;
}

// Getting data out of the function using reference to strings. Input strings will of const reference type.
void max_str_ref(const std::string& input1, const std::string& input2, std::string& output){
  if(input1 > input2)
    output = input1;
  else
    output = input2;
}

// Getting data out of the function using pointer
void max_double_ptr(double input1, double input2, double* output){
  if(input1 > input2)
    *output = input1;
  else
    *output = input2;
}

// Returning data from the function - (default is return by value)
int m_sum(int a, int b) {
  int result = a + b;
  cout << " In function:  result = " << result << ", &result = " << &result << endl;
  return result;
}


int main(int argc, char* argv[]){
  // Pass By Value
  std::cout << "--- Pass By Value ---" << endl;
  int age{23};   // Local variable
  std::cout << " age (Before Pass by Value) : " << age << ",   &age : " << &age << endl;
  say_age_value(age);
  std::cout << " age (After Pass by Value) : " << age << ",   &age : " << &age << endl;

  // Pass By Pointer 
  std::cout << "\n--- Pass By Pointer ---" << endl;
  age = 23;   // Local variable
  std::cout << " age (Before Pass by Pointer) : " << age << ",   &age : " << &age << endl;
  say_age_pointer(&age);
  std::cout << " age (After Pass by Pointer) : " << age << ",   &age : " << &age << endl;


  // Pass By Reference  
  std::cout << "\n--- Pass By Reference ---" << endl;
  age = 23;   // Local variable
  std::cout << " age (Before Pass by Reference) : " << age << ",   &age : " << &age << endl;
  say_age_ref(age);
  std::cout << " age (After Pass by Reference) : " << age << ",   &age : " << &age << endl;

  // Getting data out of the function using reference
  std::cout << "\n--- Get data out of the function using reference ---" << endl; 
  int result;
  max_int_ref(23, 45, result);
  cout << " The max of (23, 45, output) = " << result << endl;

  // Getting data out of the function using reference to strings. Input strings will of const reference type.
  std::cout << "\n --- Get data out of function using string references ---" << endl;
  std::string res;
  max_str_ref("Ram", "Shyam", res);
  cout << " The max of max_str_ref('Ram', 'Shyam', res) = " << res << endl;

  // Getting data out of the function using pointer
  std::cout << "\n --- Getting data out of the function using pointer ---" << endl;
  double res1;
  max_double_ptr(11.45, 33.66, &res1);
  cout << " The max of max_double_ptr('11.45', '33.66', &res1) = " << res1 << endl;

  // Returning data from the function
  std::cout << "\n --- Return data from the function ---" << endl;
  int solution = m_sum(23, 46);
  cout << " solution = " << solution << ",  &solution = "<< &solution << endl;


  return 0;
}

