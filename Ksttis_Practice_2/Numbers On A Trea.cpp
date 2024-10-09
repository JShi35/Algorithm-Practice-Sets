#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    long long height;
    string moves;

    cin>>height;
    cin.ignore();
    getline(cin, moves);

    long long nodes = (1LL<<(height+1)) -1;

    long long pos = 1;

    for (char c: moves)
    {
        if(c == 'L'){
            pos = pos * 2;
        }
        if (c == 'R')
        {
            pos = pos * 2 + 1;
        }
        
    }
    
    cout<<nodes - pos+1 << endl;

    return 0;
}