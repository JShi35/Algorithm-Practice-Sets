#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sumUp(string& nums1, string& nums2, string& result, int carry){
    
    if (nums1.size() == 0)
    {
        if(carry >0){
            result.push_back(carry + '0');
        }

        return result;
    }
    
    int digit1 = nums1[0] - '0';
    int digit2 = nums2.size()>0 ? nums2[0]-'0' : 0;
    int digit = digit1 + digit2 + carry;
    carry = digit/10;
    digit = digit%10;

    result.push_back(digit + '0');
    nums1.erase(nums1.begin());
    if (nums2.size()>0)
    {
        nums2.erase(nums2.begin());
    }
 
    return sumUp(nums1, nums2, result, carry);
}

int main(){
    string nums1, nums2, output;
    cin>>nums1;
    cin>>nums2;
    reverse(nums1.begin(), nums1.end());
    reverse(nums2.begin(), nums2.end());
    if (nums1.size()<nums2.size())
    {
        swap(nums1, nums2);
    }
    
    string results = sumUp(nums1, nums2, output, 0);
    reverse(results.begin(), results.end());
    cout<<results<<endl;
}