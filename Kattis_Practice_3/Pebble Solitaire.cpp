#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector> 
#include <cstring>
#include <unordered_map>

using namespace std;

int pebble_counts(string& board){
    int curr = count(board.begin(), board.end(), 'o');
    int minimum = curr;

    for (size_t i = 0; i < 10; i++)
    {
        if (board[i]=='o' && board[i+1]=='o' && board[i+2]=='-')
        {
            board[i]='-';
            board[i+1]='-';
            board[i+2]='o';
            curr--;
            minimum = min(minimum, pebble_counts(board));
            board[i]='o';
            board[i+1]='o';
            board[i+2]='-';
            curr++;
        }
        if (board[i]=='-' && board[i+1]=='o' && board[i+2]=='o')
        {
            board[i]='o';
            board[i+1]='-';
            board[i+2]='-';
            curr--;
            minimum = min(minimum, pebble_counts(board));
            board[i]='-';
            board[i+1]='o';
            board[i+2]='o';
            curr++;
        }
        
    }
    return minimum;
}

int main(){
    int num;
    cin>>num;

    while (num--)
    {
        string board;
        cin>>board;

        cout<<pebble_counts(board)<<endl;
    }
    
}