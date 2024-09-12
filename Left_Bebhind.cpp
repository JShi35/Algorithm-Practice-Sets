#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector> 

using namespace std;

int main(){
    int x;
    int y;
    bool flag = true;
    while (flag == true)
    {
        cin>>x>>y;

        if (x == 0 && y == 0)
        {
            //flag = false;
            break;
        }

        if (x+y == 13)
        {
            cout<<"Never speak again." << endl;
            continue;
        }
        if (x>y)
        {
            cout<<"To the convention." << endl;
        }
        if (x==y)
        {
            cout<<"Undecided."<<endl;
        }
        if (x<y)
        {
            cout<<"Left beehind." << endl;
        }
        
    }
    
    return 0;
}