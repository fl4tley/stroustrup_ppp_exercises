#include "../std_lib_facilities.h"


long bounded_factorial(long start, long bound){
    // if (start < 0 || bound << 0) error("Invalid inputs, less than 0");
    // if (bound > start) error("Picking too many");
    if (start > bound) return start * bounded_factorial(start - 1, bound);
    return 1;
}

long permutation(int a, int b){
    return bounded_factorial(a, (a-b));
}

long combination(int a, int b){
    long c = 0;
    c = (permutation(a,b)/(bounded_factorial(b,0)));
    return c;
}

int main(){

    cout << "\nThis program takes in two integers and calculates either a permutation or combination.\
             \nPlease input data as 'options selections X' where X is either p or c depending on the type you want.\
             \nUse 0 0 q to exit the program.\n";

    int a = 0;
    int b = 0;
    char op = ' ';

    while(true){
        while (!((cout << "Input: ") && 
              !(cin >> a >> b >> op) && 
               (op == 'p' && op == 'c' && op == 'q') &&
               (a > b) &&
               (b > 0))) cout << "Input Error Please Re-try\n";
        if (a == 0 && b == 0 && op == 'q') {
            cout << "Exit Program"; 
            break;
        }
        if (op == 'p') cout << "P(" << a << "," << b << ") = " << permutation(a,b);
        if (op == 'c') cout << "C(" << a << "," << b << ") = " << combination(a,b);
        
    }

    
    return 0;
}