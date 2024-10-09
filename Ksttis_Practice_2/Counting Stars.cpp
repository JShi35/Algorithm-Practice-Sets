#include<iostream>
#include<string>
#include<vector>

using namespace std;


void dfs(int x, int y, vector<string>& bitmap, vector<vector<bool> >& visited){
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    visited[x][y] = true;

    for (size_t dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && ny >= 0 && nx<bitmap.size() && ny<bitmap[0].size())
        {
            if (bitmap[nx][ny] == '-' && !visited[nx][ny])
            {
                dfs(nx, ny, bitmap, visited);
            }
            
        }
        
    }
    
    
}

int main(){
    int row_nums;
    int col_nums;
    int case_num = 0;
    string row;
    while (cin>>row_nums>>col_nums)
    {
        cin.ignore();

        vector<string> bitmap;

        for (size_t i = 0; i < row_nums; i++)
        {
            getline(cin, row);
            bitmap.push_back(row);
        }
        
        vector<vector<bool> > visited(row_nums, vector<bool>(col_nums, false));
        int star_nums = 0;

        for (size_t i = 0; i < bitmap.size(); i++)
        {
            for (size_t j = 0; j < bitmap[0].size(); j++)
            {
                if (bitmap[i][j] == '-' && !visited[i][j])
                {
                    star_nums++;
                    dfs(i, j, bitmap, visited);
                }
                
            }
            
        }
        case_num++;
        cout<< "Case " << case_num << ': ' << star_nums << endl;
    }
    return 0;
}