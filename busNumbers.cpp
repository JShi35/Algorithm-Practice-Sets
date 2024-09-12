#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector> 

using namespace std;

int main(){
    int nums;
    cin>>nums;
    vector<int> holder;
    int counter=0;

    while (counter<nums)
    {
        int x;
        cin>>x;
        holder.push_back(x);
        counter++;
    }

    sort(holder.begin(), holder.end());

    int i = 0;
    int j = 0;
    string ans = "";
    //4
    //[1200 1201 1202 1203 1400 1500 1501 1502]
    while (i < holder.size()){
        int bus1 = holder[i]; //1200 1400
        j = i + 1;  //1201 1500
        while (j < holder.size() && holder[j] == bus1+(j-i)){
            j ++; //j=3 j=6
        }
        if  (holder[j] != bus1+j-i) {
            j -= 1;
        }
        if (j==i){
            ans += to_string(bus1) + " ";
        } else {
            if (j-i>=2) {
                ans += to_string(bus1) + "-" + to_string(holder[j]) + " ";
            }else{
                ans += to_string(bus1) + " " + to_string(holder[j]) + " ";
            }
        }
        i = j + 1; //4
    }
    
    cout << ans << endl;
    
    
}