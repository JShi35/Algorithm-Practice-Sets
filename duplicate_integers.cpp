#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool hasDuplicate(vector<int>& nums) {
unordered_map<int, int> holder;

for (int i = 0; i<nums.size(); i++)
{
    if (holder.find(nums[i]) != holder.end())
    {
        cout<<"found duplicate: "<< nums[i] << endl;
        break;
        return true;
        
    }else{
        holder[nums[i]] = i;
        cout<<nums[i]<<" added"<<endl;
    }
    
}
return false;

    
}
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    bool check = hasDuplicate(nums);

    cout<<check<<endl;
    return 0;
}