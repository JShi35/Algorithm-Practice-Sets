#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector> 

using namespace std;

int main(){

    int times;
    string bits_before;
    string bits_after;

    cin>>times;
    cin>>bits_before;
    cin>>bits_after;

    if (times%2 == 0 && bits_before == bits_after)
    {
        cout<< "Deletion succeeded" << endl;
    }

    if (times%2 == 0 && bits_before != bits_after)
    {
        cout<< "Deletion failed" << endl;
    }

    if(times%2 == 1){
        for (size_t i = 0; i < bits_before.size(); i++)
        {
            if ((bits_before[i]) == '0')
            {
                bits_before[i] = '1';
            }else{
                bits_before[i] = '0';
            }
            
        }

        if (bits_before == bits_after)
        {
            cout<<"Deletion succeeded"<<endl;

        }else{
            cout<<"Deletion failed"<<endl;
        }
        
    }
return 0;
    
}