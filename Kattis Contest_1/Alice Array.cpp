#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<int> holder;

    while (t--)
    {
        holder.clear();
        int N, M;
        cin>>N>>M;

        for (int i = 0; i < N; i++)
        {
            int num;
            cin>>num;
            holder.push_back(num);
        }
        int maximum = 0;

        auto it = holder.begin();

        while (it != holder.end())
        {

            it = find(it, holder.end(), M);
            if (it == holder.end())
                break; 

            int center = distance(holder.begin(), it);
            int i = center - 1;
            int j = center + 1;
            int curr_sum = holder[center];


            while (i >= 0)
            {
                if (holder[i] > M)
                {
                    curr_sum += holder[i];
                    i--;
                }
                else if (holder[i] < M)
                {
                    break; 
                }
                else 
                {
                    break; 
                }
            }

        
            while (j < holder.size())
            {
                if (holder[j] > M)
                {
                    curr_sum += holder[j];
                    j++;
                }
                else if (holder[j] < M)
                {
                    break; 
                }
                else 
                {
                    break; 
                }
            }

 
            maximum = max(maximum, curr_sum);


            it++; 
        }

        cout << maximum << endl;
    }
    return 0;
}
