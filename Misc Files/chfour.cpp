#include "..\\std_lib_facilities.h"


bool is_prime(int p, Vector<int> primes){
    for (int prime : primes){
        if (p%prime == 0) return false;   
    }
    return true;
}




int main(){


    // constexpr double pi = 3.14159265359; // will truncate to 3.14159
    // cout << pi << endl;

    // constexpr int max = 17; // can't use const for values not know at compile time
    // int val = 19;
    // max+2; // a constant expression since it is a const int, not a variable
    

    // // can use const for constants not known until compile time, such as taken from a function argument

    // // cast with (type) or type var_name {expression}
    // double var = 3/4 + 32; // truncates to 0 + 32, need to cast 3/4
    // cout << var <<endl;

    // if (true){

    // } else {

    // }
    // cout << "Enter Char: ";
    // char switchex;
    // cin >> switchex;
    // switch (switchex){
    //     case 'S': 
    //         cout << 'S' << "\n";
    //         break;
    //     case 'D':
    //         cout << 'D' << "\n";
    //         // break;   // this will flow through to the default case since there is no break statement
    //     default:
    //         cout << "Default case\n";
    //         break;

    // }

    // for longer comparisons, case is generally faster than using nested if statements
    // can use constantexpr variables in the case when, but not regular variables
    // int input = 0;
    // cout << "Enter Int: ";
    // cin >> input;
    // cout << "\ninput: " << input << endl;
    // // int y = 'y'; // can't use this in the case when need to be a const
    // constexpr auto y = 'y';
    // const char n = 'n';
    // constexpr char g = 'g';
    // switch (input){
    //     case y: case g: // can use multiple cases for one piece of to-do
    //         cout << "Printed y or g" << endl;
    //         break;
    //     case n: 
    //         cout << 'n' << endl;
    //         break;
    //     default:
    //         break;
    // }

    // int i = 0;
    // while(i<127){
    //     cout << "\ni: " << i << "\tchar: " << (char)i ;
    //     i++;
    // }
    // cout << endl;

    // vector<string> phil = {"Me","Hume","Plato"};
    // phil[1] = 4; // replaces Hume with a newline chaacter

    // for (string s : phil) cout << s << endl;


    // bool exit_char_entered = false;
    // while(!exit_char_entered){
    //     cout << "Two Space Separated Ints: ";
    //     int a,b;
    //     cin >> a >> b;
    //     if (cin.peek() == '|') {exit_char_entered = true; break;}
    //     if (a < b){
    //         cout << "the smaller value is: " << a 
    //              << "\nthe larger value is: " << b 
    //              << endl;
    //     } 
    //     else if (b < a){
    //         cout << "the smaller value is: " << b 
    //              << "\nthe larger value is: " << a 
    //              << endl;
    //     }
    //     else {cout << "the numbers are equal" << endl;}
    //   
    // }
    vector<int> primes = {2};
    for (int i = 2; i < 10000; i++){
        if (is_prime(i, primes)){
            primes.push_back(i);
            // cout << i << " PRIMME" << endl;
        } 
        // else { cout << i << " NOT PRIME" << endl;}
    }

    cout << primes[primes.size()-1];
    return 0;
}