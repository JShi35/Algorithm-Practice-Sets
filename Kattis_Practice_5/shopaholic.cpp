#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int num;
    long long price;
    cin >> num;
    vector<long long> holder;
    while (num--)
    {
        cin>>price;
        holder.push_back(price);
    }

    //400 100 200 350 300 250: 400
    //100 200 300 400 500 600 700: 600
    //400 100 200 350 300 250 700 600 800 900 1000 : 100 200 250 300 350 400 600 700 800 900 1000
    // 0, 3, 6, 9
    sort(holder.begin(), holder.end());

    int i = 0;
    long long discount = 0;
    if (holder.size()%3 == 0)
    {
        for (size_t i = 0; i < holder.size(); i+=3)
        {
            discount += holder[i];
        }
        
    }else{
        for (size_t j = holder.size()%3; j < holder.size(); j+=3)
        {
            discount += holder[j];
        }
        
    }
    
    cout<<discount<<endl;

    return 0;
    
}