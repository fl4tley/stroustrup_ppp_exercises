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

    while(true){
        cout << "Enter a name value pair: \n";
        
        string new_name; int new_age;
        
        cin >> new_name >> new_age;
        if(new_name == "NoName" && new_age == 0) break;
        Name_value new_nv = Name_value(new_name, new_age); 
        
        for (Name_value nv : nv_list){ // could use a map for more speed I think 
            if(nv.is_equal(new_nv)) repeat = true;
        }

        nv_list.push_back(new_nv);    
    }
    for(Name_value nv : nv_list){
        cout << nv.name << " " << nv.age << endl; 
    }
    if (repeat) error("Repeated a name.");
    return 0;
}