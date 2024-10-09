#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int num;
    cin >> num;
    vector<int> holder(num);
    for (int i = 0; i < num; ++i) {
        cin >> holder[i];
    }
    //1 2 3 4 5: 7
    sort(holder.rbegin(), holder.rend());

    int maxMatureDay = 0;

    for (int i = 0; i < num; ++i) {
        int plantingDay = i + 1; 
        int matureDay = plantingDay + holder[i];

        if (matureDay > maxMatureDay){
            maxMatureDay = matureDay;
        }
    }

    int partyDay = maxMatureDay + 1; 
    cout << partyDay << endl;
    return 0;
}
