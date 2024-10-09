#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){

    int setNums;
    int qNums;
    int caseNum = 1;

    while (cin >> setNums && setNums != 0) {

        vector<int> set;
        vector<int> query;
        //cin>>setNums;

        for (int i = 0; i < setNums; i++) {
            int num;
            cin >> num;
            set.push_back(num);
        }

        cin >> qNums;
        for (int i = 0; i < qNums; i++) {

            int num;
            cin >> num;
            query.push_back(num);
        }

        vector<int> pairSums;
        for (int i = 0; i < setNums; i++) {
            for (int j = i + 1; j < setNums; j++) {

                pairSums.push_back(set[i] + set[j]);

            }

        }

        sort(pairSums.begin(), pairSums.end());

        cout << "Case " << caseNum << ":\n";

        for (int q : query) {

            int closestSum = pairSums[0];
            int minDiff = abs(pairSums[0] - q);

            for (int sum : pairSums) {

                int diff = abs(sum - q);

                if (diff < minDiff) {
                    closestSum = sum;
                    minDiff = diff;
                }

            }

            cout << "Closest sum to " << q << " is " << closestSum << ".\n";
        }

        caseNum++;
    }

    return 0;
}
