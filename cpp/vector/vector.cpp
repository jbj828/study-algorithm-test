#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    
    v.push_back(21);
    v.push_back(32);
    v.push_back(53);
    v.push_back(67);
    v.push_back(14);

    cout << "ex1-1) [v.at(i)] size_type: ";
    for(vector<int>::size_type i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;

    cout << "ex1-1) [ v[i] ] size_type: ";
    for(vector<int>::size_type i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl << endl;

    return 0;
}