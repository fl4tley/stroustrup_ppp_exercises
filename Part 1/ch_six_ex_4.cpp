// This solution error checks the input but does not error if there
// is a duplicate name value, it only prints out that there was a duplicate.

#include "../std_lib_facilities.h"

class Name_value{
    public:
        Name_value(string s, int a): name(s), age(a) {}
        bool is_equal(Name_value comp);
        string name;
        int age;
};

bool Name_value::is_equal(Name_value comp){
    if ((age == comp.age) && (name == comp.name)){
        return true;
    }
    return false; 
}

int main(){

    vector<Name_value> nv_list;
    bool repeat = false;
    string new_name; 
    int new_age;
    
    while(true){
        if (cout << "Enter a name value pair: " && !(cin >> new_name >> new_age)) error("Invalid format detected. Please use 'string int' format."); 
        if (new_name == "NoName" && new_age == 0) break;

        Name_value new_nv = Name_value(new_name, new_age); 
        
        for (Name_value nv : nv_list){ // could use a map for more speed I think 
            if(nv.is_equal(new_nv)) repeat = true;
        }

        nv_list.push_back(new_nv);    
    }

    cout << "------------------\nprinting names\n------------------\n"; 
    for(Name_value nv : nv_list){
        cout << nv.name << " " << nv.age << endl; 
    }
    if (repeat) cout << "\nWARNING: Repeated a name.";
    return 0;
}