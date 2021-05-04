#include "..\\std_lib_facilities.h"

// class Bad_area {};

// int area(int l, int w){
//     if (l < 0 || w < 0) throw Bad_area{}; // exits area using throw, hope that some try block will catch it
//     return l * w;
// }


// // intro to error handling and how we don't get warned about narrowing conversions
// int error_handle(){
//     try {
//         int wrap_around = area(10003, 1000000);
//         // double x0 = area(2.3, 5.3); // no warning about truncation or narrowing conversion
//         int x = -1;
//         int y = 2;
//         int z = 0;
//         int x0 = area(4,x);
//         int x1 = area(y,z);
//         cout << "area: " << x0;
//         // cout << "ratio: " << x0/x1;
//     // } catch (exception){ cout << "Caught an error\n";} // will terminate after throw, but does not run this code since we do not specify the exception type
//     } catch (Bad_area){ cout << "Caught an error\n";}  // catch a bad_area error, will run the code in the brackets

//     return 0;
// }


// // out of range exception tester with try catch
// int oor_except(){
        
//     try {
//         vector<int> v; // a vector of ints
//         for (int x; cin>>x; ) v.push_back(x); // set values
//         for (int i = 0; i<=v.size(); ++i) // print values
//             cout << "v[" << i <<"] == " 
//                  << v[i] << '\n';
//     } catch (out_of_range) {
//         cerr << "Oops! Range error\n";
//         return 1;
//     } catch (...) { // catch all other exceptions
//         cerr << "Exception: something went wrong\n";
//         return 2;
//     }

//     return 0;
// }


int main(){

    // error_handle();
    // oor_except();

    try {
        cout << "Start of Try-Catch\n";
        int* p = NULL;
        cout << "printing p: " << p << endl;
        int x0 = narrow_cast<int>(2.0); // no error
        int x1 = narrow_cast<int>(2.9); // test if a narrowing conversion will occur

        cout << "Passed the null pointer issue\n";
    } catch (runtime_error& e){
        cout << "runtime error: " << e.what() << '\n'; // cerr is less optimized and therefore less fragile
        keep_window_open();
        return 1;
    } catch (exception& e){
        cout << "other error: " << e.what() << '\n'; // cerr is less optimized and therefore less fragile
        keep_window_open();
        return 2;
    }
    // } catch (...){
    //     cout << "unknown error\n";
    //     return 2;
    // }
    cout << "end of program\n";
    keep_window_open();
    return 0;
}