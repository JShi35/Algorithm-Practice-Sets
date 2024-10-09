#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int pillars;
    cin>>pillars;
    //3: 1
    //4: 2
    //5: 3
    //6: 5
    //7: 5

    if (pillars<4)
    {
        cout<<1<<endl;
    }else{
        cout<<pillars-2<<endl;
    }
    

}