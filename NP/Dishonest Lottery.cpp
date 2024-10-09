#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int t = 10 * n;
    int num;
    unordered_map<int, int> holder;

    while (t--) {
        for (size_t i = 0; i < 5; i++) {
            cin >> num;
            holder[num]++;
        }
    }

    vector<int> sus_numbers;

    for (const auto& pair: holder) {
        if (pair.second > 2 * n) {
            sus_numbers.push_back(pair.first);
        }
    }

    sort(sus_numbers.begin(), sus_numbers.end());

    if (sus_numbers.empty()) {

        cout << "-1" << endl; 
    }else{

        for (size_t i = 0; i < sus_numbers.size(); ++i) {

            if (i>0)
            {
                cout<<" ";
            }

            cout << sus_numbers[i];
        }

        cout << endl;
    }


    return 0;
}
