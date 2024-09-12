#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector> 

using namespace std;

int main(){
    while (true) {
        int num;
        int tmp;
        vector<int> permutation;
        string str;
        string output = "";
        
        cin >> num;
        if (num == 0) {
            break;
        }

       
        for (size_t i = 0; i < num; i++) {
            cin >> tmp;
            permutation.push_back(tmp);
        }
        cin.ignore();
        getline(cin, str);
    

    for (size_t i = 0; i < str.size(); i += num) {
        for (size_t j = 0; j < permutation.size(); j++) {
            
            if (i + permutation[j] - 1 < str.size()) {
                output.push_back(str[i + permutation[j] - 1]);
            } else {
                
                output.push_back(' ');
            }
        }
    }
    cout<<"'"<<output<<"'"<<endl;

    }
    return 0;
}