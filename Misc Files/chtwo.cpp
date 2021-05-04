#include "..\\std_lib_facilities.h"

int main(){
    
    // int number_steps = 'a'; // converts from char to int, value 97
    // number_steps += 4;
    // char a = number_steps;
    // int a,b;
    // cout << "Enter Two Integers: ";
    // cin >> a >> b;
    // cout << "a/b: " << a/b << endl;
    // cout << "(double)a/b: " << (double)a/b << endl;

    // string prev = "";
    // string curr = "";
    // cout << "Enter some stuff: ";
    // while(cin >> curr){
    //     if (prev == curr) {cout << curr << endl; break;}
    //     prev = curr;
    // }

    // safe conversions are fine
    // char c = 'c';
    // int ic = c;
    // cout << "int ic: " << ic; 
    
    
    // but can also do unsafe conversion -- a narrowing conversion because placed into too small of a type
    double d = 0;
    while (cin>>d) { // repeat the statements below
        // as long as we type in numbers
        int i = d; // try to squeeze a double into an int
        char c = i; // try to squeeze an int into a char
        int i2 = c; // get the integer value of the character
        cout << "d==" << d // the original double
        << " i=="<< i // converted to int
        << " i2==" << i2 // int value of char
        << " char(" << c << ")\n"; // the char
    }

    // use {} initialization rather than = to remove accidental narrowing conversions
    // char b {1000};
    return 0;
}