#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numberOfPerson;
    int closeTime;

    cin >> numberOfPerson >> closeTime;

    vector<int> cashList(numberOfPerson);
    vector<int> timeList(numberOfPerson);

    for (int i = 0; i < numberOfPerson; ++i) {
        cin >> cashList[i] >> timeList[i];
        if (timeList[i] >= closeTime)
            timeList[i] = closeTime - 1;
    }

    vector<int> indices(numberOfPerson);
    for (int i = 0; i < numberOfPerson; i++)
        indices[i] = i;

    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return cashList[a] > cashList[b];
    });

    vector<int> holder(closeTime, -1); 
    int maxCash = 0;

    for (int idx : indices) {
        for (int j = timeList[idx]; j >= 0; j--) {
            if (holder[j] == -1) {
                holder[j] = cashList[idx];
                maxCash += cashList[idx];
                break;
            }
        }
    }

    cout << maxCash << endl;
    return 0;
}
