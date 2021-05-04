#include "..\\std_lib_facilities.h"


double * quadratic(double a, double b, double c){


    // don't actually need to init to 0 since if there is an error, this won't be returned anyways and thus p wont update to it
    // static double r[2] = {0, 0}; // starts with some memory that might already have values in it, so need to init to 0
    
    static double r[2];

    double x0 = {0};
    double x1 = {0};

    double rt = (b*b - (4 * a * c));
    if (rt < 0) error("no real roots");

    rt = sqrt(rt) / (2*a);
    x0 = -b + rt;
    x1 = -b - rt;

    r[0] = x0; r[1] = x1;
    // cout << "r: " << r << endl;
    return r; // returns the address
}

void quadratic_test(){
    double *p;
    // cout << "p: " << p << endl;
    try{
        p = quadratic(10,130,10); // changes where p is pointing at
        cout << "root 1: " << p[0] << "\nroot 2: " << p[1] << endl;
    } catch (...) {cout << "error\n";}

    // if we hit the catch, p will not update its address and thus these values could be non-zero
    // cout << "root 1: " << (int)p[0] << "\nroot 2: " << (int)p[1] << endl; 
    // cout << "p: " << p << endl;;
    // cout << "p[0]: " << p[0];
}

// find biggest fibbonacii that fits into an int
int find_big_fib_int(){
    int fib_prior = 0;
    int fib_now = 1;
    int temp = 1;
    int count = 1;
    while (true){
        if (++count > 50) break;
        try{
            temp = fib_prior;
            fib_prior = fib_now;
            fib_now = narrow_cast<int>(fib_now + temp); // check the type

        } catch (...){
            cout << "caught error final value: ";
            return fib_now;
        }
    }

    return fib_now;
}


int main(){

    // quadratic_test();

    try
    {
        int n = 1;
        int m = 2;

        while (n<m) {
                cout << n << '\n';
                int x = n+m;
                n = m;	// drop the lowest number
                m = x;	// add a new highest number
        }

        cout << "the largest Fibonacci number that fits in an int is " << n << '\n';

        keep_window_open("~");	// For some Windows(tm) setups
    }
        catch (runtime_error e) {	// this code is to produce error messages
        cout << e.what() << '\n';
        keep_window_open("~");	// For some Windows(tm) setups
    }

    // int x = narrow_cast<int> (99000000009);
    return 0;
}