#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int pebble_count(string& board, unordered_map<string, int>& memory){
    if (memory.find(board) != memory.end())
    {
        return memory[board];
    }

    int curr = count(board.begin(), board.end(), 'o');
    int minimum = curr;

    for (size_t i = 0; i < 21; i++)
    {
        if (board[i]=='o' && board[i+1]=='o' && board[i+2]=='-')
        {
            board[i]='-';
            board[i+1]='-';
            board[i+2]='o';
            curr--;
            minimum = min(minimum, pebble_count(board, memory));
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
            minimum = min(minimum, pebble_count(board, memory));
            board[i]='-';
            board[i+1]='o';
            board[i+2]='o';
            curr++;
        }
    }
    
    memory[board] = minimum;
    return minimum;
    
}


int main(){
    unordered_map<string, int> memory;
    int num;
    cin>>num;

    while (num--)
    {
        string board;
        cin>>board;
        memory.clear();
        cout<<pebble_count(board, memory) << endl;
        
    }
    
    return 0;
}