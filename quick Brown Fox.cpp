#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector> 
#include <cstring>

using namespace std;

int main(){
    int num;
    cin>>num;
    cin.ignore();
    cin.clear();
    string str;
    for (size_t i = 0; i < num; i++)
    {
        getline(cin, str);
        //cout<<str<<endl;
        vector<int> holder(26, 1);

        for (size_t j = 0; j < str.size(); j++)
        {
            if (isalpha(str[j]))
            {
                holder[tolower(str[j]) - 'a'] = 0;
            }else{
                continue;
            }
            
        }

        string temp="";

        if (find(holder.begin(), holder.end(), 1) == holder.end())
        {
            cout<<"pangram"<<endl;
            continue;
        }else{
            for (size_t x = 0; x < holder.size(); x++)
        {
            if (holder[x] == 0)
            {
                continue;
            }else{
                temp.push_back(char(x+'a'));
            }
        }
        }
        
        cout<<"missing "<<temp<<endl;
        
        temp.clear();
        holder.clear();
    }
    return 0;
}