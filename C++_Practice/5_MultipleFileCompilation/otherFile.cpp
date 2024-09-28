// The function min() is declared in 'compare.h' file but it is not mandatory to define it inside 'compare.cpp' file
// only. It can be defined in any of the .cpp file in the project.

int min (int a, int b) {
  if( a < b)
    return a;
  else
    return b;
}