#include "my.h"
#include <iostream>

void swap_v(int a, int b){
    int temp;
    temp = a; a = b; b = temp;
    std::cout << "a: " << a << "\t b: " << b;
}
void swap_r(int& a,int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    std::cout << "a: " << a << "\t b: " << b;
}
// void swap_cr(const int& a, const int& b){
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }
int main(){
    // print_foo();
    // foo = 7;
    // print_foo();
    // print(99);
    int x = 7;
    int y = 9;

    // swap_r(7,9); // can't pass a rvalue to a lvalue non-constant
    swap_v(7,9);
}