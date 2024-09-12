#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> holder;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int compliment = target-nums[i];
            //{1,2,3,4} 7;
            if (holder.find(compliment) != holder.end())
            {
                result.push_back(holder[compliment]);
                cout<<holder[compliment]<<" added"<<endl;
                result.push_back(i);
                cout<<i<<" added"<< endl;
                return result;
            }else{
                holder[nums[i]] = i;
            }
            
        }
        
}
int main(){
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(-2);
    nums.push_back(-3);
    nums.push_back(-4);
    nums.push_back(-5);
    int target = -8;

    vector<int> result = twoSum(nums, target);

    cout << result[0] << endl;
    cout << result[1] << endl;
}