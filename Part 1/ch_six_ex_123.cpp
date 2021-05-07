
//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
    This file started as calculator02buggy.cpp
    
    I removed the bugs and added factorial + remainder fucntionality.

*/

#include "../std_lib_facilities.h"

const char number = '8';
const char quit = 'q';
const char print = ';';
const char let = 'L';
const char name = 'a';

const string declkey = "let";


double expression();    // declaration so that primary() can call expression()
int calc_fact(int i);
double factorial();


//------------------------------------------------------------------------------

class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    string name; 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    Token(char ch, string n)
        :kind{ch}, name{n} {}
};

class Variable{
    public:
        string name;
        double value;
        Variable(string s, double v) : name(s), value(v) { }
};

vector<Variable> var_table;

double get_value(string s){
    for (Variable v : var_table)
        if (v.name == s) return v.value;
    error("get undefined variable");
}

void set_value(string s, double d){
    for (Variable v : var_table){
        if(v.name == s){
            v.value = d;
            return;
        }
    }
    error("set undefined variable");
}

bool is_declared(string var){
    for (Variable v : var_table){
        if (v.name == var) return true;
    }
    return false;
}

double define_name(string var, double val){
    if(is_declared(var)) error(var, " declared twice");
    var_table.push_back(Variable(var, val));

}
//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{   
    
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
        case print:    // for "print"
        case quit:    // for "quit"
        case '(': case ')': case '}': case '{': case '+': case '-': case '*': case '/': case '!': case '%':
            return Token(ch);        // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            // if(cin >> ch && ch == '!')
            return Token(number, val);   // let '8' represent "a number"
            break;
        }
    default:
        if(isalpha(ch)){
            cin.putback(ch);
            string s;
            cin >> s;
            if (s == declkey) return Token(let);
            return Token{name,s};
        }
        error("Bad token");
        return 0;
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------



//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
        case '(':    // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case '{': 
        {
            double d = expression();
            t = ts.get();
            if (t.kind != '}') error("expected a closing bracket }");
            return d;
        }
        case '8': {          // we use '8' to represent a number  
            return t.value;  // return the number's value
        }
        case '-':           // add unary plus and minus
            return (-1 * primary());
        case '+':
            return primary();
        default:
            error("primary expected");
            return 0;
        }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= factorial();
            t = ts.get();
            break;
        case '/':
        {
            double d = factorial();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':{ // allow modulo, but throw error if there is a narrowing conversion
            int i1 = narrow_cast<int>(left);
            int i2 = narrow_cast<int>(factorial());
            if (i2 == 0) error("%: attempted division by 0");
            left = i1%i2;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}
int calc_fact(int f){
    if (f > 0) return (f * calc_fact(f-1));
    else if (f == 0) return 1; 
    error("negative factorial");
}

double factorial(){
    double left = term();
    Token t = ts.get();

    while (true) {
        switch(t.kind){
            case '!': {
                left = calc_fact((int)left); // force conversion to int
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = factorial();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += factorial();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= factorial();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double declaration(){
    Token t = ts.get();
    if(t.kind != name) error ("name expected in definition");
    string var_name = t.name;
    
    Token t2 = ts.get();
    if (t2.kind != '=') error(" missing the = sign from the declaration of", var_name);

    double d = expression();
    define_name(var_name, d);
    return d;
}
double statement(){
    Token t = ts.get();
    switch (t.kind){
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}
int main(){
    std::cout << "Welcome to Calculator\n";

    try {
            double val = 0;
            while(cin)
            {
                Token t = ts.get();
                // while(t.kind == print) t = ts.get();
                if(t.kind == quit) break;
                if(t.kind == print){
                    cout << "= " << val << '\n';
                }
                else {ts.putback(t);}
                val = statement();
                
            }

        keep_window_open("~~");
    } catch (exception& e) {
        cerr << e.what() << endl;
        keep_window_open ("~~");
        return 1;
    } catch (...) {
        cerr << "exception \n";
        keep_window_open ("~~");
        return 2;
    }
}
//------------------------------------------------------------------------------
