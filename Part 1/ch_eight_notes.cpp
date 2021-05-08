#include "../std_lib_facilities.h"
#include "f.h" // #include occurs before the rest of the code and is part of "pre-processing"

// Most declarations are found in header files which usually define the logic behind those 
// A declaration that fully specifies the entity declared is called a definition

// int f(int); // This is a declaration, don't need to specify a variable in the function definition.

// Let's say we used to have a function that took in 3 parameters, but one of them was slowing performance and not widely used
// We can update the function declaration to specify (int x, int y, int) so that the 3 argument is no longer assigned.

extern int x; // This is a not-very-useful keywork that stats the delcaration of x is NOT a definition.

// This area is the global scope
// Use a function to make sure the value is initialized before it is called if you need to use a global constant
const vector<string>& default_name(){
    static const vector<string> dn = {"Jimothy", "Cricket"}; // Use static to initialize this just once, use const to prevent receiving code from modifying
                                                             // send the address back to reduce copying
    return dn;
}
// Gives the function a copy of the value we used in the argument
// More costly since you need to copy over all the data in the variable, and if the 
// variable is large, then could cost compute time.
int pass_by_value(int argum){
    return argum + 3;
}

// The & sign tells the function it is by reference and the const part is to stop 
// the function from modifying the contents by accident
vector<int> pass_by_const_ref(const vector<int>& argum){
    return argum;
}

// Passing in without the const will allow us to modify the contents at the address 
// specified by argum
vector<vector<int>> pass_by_ref(vector<vector<int>>& argum, int outerl, int innerl){
    // We can also use & to get a refernce to a specific location that will make referencing that memory faster and easier from a 
    // notation perspective.

    double val = argum[outerl-1][innerl -2];
    val = 10;
    for (vector<int> vec : argum){
        cout << '{';
        for (int i : vec){
            cout << i << ", ";
        }
        cout << "}\n";
    }
    int& val_add = argum[outerl-1][innerl -2]; // now we can modify the contents
    val_add = 10000;
    cout << "\nmodified\n";
    for (vector<int> vec : argum){
        cout << '{';
        for (int i : vec){
            cout << i << ", ";
        }
        cout << "}\n";
    }
    return argum;
}

int pass_int_by_ref(int& i){
    i = i + 3;
    return i;
}

int main(){

    int i = 7; // In nearly all situations, initialize your variables
    extern int x;

    vector<int> vi{1,2,3,4};
    vector<vector<int>> vvi = {{1,2,3,4}, 
                               {5,6,7,8},
                               {9,10,11,12}};
    string s; // Variables of these are initialized with a default value whenever one is not supplied
    vector<string> vs;



    // A header file is a collection of delcarations, typically defined in a file, which is then included in our own file.
    // Define your functions in some .cpp, then declare them in a .h and reference that .h in both the .cpp and the main file
    {
        // sub-scopes will re-declare variables
    }



    // Can have clases within other classes and other functions, but this probably means your code is too long
    // cout << f(i) << '\n';

    int unchanged = 10;
    cout << "unchanged: " << unchanged << "\npass_by_value(unchanged): " << pass_by_value(unchanged) << "\nunchaged: " << unchanged << endl;
    cout << "unchanged: " << unchanged << "\npass_int_by_ref(unchanged): " << pass_int_by_ref(unchanged) << "\nunchaged: " << unchanged << endl;
    pass_by_ref(vvi,3,4);

    int j = 23;
    int& r = j;

    r = 14;
    cout << j; // j has been modified to 14

    // We can use by-reference to speed up swapping and sorting algorithms

    // Explicitly truncate, otherwise avoid passing in parameters that are going to get widened

    // Sometimes we want to do a calculation at compile time as to avoid having the same calculation done over and over
    // So we use the constexpr

    constexpr double xscale = 10;
    constexpr double yscale = 0.8;

    // Some struct point with an x and y coordinate
    // constexpr function are like normal functions uneless you use it where a constant is needed
    // then it is calculated at compile time, provided its arguments are constant expressions
    // Constant expression functions cannot modify stuff outside of their own simple scope
    // constexpr Point scale(Point p) {
    //     return {xscale * p.x, 
    //             yscale * p.y};
    // };
    int sd = 1;
    cout << "new\n" << sd++ << ' ' << sd; // weird behavior, don't modify 

    // don't use global non constant variables unless you really need to
    // if we need a global constant, we face the issue of not knowing if it was initialized or not
    // before being called
    // so we need to create a const function that returns a constant place in memory of that global
    // see above


    // We can use namespaces to make sure that our function snad classes, even if they are being used by other people,
    // are still referring to our specifc classes
    // namespace Graphic_lib {
    // struct Color {...}
    // struct Shape {...}
    // ...
    // }
    // then access them like Graphic_lib::Color which is a fully qualified name
    // using std::string; -- string means refer to this
    // using namespace std; -- names from std now accessible directly

}