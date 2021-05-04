#include <iostream>
#include <stdexcept>

int main(){

    try {
        std::cout << "Start of Try-Catch\n";
        int a = 13;
        int b = 3;
        if (b == 0){
            throw std::runtime_error("Attempted to Div by 0");
        } else {throw std::exception();}
        int p = a/b;
        std::cout << "printing p: " << p << std::endl;
        p = 43;

        std::cout << "Passed the null pointer issue\n";
    } catch (std::runtime_error& e){
        std::cout << "runtirrme error: " << e.what() << '\n';
        return 2;
    } catch (std::exception& e){
        std::cout << "other error: " << e.what() << '\n'; 
        return 3;
    } catch (...) {
        std::cout << "final catch\n";
        return 4;
    }
    std::cout << "end of program\n";
    return 0;
}