#include "../std_lib_facilities.h"
#include "f.h" // #include occurs before the rest of the code and is part of "pre-processing"

// Most declarations are found in header files which usually define the logic behind those 
// A declaration that fully specifies the entity declared is called a definition

// int f(int); // This is a declaration

extern int x; // This is a not-very-useful keywork that stats the delcaration of x is NOT a definition.

int main(){

    int i = 7; // In nearly all situations, initialize your variables
    extern int x;

    vector<int> vi{1,2,3,4};

    string s; // Variables of these are initialized with a default value whenever one is not supplied
    vector<string> vs;

    // A header file is a collection of delcarations, typically defined in a file, which is then included in our own file.
    // Define your functions in some .cpp, then declare them in a .h and reference that .h in both the .cpp and the main file
    
    cout << f(i) << '\n';

}