#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector> 

using namespace std;

int main(){
    int rows;
    cin>>rows;
    vector<int> holder(rows);
    int minimum = 90000000;
    for (size_t i = 0; i < rows; i++)
    {
        cin>>holder[i];
        minimum = min(minimum, holder[i]);
    }
    cout<<minimum+1<<endl;

    return 0;
}