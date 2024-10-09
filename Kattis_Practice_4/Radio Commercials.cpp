#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main (){
    int commercials;
    int cost;
    int commer;
    //vector<int> holder;
    cin>>commercials>>cost;
    vector<int> table;

    for (size_t i = 0; i < commercials; i++)
    {
        cin>>commer;
        //holder.push_back(commer);
        table.push_back(commer - cost);
    }
    vector<int> dp(commercials);
    dp[0] = table[0];
    int maximum = dp[0];
    // {-2, 15, -14, 60, -5, 1}
    for (size_t i = 1; i < table.size(); i++)
    {
        dp[i] = max(table[i], table[i]+dp[i-1]); //{-2, 15, 1, 61, 57, 58}
        maximum = max(dp[i], maximum);
    }
    


    cout<<maximum<<endl;
    return 0;
}