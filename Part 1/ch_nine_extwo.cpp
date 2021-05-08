#include "../std_lib_facilities.h"

const string exit_reading_name = "X";
const int exit_reading_age = -1;

class NamePairs{
    public:
        NamePairs() : ages{}, names{} {} 
        void read_names();
        void read_ages();
        void print();
        void sort();

    private:
        void quicksort(int low, int high);
        int partition(int low, int high);
        vector<double> ages;
        vector<string> names;
};

void NamePairs::read_names(){
    string name;
    cout << "Please inputs space or new-line separated names. Exit name entry with the phrase '" << exit_reading_name << "'\nName: ";
    while (cin >> name){
        if (name == exit_reading_name) break;
        names.push_back(name);
        cout << "Next Name: ";
    }
}

void NamePairs::read_ages(){
    int age = 0;
    string next;
    cout << "Please input space or new-line separated ages (as integers).\n";
    for (string name : names){
        cout << name << " Age: ";
        while (!(std::cin >> age) || (!(age >= 0))) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "Invalid age, try again. " << name << " age: ";
        }
        ages.push_back(age);
    }
    if (names.size() == 0) error("no names entered yet");
}

void NamePairs::print(){
    for (int i = 0; i < names.size(); i++){
        cout << names[i] << " \t " << ages[i] << '\n';
    }
}

void NamePairs::sort(){
    quicksort(0, names.size()-1);
    cout << "---------sorted-------\n";
}

int NamePairs::partition(int l, int h){
    int pivot = ages[h];
    int i = (l - 1);
    for (int j = l; j < h; j++){
        if (ages[j] < pivot){
            i++;
            int age_temp = ages[i];
            string name_temp = names[i];
            ages[i] = ages[j];
            ages[j] = age_temp;
            names[i] = names[j];
            names[j] = name_temp;
            
        }
    }
    int age_temp = ages[h];
    string name_temp = names[h];
    ages[h] = ages[i+1];
    names[h] = names[i+1];
    ages[i+1] = age_temp;
    names[i+1] = name_temp;
    return i + 1;
}

void NamePairs::quicksort(int l, int h){
    if (l < h){
        int pi = partition(l, h);

        quicksort(l, pi - 1);
        quicksort(pi + 1, h);
    }
}


int main(){
    NamePairs np = NamePairs{};
    np.read_names();
    np.read_ages();
    np.print();
    np.sort();
    np.print();
    return EXIT_SUCCESS;
}