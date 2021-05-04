#include "..\\std_lib_facilities.h"

double expression();
double term();
double primary();
// Token get_token();


class Token {
    public:
        char kind;
        double value;
        Token(char c): kind(c), value(0) {};
        Token(char c, double v): kind(c), value(v) {};

};

double term(){
    double left = primary();
    Token t = get_token();
    while (true){
        switch(t.kind){
            case '*':
                left *= primary();
                t = get_token();
                break;
            case '/': { // to initialize variables in a switch, need to put them into a code block
                double d = primary();
                if (d==0) error("division by 0 zero error");
                left /= d;
                t = get_token();
                break;
            }
            default:
                return left;
        }
    }
}

double expression(){
    double left = term();
    Token t = get_token();
    while(true){
        switch(t.kind){
            case '+':
                left += term();
                t = get_token();
                break;
            case '-':
                left -= term();
                t = get_token();
                break;
            default:
                return left;
        }
    }
}

double primary(){
    Token t = get_token();
    switch(t.kind){
        case '(': {
                double d = expression();
                t = get_token();
                if (t.kind != ')') error("no closing brackets");
                return d;
        }
        case '8':
            return t.value;
        default:
            error("expected a primary");
    }
}


int main(){
    try{
        while (cin) cout << expression() << '\n';
        keep_window_open();
    } catch(exception& e){
        cerr << e.what() << '\n';
        return 2;
    } catch(...){
        cerr << "error" << '\n';
        return 2;
    }
    return 0;
}
