#include <iostream>

using namespace std;

int main(){
  /*
    Lambda function signature :
                    [capture list](parameters)->return type{
                      // Function body
                    }

  // Declaring a lambda function and calling it through name.
  cout << "\n--- Declaring lambda function and calling it through name ---" << endl;
  auto func = [](){
    std::cout << " This is a lambda function." << std::endl;
  };      // Defining the lambda function.
  func(); // Calling of lambda function.

  // Declare and call the lambda function directly.
  cout << "\n--- Declare and call the lambda function directly --- " << std::endl;
  [](){
    std::cout << " Hello world!" << std::endl;
  }();

  // Lambda function that takes parameters
  cout << "\n--- Lambda function that takes parameters ---" << std::endl;
  [](double a, double b){
    std::cout << " a + b : ("<< a << ", "<< b<< ") : " << (a + b) << std::endl;
  }(10.1, 23.3);

  auto func1 = [](double a, double b){
    std::cout << " a + b : ("<< a << ", "<< b<< ") : " << (a + b) << std::endl;
  };
  func1(21, 23);
  func1(22, 33);

  // Lambda function that takes arguments and returns the result
  cout << "\n--- Lambda function that takes arguments and returns the result ---" << endl;
  auto result = [](double a, double b) -> double{
    cout << " ("<< a << " + "<< b << ") = " ;
    return a + b;
  }(10.1, 23.3);
  std::cout << result << std::endl;

  // Explicitly specify the return type
  cout << "\n--- Explicitly specify return type of Lambda function ---" << endl;
  auto func3 = [](double a, double b)-> int{
    return a + b;
  };
  auto func4 = [](double a, double b)-> double{
    return a + b;
  };

  auto res4 = func3(2.3, 4.6);
  auto res5 = func4(2.4, 3.4);

  cout << " res4 = " << res4 << " sizeof(res4) = " << sizeof(res4) << endl;
  cout << " res5 = " << res5 << " sizeof(res5) = " << sizeof(res5) << endl;  

  cout << endl;
  std::cout << "Done!" << std::endl;
  */
  
  /*
  // Capture Lists
  */

  // capturing by value : what we have in the lambda function is a copy.
    cout << "\n--- Capture Lists :- capturing by value ---" << std::endl;
    int c{54};
    auto func1 = [c](){     // The value of variable 'c' at previous line of code will be passed by value to capture list.
      std::cout << "First lambda func: c = "<< c << endl;
    };
    for(size_t i = 0; i < 5; i++){
      std::cout << "Outer value: c = "<< c << endl;
      func1();
      ++c;
    }
    auto func11 = [c](){    // The value of variable 'c' at previous line of code will be passed by value to capture list.
      std::cout << "func11 lambda func: c = "<< c << endl;
    };
    func11();

	// capturing by reference : what we have in the lambda function is actual reference.
    cout << "\n--- Capture Lists :- capturing by reference ---" << std::endl;
    int d{54};
    auto func2 = [&d](){    // reference is passed in capture list, so whenever 'd' is modified it is visible in lambda function.
      std::cout << "Inner value: d = "<< d << endl;
    };
    for(size_t i = 0; i < 5; i++){
      std::cout << "Outer value: d = "<< d << endl;
      func2();
      ++d;
    }
    auto func22 = [&d](){    // reference is passed in capture list, so whenever 'd' is modified it is visible in lambda function.
      std::cout << "fun22 lambda func: d = "<< d << endl;
    };	
    func22();

  // capture all by value
    cout << "\n--- Capture Lists :- capturing all by value ---" << std::endl;
    int e{54};
    double pi{3.14};
    auto func3 = [=](){     // The '=' sign inside capture list means that entire context is available inside lambda function by value.
                            // The values are as per the variable values at previous line.
      std::cout << "func3 lambda func: e = "<< e << endl;
      std::cout << "func3 lambda func: pi = "<< pi << endl;
    };
    for(size_t i = 0; i < 5; i++){
      std::cout << "Outer value: e = "<< e << endl;
      func3();
      ++e;
    }

  // Capture all by Reference :- capture entire context from outside of lambda function to its inside by reference
    cout << "\n--- Capture Lists :- capturing all  by reference ---" << std::endl;
    int f{54};
    double g{3.1415};
    auto func4 = [&](){     // The '&' sign inside capture list means that entire context is available inside lambda function by reference.
      std::cout << "func4 lambda func: f = "<< f << endl;
      std::cout << "func4 lambda func: g = "<< g << endl;
    };
    for(size_t i = 0; i < 5; i++){
      std::cout << "Outer value: f = "<< f << endl;
      func4();
      ++f;
      g*=1.2;
    }

  return 0;
}

