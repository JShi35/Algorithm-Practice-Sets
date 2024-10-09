#include <iostream>
#include <vector>

using namespace std;

int main(){
    int num;
    int difficulty;

    vector<int> holder;

    int excluded = 0;

    cin>>num;
    
    while (num--)
    {
        cin>>difficulty;
        holder.push_back(difficulty);
    }

    for (size_t i = 0; i < holder.size(); i++)
    {
        if (holder[i]%2 != 0)
        {
            excluded++;
        }
        
    }

    cout<<excluded<<endl;

    return 0;

}