#include "../std_lib_facilities.h"



namespace X{
    int var = 0;
    void print(){
        cout << var << endl;
    }
} 
namespace Y{
    int var = 0;
    void print(){
        cout << var << endl;
    }
}
namespace Z{
    int var = 0;
    void print(){
        cout << var << endl;
    }
}
void print(vector<int>& v){
    for (int i = 0; i < v.size(); i++){
        cout << i << ": \t" << v[i] << endl;
    }
}

void fibonacci(int x, int y, vector<int>& v, int n){
    v.push_back(x);
    v.push_back(y);
    for(int i = 0; i < n; i++){
        v.push_back(v[i] + v[i+1]);
    }
}

vector<int> new_swap(const vector<int> original){
    vector<int> reversed;
    for (int i = original.size()-1; i >= 0; i--){
        reversed.push_back(original[i]);
    }   
    return reversed;
}

void same_swap(vector<int>& swapper){
    int size = swapper.size();
    for(int i = 0; i < (size/2); i++){
        int temp = swapper[i];
        swapper[i] = swapper[size - i - 1];
        swapper[size - i - 1] = temp;
    }
}

double index_calc(const vector<double> &prices, const vector<double> &weights){
    if (prices.size() != weights.size()) error("vector size mismatch");
    double index = 0;
    for (int i = 0; i < prices.size(); i++){
        index += (prices[i]*weights[i]);
    }
    return index;
}

double maxv(vector<double> &v){
    double max = v[0];
    for(double value : v){
        if (value > max) max = value;
    }
    return max;
}
struct summary_stats{
    int max_value;
    int min_value;
    double mean;
    int median;
};




int main(){

    // namespace example from the drill
    // X::var = 7;
    // X::print();

    // using namespace Y;
    // var = 9;
    // print();
    // {
    //     using Z::var;
    //     using Z::print;
    //     var = 11;
    //     print();
    // }
    // print();
    // X::print();

    vector<int> fibs;
    fibonacci(1,2,fibs, 10);
    print(fibs);
    same_swap(fibs);
    print(fibs);

}

