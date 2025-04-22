#include <iostream>
#include <iomanip>   // for manipulators like setw, setprecision
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

int main(){
  unordered_map<int, int> ump;
    int count = 0;
    unsigned int A = 0;
    unsigned int t;
    t = A & (A-1);
    cout << "A = " << A << ", (A-1) = " << A-1;
    while(t){
        count++;
        t = A & (A-1);
    }
    cout << "\n count = " << count << endl;
    cout << "HI" << endl;
}